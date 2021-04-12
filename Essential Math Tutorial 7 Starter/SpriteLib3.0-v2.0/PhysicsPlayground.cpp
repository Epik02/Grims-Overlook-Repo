#include "PhysicsPlayground.h"
#include "Utilities.h"
#include "Camera.h"
#include "PopUpTrigger.h"
#include "windows.h"
#include "winuser.h"
#include <ctime>
#include "Tone Fire/ToneFire.h"
#include <random>
using namespace std;
//int playerid;
//int playerid;
int flashlightid;
int flashlightoff;
int cameraid;
int cursorid;
int playerid;
int oops, oops2, oops3, oops4, oops5, oops6;
int bignote1, bignote2, bignote3, bignote4, bignote5, bignote6, bignote7;
bool pgangleup;
bool pgangledown;
int flashlightclick = 0;
int fbfull;
int fbhalf;
int fbempty;
int mkid;
bool flon;
auto batterystart = 0;
auto batteryend = 0;
float timer1 = 0;
float timer2 = 0;
float timer3 = 0;
bool usingbattery = true;
int battery1;
int testme;
HWND MyText;
static int slideint = 0;
int batterys = 0;
int batterytrigger;
bool keypad = false;
string keypadnum;
int kpg, kpr;
bool kpl = false;
int bigkeypad1;
int gsid;
int gstrigger;
bool keyappear = false;
int keycar;
int char1, char2, char3, char4;
int door;
int cartCoords[34][2];
int maintitle;
bool titleappear = true;
bool openmech = false;
bool opengro = false;
int tut;
bool tutorial1 = true;
//float energy;


PhysicsPlayground::PhysicsPlayground(std::string name)
	: Scene(name)
{
	//No gravity this is a top down scene
	m_gravity = b2Vec2(0.f, 0.f);
	m_physicsWorld->SetGravity(m_gravity);

	m_physicsWorld->SetContactListener(&listener);
}


int assetMaker(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy, int posz) {
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		auto entity = ECS::CreateEntity();
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = asset;
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, sizex, sizey);
		ECS::GetComponent<Sprite>(entity).SetTransparency(1.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, posz));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(posx), float32(posy));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);
		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, GROUND, PLAYER | ENEMY | OBJECTS | HEXAGON);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(0.f);

		return entity;
	}
}

int invisiWall(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy) {
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		auto entity = ECS::CreateEntity();
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = asset;
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, sizex, sizey);
		ECS::GetComponent<Sprite>(entity).SetTransparency(0.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 3.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(posx), float32(posy));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);
		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, GROUND, PLAYER | ENEMY | OBJECTS | HEXAGON);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(0.f);

		return entity;
	}
}

int assetMakerturn(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy) {
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		auto entity = ECS::CreateEntity();
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = asset;
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, sizex, sizey);
		ECS::GetComponent<Sprite>(entity).SetTransparency(1.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 3.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(posx), float32(posy));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);
		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, GROUND, PLAYER | ENEMY | OBJECTS | HEXAGON);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(90.f);

		return entity;
	}
}

int assetMakerbg(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy) {
	{
		auto entity = ECS::CreateEntity();
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = asset;
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, sizex, sizey);
		ECS::GetComponent<Sprite>(entity).SetTransparency(1.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 1.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(posx), float32(posy));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);
		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(0.f);

		return entity;
	}
}



int objectMaker(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy, int rot) {
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		auto entity = ECS::CreateEntity();
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = asset;
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, sizex, sizey);
		ECS::GetComponent<Sprite>(entity).SetTransparency(1.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 5.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(posx), float32(posy));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);
		//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, GROUND, ENEMY | OBJECTS | HEXAGON);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(rot);

		return entity;
	}
}
int pushObject(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy, int id)
{
	
	auto entity = ECS::CreateEntity();

	//Add components
	ECS::AttachComponent<Sprite>(entity);
	ECS::AttachComponent<Transform>(entity);
	ECS::AttachComponent<PhysicsBody>(entity);

	//Sets up the components
	std::string fileName = asset;
	ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, sizex, sizey);
	ECS::GetComponent<Sprite>(entity).SetTransparency(1.f);
	ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 3.f));

	auto& tempSpr = ECS::GetComponent<Sprite>(entity);
	auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

	float shrinkX = 0.f;
	float shrinkY = 0.f;

	b2Body* tempBody;
	b2BodyDef tempDef;
	tempDef.type = b2_dynamicBody;
	tempDef.position.Set(float32(posx), float32(posy));

	tempBody = m_physicsWorld->CreateBody(&tempDef);

	//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);
	tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, GROUND | PLAYER | ENEMY | OBJECTS | HEXAGON);
	cartCoords[id][0] = posx;
	cartCoords[id][1] = posy;
	id++;
	tempBody->SetUserData((void*)id);

	tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
	tempPhsBody.SetFixedRotation(true);
	tempPhsBody.SetRotationAngleDeg(0.f);

	return entity;
}
int HUD(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy, int transparency) {
	{
		auto entity = ECS::CreateEntity();
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = asset;
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, sizex, sizey);
		ECS::GetComponent<Sprite>(entity).SetTransparency(1.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 3.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(transparency);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 2.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(posx), float32(posy));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);
		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, PLAYER | ENEMY | GROUND | OBJECTS | HEXAGON);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(true);
		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(0.f);

		return entity;
	}
}

void trigger(b2World* m_physicsWorld, float platformx, float platformy, int platformw, int platformh, float triggerx, float triggery, int& puzzleWall) {
	{
		//wall
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, platformw, platformh);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -20.f, 2.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(platformx), float32(platformy));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new DestroyTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(triggerx), float32(triggery));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}
}



void PhysicsPlayground::InitScene(float windowWidth, float windowHeight)
{

	//Dynamically allocates the register
	m_sceneReg = new entt::registry;

	//Attach the register
	ECS::AttachRegister(m_sceneReg);

	//Sets up aspect ratio for the camera
	float aspectRatio = windowWidth / windowHeight;

	EffectManager::CreateEffect(EffectType::Vignette, windowWidth, windowHeight); // filters
	EffectManager::CreateEffect(EffectType::Sepia, windowWidth, windowHeight);


	//Setup MainCamera Entity
	{
		/*Scene::CreateCamera(m_sceneReg, vec4(-75.f, 75.f, -75.f, 75.f), -100.f, 100.f, windowWidth, windowHeight, true, true);*/

		//Creates Camera entity
		auto entity = ECS::CreateEntity();
		cameraid = entity;
		ECS::SetIsMainCamera(entity, true);

		//Creates new orthographic camera
		ECS::AttachComponent<Camera>(entity);
		ECS::AttachComponent<HorizontalScroll>(entity);
		ECS::AttachComponent<VerticalScroll>(entity);

		vec4 temp = vec4(-120.f, 120.f, -120.f, 120.f); //fov
		ECS::GetComponent<Camera>(entity).SetOrthoSize(temp);
		ECS::GetComponent<Camera>(entity).SetWindowSize(vec2(float(windowWidth), float(windowHeight)));
		ECS::GetComponent<Camera>(entity).Orthographic(aspectRatio, temp.x, temp.y, temp.z, temp.w, -100.f, 100.f);

		//Attaches the camera to vert and horiz scrolls
		ECS::GetComponent<HorizontalScroll>(entity).SetCam(&ECS::GetComponent<Camera>(entity));
		ECS::GetComponent<VerticalScroll>(entity).SetCam(&ECS::GetComponent<Camera>(entity));
	}

	//Link entity
	{
		/*Scene::CreatePhysicsSprite(m_sceneReg, "LinkStandby", 80, 60, 1.f, vec3(0.f, 30.f, 2.f), b2_dynamicBody, 0.f, 0.f, true, true)*/

		auto entity = ECS::CreateEntity();
		ECS::SetIsMainPlayer(entity, true);

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<CanJump>(entity);
		ECS::AttachComponent<Player>(entity);
		ECS::AttachComponent<AnimationController>(entity);


		//Sets up the components
		std::string fileName = "spritesheets/anim.png";
		std::string animations = "ANIM.json";
		ECS::GetComponent<Player>(entity).InitPlayer(fileName, animations, 40, 30, &ECS::GetComponent<Sprite>(entity), &ECS::GetComponent<AnimationController>(entity),
			&ECS::GetComponent<Transform>(entity));
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 30.f, 2.f));
		
		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_dynamicBody;
		tempDef.position.Set(float32(210.f), float32(-5.f));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, PLAYER, ENEMY | OBJECTS | PICKUP | TRIGGER, 0.5f, 3.f);
		tempPhsBody = PhysicsBody(entity, tempBody, float((tempSpr.GetHeight() - shrinkY) / 2.f), vec2(0.f, 0.f), false, PLAYER, ENVIRONMENT | ENEMY | OBJECTS | PICKUP | TRIGGER | HEXAGON, 5.f, 3.f);
		//std::vector<b2Vec2> points = {b2Vec2(-tempSpr.GetWidth()/2.f, -tempSpr.GetHeight()/2.f), b2Vec2(tempSpr.GetWidth()/2.f, -tempSpr.GetHeight()/2.f), b2Vec2(0.f, tempSpr.GetHeight()/2.f)};
		//tempPhsBody = PhysicsBody(entity, BodyType::TRIANGLE, tempBody, points, vec2(0.f, 0.f), false, PLAYER, ENEMY | OBJECTS | PICKUP | TRIGGER, 0.5f, 3.f);

		tempPhsBody.SetRotationAngleDeg(90.f);
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetGravityScale(1.f);

		playerid = entity;
	}


	//Flashlight
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		auto entity = ECS::CreateEntity();
		ECS::SetFlashlight(entity, true);
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = "Flashlightdim.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 1030, 576);
		ECS::GetComponent<Sprite>(entity).SetTransparency(0.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 49.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_dynamicBody;
		tempDef.position.Set(float32(playerx), float32(playery));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(0.f);

		flashlightid = entity;
	}

	//Flashlight off
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		auto entity = ECS::CreateEntity();
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = "Flashlightoff.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 858, 480);
		ECS::GetComponent<Sprite>(entity).SetTransparency(0.85f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 49.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_dynamicBody;
		tempDef.position.Set(float32(playerx), float32(playery));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(0.f);

		flashlightoff = entity;
	}

	//cursor
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		auto entity = ECS::CreateEntity();

		POINT point;
		GetCursorPos(&point); //gets coordinates of cursor

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = "cursor.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 20, 10);
		ECS::GetComponent<Sprite>(entity).SetTransparency(1.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(point.x, point.y, 100.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(point.x), float32(point.y));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(0.f);

		cursorid = entity;
	}

	//title screen
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		auto entity = ECS::CreateEntity();
		ECS::SetFlashlight(entity, true);
		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up the components
		std::string fileName = "title.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 350, 300);
		ECS::GetComponent<Sprite>(entity).SetTransparency(0.85f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(45.f, -8.f, 49.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_dynamicBody;
		tempDef.position.Set(float32(playerx), float32(playery));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, OBJECTS, ENVIRONMENT, 0.3f);

		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetFixedRotation(false);
		tempPhsBody.SetRotationAngleDeg(0.f);

		maintitle = entity;
	}

	//BG
	{
		//Creates entity
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "green.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 2000, 2000);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 0.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(30.f), float32(-10.f));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, GROUND, ENEMY | ENEMY | OBJECTS | HEXAGON);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));

	}



	//LibraryBG
	{
		//Creates entity
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "librarybg.jpg";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 700, 700);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 1.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(2100.f), float32(2335.f));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, GROUND, ENEMY | ENEMY | OBJECTS | HEXAGON);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));

	}

	//MechanicsBG
	{
		//Creates entity
		auto entity = ECS::CreateEntity();

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "mechanicsbg.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 585, 451);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 1.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-1000.f), float32(-2335.f));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, GROUND, ENEMY | ENEMY | OBJECTS | HEXAGON);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));

	}

	{
		//big note 1
		//Creates entity
		auto entity = ECS::CreateEntity();
		bignote1 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "tnote.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(300), float32(-40));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//note
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall1 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "tnote.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 10, 10);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(300), float32(-40));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new PopUpTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(bignote1);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(300), float32(-30)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		//big note 2
		//Creates entity
		auto entity = ECS::CreateEntity();
		bignote2 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note3.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(100), float32(100));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//note
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall5 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 10, 10);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(2360), float32(2200));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops4 = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new PopUpTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall5);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(bignote2);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(2360), float32(2180)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		//big note 3
		//Creates entity
		auto entity = ECS::CreateEntity();
		bignote3 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note2.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(100), float32(100));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//note
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall6 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 10, 10);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(1930), float32(2570));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops5 = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new PopUpTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall6);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(bignote3);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(1930), float32(2570)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		//big note 4
		//Creates entity
		auto entity = ECS::CreateEntity();
		bignote4 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note7.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(100), float32(100));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//note
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall7 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note7.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 10, 10);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-750), float32(-2160));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops6 = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new PopUpTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall7);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(bignote4);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-750), float32(-2180)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		//big note 5
		//Creates entity
		auto entity = ECS::CreateEntity();
		bignote5 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "fusebox.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-800), float32(-2160));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//note
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall9 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "fusebox.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 12, 8);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-800), float32(-2160));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops4 = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new PopUpTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall9);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(bignote5);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-800), float32(-2180)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		//big note 6
		//Creates entity
		auto entity = ECS::CreateEntity();
		bignote6 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note5.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(100), float32(100));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//note
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall10 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note5.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 12, 8);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(1315), float32(-1070));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops4 = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new PopUpTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall10);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(bignote6);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(1310), float32(-1080)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		//big note 7
		//Creates entity
		auto entity = ECS::CreateEntity();
		bignote7 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 100, 100);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(400), float32(-35));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//note
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall11 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 10, 10);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(400), float32(-30));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new PopUpTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall11);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(bignote7);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(400), float32(-40)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		//big keypad
		//Creates entity
		auto entity = ECS::CreateEntity();
		bignote1 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "keypad.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 153, 102);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(102), float32(153));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//invisible
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall1 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "note.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 10, 10);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 0.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(100), float32(100));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger keypad

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops3 = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new PopUpTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(bignote1);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-970), float32(-2150)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		// mechanics key
		//Creates entity
		auto entity = ECS::CreateEntity();
		mkid = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "mk.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 40, 20);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(2040), float32(2326));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//mkhud
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall2 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "mk.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 40, 20);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(2040), float32(2326));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		oops2 = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new AppearTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall2);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(mkid);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(2030), float32(2326)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		// grocery store key
		//Creates entity
		auto entity = ECS::CreateEntity();
		gsid = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "gs.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 40, 20);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(0);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(2040), float32(2326));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//gshud
		//Creates entity
		auto entity = ECS::CreateEntity();
		puzzleWall4 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "gs.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 40, 20);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 120.f, 48.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-1210), float32(-2205));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);


	}

	{
		//Setup trigger gsk

		//Creates entity
		auto entity = ECS::CreateEntity();
		gstrigger = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new AppearTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall4);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(gsid);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(-1210), float32(-2220)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	{
		//battery
		//Creates entity
		auto entity = ECS::CreateEntity();
		battery1 = entity;

		//Add components
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		//Sets up components
		std::string fileName = "Battery.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 40, 20);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(650.f, 100.f, 100.f));
		ECS::GetComponent<Sprite>(entity).SetTransparency(1);

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(400), float32(-15));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, ENEMY | ENEMY);
		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
		tempPhsBody.SetRotationAngleDeg(90.f);
	}

	{
		//Setup battery trigger

		//Creates entity
		auto entity = ECS::CreateEntity();
		batterytrigger = entity;

		//Add components
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);
		ECS::AttachComponent<Trigger*>(entity);

		//Sets up components
		std::string fileName = "boxSprite.jpg";
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
		ECS::GetComponent<Trigger*>(entity) = new TrueFalseTrigger();
		ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall3);
		ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(battery1);
		//ECS::GetComponent<Trigger*>(entity)->m_physicsWorld = m_physicsWorld;
		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(playerid);


		bool tester = false;

		//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);

		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;
		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_staticBody;
		tempDef.position.Set(float32(400), float32(-15)); //coords

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	}

	int truck = assetMaker(m_physicsWorld, "Truck.png", 75, 125, 200, 0, 3);
	int repairshop = assetMaker(m_physicsWorld, "Repairshop.png", 100, 100, 700, 100, 3);
	int library = assetMaker(m_physicsWorld, "library.png", 100, 100, 300, 100, 3);
	int SuperMarket = assetMaker(m_physicsWorld, "Super Market.png", 200, 100, 500, 100, 3);

	int road00 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, -200, 0);
	int road0 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 0, 0);
	int road = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 200, 0);
	int road2 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 400, 0);
	int road3 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 600, 0);
	int road4 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 800, 0);
	int road5 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 1000, 0);

	//invisible road border
	{
		int left1 = invisiWall(m_physicsWorld, "Yellow.png", 20, 600, -200, 0);
		int right1 = invisiWall(m_physicsWorld, "Yellow.png", 20, 600, 800, 0);
		int top1 = invisiWall(m_physicsWorld, "Yellow.png", 1200, 20, 400, 200);
		int bottom1 = invisiWall(m_physicsWorld, "Yellow.png", 1200, 20, 400, -200);
	}

	//inside library
	assetMaker(m_physicsWorld, "darkbrown.jpg", 400, 26, 1943, 2085, 3);
	assetMaker(m_physicsWorld, "darkbrown.jpg", 250, 26, 2326, 2085, 3);//bottom wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 400, 100, 1943, 2035, 3);
	assetMaker(m_physicsWorld, "darkbrown.jpg", 250, 100, 2326, 2035, 3); //bottom wall fill in
	assetMaker(m_physicsWorld, "darkbrown.jpg", 70, 20, 2170, 1995, 3); //door

	assetMaker(m_physicsWorld, "darkbrown.jpg", 20, 610, 1745, 2385, 3); //left wall

	assetMaker(m_physicsWorld, "darkbrown.jpg", 710, 20, 2103, 2680, 3); //top wall

	assetMaker(m_physicsWorld, "darkbrown.jpg", 20, 630, 2450, 2355, 3); //right wall

	//library maze 	
	assetMaker(m_physicsWorld, "darkbrown.jpg", 110, 25, 1808, 2359, 3); //little wall left
	assetMaker(m_physicsWorld, "darkbrown.jpg", 300, 26, 1990, 2278, 3); //bottom wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 210, 1941, 2373, 3); //connected to bottom wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 120, 25, 2065, 2374, 3); //little wall right
	assetMaker(m_physicsWorld, "darkbrown.jpg", 20, 420, 2130, 2480, 3); //right wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 170, 25, 1976, 2470, 3); //middle
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 205, 1810, 2510, 3); //leftmost wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 262, 26, 1930, 2622, 3); //top wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 106, 1884, 2510, 3); //connected to middle (little)
	assetMaker(m_physicsWorld, "darkbrown.jpg", 97, 26, 1926, 2550, 3); //backwards L bottom
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 100, 1965, 2588, 3); //backwards L top
	assetMaker(m_physicsWorld, "darkbrown.jpg", 90, 26, 2080, 2543, 3); //little wall top right

	//library room
	assetMaker(m_physicsWorld, "darkbrown.jpg", 230, 26, 2336, 2283, 3); //bottom
	assetMaker(m_physicsWorld, "darkbrown.jpg", 20, 330, 2219, 2435, 3); //top


	//office maze
	assetMakerturn(m_physicsWorld, "bookshelf.png", 40, 80, 2270, 2580);
	assetMakerturn(m_physicsWorld, "bookshelf.png", 40, 80, 2350, 2580);
	assetMakerturn(m_physicsWorld, "bookshelf.png", 40, 80, 2310, 2500);
	assetMaker(m_physicsWorld, "bookshelf.png", 40, 80, 2370, 2480, 3);
	assetMakerturn(m_physicsWorld, "bookshelf.png", 40, 80, 2350, 2420);
	assetMaker(m_physicsWorld, "bookshelf.png", 30, 60, 2250, 2410, 3);
	assetMaker(m_physicsWorld, "bookshelf.png", 40, 80, 2370, 2351, 3);

	//props
	//Assorted Tools.png
	//Plant.png
	//Pile of Books.png
	objectMaker(m_physicsWorld, "Assorted Tools.png", 20, 20, 2280, 2580, 0);
	objectMaker(m_physicsWorld, "Pile of Books.png", 20, 20, 2310, 2500, 0);
	objectMaker(m_physicsWorld, "Pile of Books.png", 20, 20, 2310, 2330, 0);
	assetMaker(m_physicsWorld, "Plant.png", 40, 40, 2416, 2331, 3);
	objectMaker(m_physicsWorld, "Plant.png", 10, 10, 2250, 2435, 0);
	objectMaker(m_physicsWorld, "Plant.png", 10, 10, 2250, 2390, 0);
	objectMaker(m_physicsWorld, "Pile of Books.png", 15, 15, 2330, 2330, 45);
	//objectMaker(m_physicsWorld, "Assorted Tools.png", 15, 15, );

	assetMaker(m_physicsWorld, "table.png", 100, 67, 2290, 2330, 3); //table


	//outside library background
	assetMakerbg(m_physicsWorld, "black.png", 1500, 1500, 2000, 2650);

	//mechanics
	assetMaker(m_physicsWorld, "darkbrown.jpg", 460, 26, -928, -2550, 3); //bottom
	assetMaker(m_physicsWorld, "darkbrown.jpg", 40, 26, -1270, -2550, 3); //bottom left
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 440, -710, -2340, 3); //right
	assetMaker(m_physicsWorld, "darkbrown.jpg", 600, 26, -995, -2110, 3); //top
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 440, -1280, -2340, 3); //left

	assetMaker(m_physicsWorld, "darkbrown.jpg", 135, 20, -1212, -2280, 3); //room bottom
	assetMaker(m_physicsWorld, "darkbrown.jpg", 25, 65, -1150, -2255, 3); //left of door
	assetMaker(m_physicsWorld, "darkbrown.jpg", 25, 65, -1150, -2140, 3); //right of door
	door = assetMaker(m_physicsWorld, "green.png", 25, 85, -1150, -2205, 3);

	//Grocery
	{
		assetMakerbg(m_physicsWorld, "Grocery Store Asset.png", 720, 580, 1500, -1000);

		//furthest boundaries of Grocery Walls
		//bottom
		invisiWall(m_physicsWorld, "Yellow.png", 720, 15, 1500, -1282.5);
		//top left
		invisiWall(m_physicsWorld, "Yellow.png", 140, 15, 1215, -715);
		//top right
		invisiWall(m_physicsWorld, "Yellow.png", 570, 15, 1570, -777.5);
		//left side
		invisiWall(m_physicsWorld, "Yellow.png", 15, 580, 1147.5, -1000);
		//right side
		invisiWall(m_physicsWorld, "Yellow.png", 15, 500, 1852.5, -1020);
		//right topleft
		invisiWall(m_physicsWorld, "Yellow.png", 15, 70, 1285, -750);

		//main hall
		invisiWall(m_physicsWorld, "Yellow.png", 15, 180, 1285, -1190);
		invisiWall(m_physicsWorld, "Yellow.png", 15, 210, 1285.5, -950);
		invisiWall(m_physicsWorld, "Yellow.png", 15, 60, 1345, -1070);


		invisiWall(m_physicsWorld, "Yellow.png", 220, 15, 1405, -1107.5);
		invisiWall(m_physicsWorld, "Yellow.png", 210, 15, 1400, -1047.5);

		//2nd room right side top
		invisiWall(m_physicsWorld, "Yellow.png", 15, 165, 1470, -862.5);
		//2nd room right side bottom
		invisiWall(m_physicsWorld, "Yellow.png", 15, 60, 1470, -1020);
		//2nd room alcove bottom
		invisiWall(m_physicsWorld, "Yellow.png", 105, 15, 1517.5, -997.5);
		//2nd room alcove right
		invisiWall(m_physicsWorld, "Yellow.png", 15, 285, 1575, -1082.5);
		//2nd room box wall
		invisiWall(m_physicsWorld, "Yellow.png", 45, 50, 1307.5, -869.5);


		//3rd room bottom side
		invisiWall(m_physicsWorld, "Yellow.png", 270, 15, 1663, -939.5);

		//4th room
		//right wall
		invisiWall(m_physicsWorld, "Yellow.png", 15, 250, 1792.5, -1057.5);
		//corner wall
		invisiWall(m_physicsWorld, "Yellow.png", 50, 40, 1830, -1258);
		//Mid line p1
		invisiWall(m_physicsWorld, "Yellow.png", 40, 15, 1672.5, -1093);
		//Mid line p2
		invisiWall(m_physicsWorld, "Yellow.png", 50.5, 15, 1597.5, -1093);
		//Mid line p3
		invisiWall(m_physicsWorld, "Yellow.png", 60, 15, 1763, -1093);
		//Mid line vertical 1
		invisiWall(m_physicsWorld, "Yellow.png", 15, 50, 1740, -1115);
		//Mid line vertical 2
		invisiWall(m_physicsWorld, "Yellow.png", 15, 50, 1685, -1115);

		//5th room
		invisiWall(m_physicsWorld, "Yellow.png", 80, 15, 1542.5, -1222);
		invisiWall(m_physicsWorld, "Yellow.png", 15, 127.5, 1509.5, -1166.25);
	}

	//boxes, currently placeholder for coordinates
	{//p1 lower hall
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1265, -1050, 0);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1225, -1050, 1);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1185, -1050, 2);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1224, -970, 3);

		//p2 higher hall
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1177.5, -825, 4);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1217.5, -825, 5);
		pushObject(m_physicsWorld, "Cart.png", 40, 80, 1257.5, -845, 6);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1217.5, -745, 7);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1257.5, -745, 8);

		//p3 diagonal crossing
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1390, -817.5, 9);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1430, -867.5, 10);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1350, -867.5, 11);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1350, -967.5, 12);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1430, -967.5, 13);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1390, -917.5, 14);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1390, -1017.5, 15);

		//p4 back hallway
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1761.5, -817.5, 16);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1721.5, -857.5, 17);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1721.5, -897.5, 18);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1701.5, -897.5, 19);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1641.5, -857.5, 20);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1601.5, -817.5, 21);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1601.5, -897.5, 22);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1561.5, -857.5, 23);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1521.5, -857.5, 24);

		//p5 battery or win trap
		//top part
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1752.5, -1065.5, 25);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1712.5, -1022.5, 26);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1672.5, -1022.5, 27);
		//Needs new asset
		pushObject(m_physicsWorld, "Cart.png", 20, 135, 1642.5, -1072.6, 28);
		//key stand in
		//pushObject(m_physicsWorld, "Cart.png", 40, 40, 1602.5, -1065.5);

		//bottom part
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1712, -1180, 29);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1712, -1220, 30);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1672, -1220, 31);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1592, -1180, 32);
		pushObject(m_physicsWorld, "Cart.png", 40, 40, 1642.5, -1260, 33);

		//parents
		assetMaker(m_physicsWorld, "mom.png", 50, 50, 1342, -1155, 3);
		assetMaker(m_physicsWorld, "dad.png", 50, 50, 1342, -1185, 3);
	}

	//tutorial
	tut = assetMaker(m_physicsWorld, "gt.png", 100, 50, 200, 0, 3);

	////cars
	keycar = assetMaker(m_physicsWorld, "car.png", 80, 160, -1025, -2380, 3); //left of door
	assetMaker(m_physicsWorld, "car.png", 80, 160, -830, -2380, 3); //right of door

	////HUD
	fbfull = HUD(m_physicsWorld, "flashbarfull.png", 140, 100, 0, 0, 51);
	fbhalf = HUD(m_physicsWorld, "flashbarhalf.png", 140, 100, 0, 0, 51);
	fbempty = HUD(m_physicsWorld, "flashbarempty.png", 140, 100, 0, 0, 51);

	//Keypad Indicators
	kpg = assetMaker(m_physicsWorld, "keypadr.png", 102, 153, 0, 0, 25);
	kpr = assetMaker(m_physicsWorld, "keypadg.png", 102, 153, 0, 0, 25);
	ECS::GetComponent<Sprite>(kpg).SetTransparency(0.0f);
	ECS::GetComponent<Sprite>(kpr).SetTransparency(0.0f);

	//entering characters on keypad
	char1 = assetMaker(m_physicsWorld, "charenter.png", 10, 10, 0, 0, 25);
	char2 = assetMaker(m_physicsWorld, "charenter.png", 10, 10, 0, 0, 25);
	char3 = assetMaker(m_physicsWorld, "charenter.png", 10, 10, 0, 0, 25);
	char4 = assetMaker(m_physicsWorld, "charenter.png", 10, 10, 0, 0, 25);
	ECS::GetComponent<Sprite>(char1).SetTransparency(0.f);
	ECS::GetComponent<Sprite>(char2).SetTransparency(0.f);
	ECS::GetComponent<Sprite>(char3).SetTransparency(0.f);
	ECS::GetComponent<Sprite>(char4).SetTransparency(0.f);

	//Beginning Message
	MessageBox(NULL, "Welcome To Grims Overlook", "New Game", NULL);

	ECS::GetComponent<HorizontalScroll>(MainEntities::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(MainEntities::MainPlayer()));
	ECS::GetComponent<VerticalScroll>(MainEntities::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(MainEntities::MainPlayer()));
}

void PhysicsPlayground::GUI()
{
	GUIWindowUI();

	if (m_firstWindow)
	{
		GUIWindowOne();
	}

	if (m_secondWindow)
	{
		GUIWindowTwo();
	}
}

void PhysicsPlayground::GUIWindowUI()
{
	ImGui::Begin("Test");

	ImGui::Checkbox("Enable First Window", &m_firstWindow);
	ImGui::SameLine();
	if (ImGui::Button("Toggle Second Window", ImVec2(180.f, 15.f)))
	{
		m_secondWindow = !m_secondWindow;
	}


	ImGui::End();
}

void PhysicsPlayground::GUIWindowOne()
{
	//Window begin
	ImGui::Begin("Side Docked Window");
	//is the buffer initialized
	static bool init = false;

	//Buffers
	const unsigned int BUF_LEN = 512;
	static char buf[BUF_LEN];
	//Image load
	static std::string imageLoad = "LinkStandby.png";
	//World gravity slider
	float gravity[2] = { m_physicsWorld->GetGravity().x, m_physicsWorld->GetGravity().y };

	if (!init)
	{
		memset(buf, 0, BUF_LEN);
		init = true;
	}
	m_physicsWorld->SetAllowSleeping(true);

	//ImGui content
	if (ImGui::TreeNode("Vignette Effect"))
	{
		if (EffectManager::GetVignetteHandle() != -1)
		{
			if (ImGui::TreeNode("Properties"))
			{
				VignetteEffect* vig = (VignetteEffect*)EffectManager::GetEffect(EffectManager::GetVignetteHandle());
				float innerRad = vig->GetInnerRadius();
				float outerRad = vig->GetOuterRadius();
				float opacity = vig->GetOpacity();

				if (ImGui::SliderFloat("Inner Radius", &innerRad, 0.f, outerRad))
				{
					vig->SetInnerRadius(innerRad);
				}
				if (ImGui::SliderFloat("Outer Radius", &outerRad, innerRad, 1.f))
				{
					vig->SetOuterRadius(outerRad);
				}
				if (ImGui::SliderFloat("Opacity", &opacity, 0.f, 1.f))
				{
					vig->SetOpacity(opacity);
				}

				ImGui::TreePop();
			}

			if (ImGui::Button("Remove Effect", ImVec2(100.f, 30.f)))
			{
				EffectManager::RemoveEffect(EffectManager::GetVignetteHandle());
			}
		}
		else
		{
			if (ImGui::Button("Apply Effect", ImVec2(100.f, 30.f)))
			{
				EffectManager::CreateEffect(Vignette, BackEnd::GetWindowWidth(), BackEnd::GetWindowHeight());
			}
		}


		ImGui::TreePop();
	}

	if (ImGui::TreeNode("Sepia Effect"))
	{
		if (EffectManager::GetSepiaHandle() != -1)
		{
			if (ImGui::TreeNode("Properties"))
			{
				SepiaEffect* sep = (SepiaEffect*)EffectManager::GetEffect(EffectManager::GetSepiaHandle());
				float intensity = sep->GetIntensity();

				if (ImGui::SliderFloat("Inner Radius", &intensity, 0.f, 1.f))
				{
					sep->SetIntensity(intensity);
				}

				ImGui::TreePop();
			}

			if (ImGui::Button("Remove Effect", ImVec2(100.f, 30.f)))
			{
				EffectManager::RemoveEffect(EffectManager::GetSepiaHandle());
			}
		}
		else
		{
			if (ImGui::Button("Apply Effect", ImVec2(100.f, 30.f)))
			{
				EffectManager::CreateEffect(Sepia, BackEnd::GetWindowWidth(), BackEnd::GetWindowHeight());
			}
		}


		ImGui::TreePop();
	}

	ImGui::Separator();

	ImGui::Text("Editing World Variables!");
	if (ImGui::SliderFloat2("World Gravity", gravity, -1000.f, 1000.f, "%.2f"))
	{
		m_physicsWorld->SetGravity(b2Vec2(gravity[0], gravity[1]));
		m_physicsWorld->SetAllowSleeping(false);
	}

	ImGui::Separator();

	ImGui::Text("Displaying image dynamically");
	ImGui::InputText("Input filename for image", buf, BUF_LEN, ImGuiInputTextFlags_CharsNoBlank);

	if (ImGui::Button("Confirm File", ImVec2(100.f, 30.f)))
	{
		imageLoad = buf;
	}

	ImGui::Image((void*)(intptr_t)TextureManager::FindTexture(imageLoad)->GetID(), ImVec2(150.f, 150.f), ImVec2(0, 1), ImVec2(1, 0));

	ImGui::Separator();

	ImGui::Text("Editing Colors");
	ImGui::ColorPicker4("Scene Background Color", &m_clearColor.x);

	ImGui::End();
}

void PhysicsPlayground::GUIWindowTwo()
{
	//Second docked window
	ImGui::Begin("Second Window");
	//Image load
	static std::string imageLoad1 = "FunnyButton.png";
	static std::string imageLoad2 = "LikeButton.png";
	static std::string hahaPressed = "";
	static std::string likePressed = "";

	ImGui::BeginTabBar("Tab Bar Test");

	if (ImGui::BeginTabItem("Tab 1"))
	{
		ImGui::Text("You are within Tab 1");

		if (ImGui::ImageButton((void*)(intptr_t)TextureManager::FindTexture(imageLoad1)->GetID(), ImVec2(100.f, 100.f), ImVec2(0, 1), ImVec2(1, 0)))
		{
			hahaPressed = "You shouldn't have pressed that...";
		}

		ImGui::Text("%s", hahaPressed.c_str());

		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("Tab 2"))
	{
		ImGui::Text("You are within Tab 2");

		if (ImGui::ImageButton((void*)(intptr_t)TextureManager::FindTexture(imageLoad2)->GetID(), ImVec2(100.f, 100.f), ImVec2(0, 1), ImVec2(1, 0)))
		{
			likePressed = "LIKED!!!";
		}

		ImGui::Text("%s", likePressed.c_str());

		ImGui::EndTabItem();
	}

	ImGui::EndTabBar();

	ImGui::End();
}


void PhysicsPlayground::myPlaySound(std::string filepath)
{
	if (sounds[filepath] == nullptr) {

		ToneFire::CoreSound* sound1=new ToneFire::CoreSound{ filepath, FMOD_2D };
		sounds[filepath] = sound1;
	}
	if (!sounds[filepath]->IsPlaying()) {
		sounds[filepath]->Play();
	}

}


void PhysicsPlayground::KeyboardHold()
{
	auto& player = ECS::GetComponent<PhysicsBody>(MainEntities::MainPlayer());
	auto& flashlight = ECS::GetComponent<PhysicsBody>(MainEntities::MainFlashlight());

	float speed = 1.f;
	b2Vec2 vel = b2Vec2(0.f, 0.f);


	if (Input::GetKey(Key::A))
	{
		player.GetBody()->SetLinearVelocity(b2Vec2(-5000.f, 0.f));
		//std::string fileName = "playerr.png";
		//ECS::GetComponent<Sprite>(playerid).LoadSprite(fileName, 40, 30);
	}
	if (Input::GetKey(Key::D))
	{
		player.GetBody()->SetLinearVelocity(b2Vec2(5000.f, 0.f));
		//std::string fileName = "playerl.png";
		//ECS::GetComponent<Sprite>(playerid).LoadSprite(fileName, 40, 30);
	}
	if (Input::GetKey(Key::W))
	{
		player.GetBody()->SetLinearVelocity(b2Vec2(0.f, 5000.f));
		//std::string fileName = "player.png";
		//ECS::GetComponent<Sprite>(playerid).LoadSprite(fileName, 40, 30);
	}
	if (Input::GetKey(Key::S))
	{
		player.GetBody()->SetLinearVelocity(b2Vec2(0.f, -5000.f));
		//std::string fileName = "playeru.png";
		//ECS::GetComponent<Sprite>(playerid).LoadSprite(fileName, 40, 30);
	}

}

void PhysicsPlayground::KeyboardDown()
{
	auto& player = ECS::GetComponent<PhysicsBody>(MainEntities::MainPlayer());
	float playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
	float playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
	float tempenergy, energy;
	if (Input::GetKeyDown(Key::T))
	{
		PhysicsBody::SetDraw(!PhysicsBody::GetDraw());
	}
	if (Input::GetKeyUp(Key::Enter))
	{
		playerx = 0;
	}

	if (Input::GetKeyDown(Key::UpArrow))
	{
		pgangleup = true;
	}

	if (Input::GetKeyDown(Key::DownArrow))
	{
		pgangledown = true;
	}

	if (Input::GetKeyDown(Key::E))
	{
		ECS::GetComponent<Sprite>(flashlightid).SetTransparency(0.0f);
		flashlightclick = flashlightclick + 1;
		if (flashlightclick % 2 == 0 && usingbattery == true) {
			ECS::GetComponent<Sprite>(flashlightoff).SetTransparency(0.0f);
			ECS::GetComponent<Sprite>(flashlightid).SetTransparency(0.85f);
			flon = true;
		}
		else {
			ECS::GetComponent<Sprite>(flashlightid).SetTransparency(0.0f);
			ECS::GetComponent<Sprite>(flashlightoff).SetTransparency(0.85f);
			flon = false;
		}
	}

	if (Input::GetKeyDown(Key::Space))
	{
		titleappear = false;
	}
	if (Input::GetKeyDown(Key::NumPad0)) {

		if (keypad == true) {
			keypadnum.append("0");
		}
	}
	if (Input::GetKeyDown(Key::NumPad1)) {

		if (keypad == true) {
			keypadnum.append("1");
		}
	}
	if (Input::GetKeyDown(Key::NumPad2)) {

		if (keypad == true) {
			keypadnum.append("2");
		}
	}
	if (Input::GetKeyDown(Key::NumPad3)) {

		if (keypad == true) {
			keypadnum.append("3");
		}
	}
	if (Input::GetKeyDown(Key::NumPad4)) {

		if (keypad == true) {
			keypadnum.append("4");
		}
	}
	if (Input::GetKeyDown(Key::NumPad5)) {

		if (keypad == true) {
			keypadnum.append("5");
		}
	}
	if (Input::GetKeyDown(Key::NumPad6)) {

		if (keypad == true) {
			keypadnum.append("6");
		}
	}
	if (Input::GetKeyDown(Key::NumPad7)) {

		if (keypad == true) {
			keypadnum.append("7");
		}
	}
	if (Input::GetKeyDown(Key::NumPad8)) {

		if (keypad == true) {
			keypadnum.append("8");
		}
	}
	if (Input::GetKeyDown(Key::NumPad9)) {

		if (keypad == true) {
			keypadnum.append("9");
		}
	}
}

void PhysicsPlayground::KeyboardUp()
{
	auto& player = ECS::GetComponent<PhysicsBody>(MainEntities::MainPlayer());
	float playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
	float playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
	float speed = 1.f;
	b2Vec2 vel = b2Vec2(0.f, 0.f);
	if (Input::GetKeyUp(Key::A))
	{
		player.GetBody()->SetLinearVelocity(b2Vec2(0.f, 0.f));
	}
	if (Input::GetKeyUp(Key::D))
	{
		player.GetBody()->SetLinearVelocity(b2Vec2(0.f, 0.f));
	}
	if (Input::GetKeyUp(Key::W))
	{
		player.GetBody()->SetLinearVelocity(b2Vec2(0.f, 0.f));
	}
	if (Input::GetKeyUp(Key::S))
	{
		player.GetBody()->SetLinearVelocity(b2Vec2(0.f, 0.f));
	}

	if (Input::GetKeyUp(Key::UpArrow))
	{
		pgangleup = false;
		pgangledown = false;

	}

	if (Input::GetKeyUp(Key::DownArrow))
	{
		pgangleup = false;
		pgangledown = false;
	}
}

void PhysicsPlayground::SetPlayerCoords(int x, int y) {
	ECS::GetComponent<Transform>(playerid).SetPosition(vec3(x, y, 2.f));
	ECS::GetComponent<PhysicsBody>(playerid).SetPosition(b2Vec2(x, y));
}



void PhysicsPlayground::Update()
{
	
	fmod.Update();
	// loud be careful before turning on
	myPlaySound("Ambiance.mp3");

	auto& flashlight = ECS::GetComponent<PhysicsBody>(flashlightid);
	auto& cursor = ECS::GetComponent<PhysicsBody>(cursorid);
	auto& player = ECS::GetComponent<PhysicsBody>(playerid);
	float playerx, playery, flashlightangle, cx, cy;
	playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
	playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
	ECS::GetComponent<Player>(MainEntities::MainPlayer()).Update();


	for (b2Body* b = m_physicsWorld->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetLinearVelocity() != b2Vec2(0, 0)) {
			b->SetLinearVelocity(b2Vec2(0, 0));
		}
	}

	POINT point;
	GetCursorPos(&point); //gets coordinates of cursor
	//SetCursorPos(900, 900);
	ShowCursor(true);

	//checks monitor resolution
	int resolutionx = GetSystemMetrics(SM_CXSCREEN);
	if (resolutionx == 2560) {
		cursor.SetPosition(b2Vec2((((point.x) / 2) + playerx) - 320, -(((point.y) / 2) - playery) + 175));
		ECS::GetComponent<Transform>(fbfull).SetPosition(vec3(playerx, playery, 2.f));
		//ECS::GetComponent<Transform>(fbfull).SetPosition(vec3(45.f, -8.f, 2.f));
	}
	else if (resolutionx == 1920) {
		cursor.SetPosition(b2Vec2((((point.x) / 2) + playerx) - 240, -(((point.y) / 2) - playery) + 130));
	}

	//gets player to rotate based on where the mouse is
	float x1 = 1, y1 = 1, f1;
	if (point.x > 960 && point.y <= 540) { //top right quadrant of screen
		x1 = point.x - 960;
		y1 = point.y - 540;
		f1 = (-atan(y1 / x1)) * (180 / PI);
		player.SetRotationAngleDeg(f1);
		flashlight.SetRotationAngleDeg(f1);
	}
	if (point.x <= 960 && point.y <= 540) { // top left quadrant of screen
		x1 = point.x - 960;
		y1 = point.y - 540;
		f1 = (-atan(y1 / x1)) * (180 / PI);
		player.SetRotationAngleDeg(f1 + 180.f);
		flashlight.SetRotationAngleDeg(f1 + 180.f);
	}
	if (point.x <= 960 && point.y > 540) { //bottom left quadrant of screen
		x1 = point.x - 960;
		y1 = point.y - 540;
		f1 = (-atan(y1 / x1)) * (180 / PI);
		player.SetRotationAngleDeg(f1 + 180.f);
		flashlight.SetRotationAngleDeg(f1 + 180.f);
	}
	if (point.x > 960 && point.y > 540) { //bottom right quadrant of screen
		x1 = point.x - 960;
		y1 = point.y - 540;
		f1 = (-atan(y1 / x1)) * (180 / PI);
		player.SetRotationAngleDeg(f1);
		flashlight.SetRotationAngleDeg(f1);
	}
	//cout << player.GetRotationAngleDeg() << "\n";

	//Timer 1 (For flashlight battery)
	//cout << timer1 << "\n";
	if (flon == true) {
		timer1 = timer1 + 1.f;
	}
	else {
		timer1 = timer1 - 0.f;
	}

	//Timer 2 (For keypad lights)
	//cout << timer1 << "\n";
	if (kpl == true) {
		timer2 = timer2 + 1.f;
	}
	else {
		timer2 = 0.f;
	}

	timer3 = timer3 + 1.f;


	//Changes Battery Life Based on Time
	if (timer1 <= 5000) {
		ECS::GetComponent<Sprite>(fbfull).SetTransparency(1.f);
		ECS::GetComponent<Sprite>(fbhalf).SetTransparency(0.f);
		ECS::GetComponent<Sprite>(fbempty).SetTransparency(0.f);
	}
	else if (timer1 >= 5000 && timer1 < 10000) {
		ECS::GetComponent<Sprite>(fbfull).SetTransparency(0.f);
		ECS::GetComponent<Sprite>(fbhalf).SetTransparency(1.f);
		ECS::GetComponent<Sprite>(fbempty).SetTransparency(0.f);
	}
	else {
		ECS::GetComponent<Sprite>(fbfull).SetTransparency(0.f);
		ECS::GetComponent<Sprite>(fbhalf).SetTransparency(0.f);
		ECS::GetComponent<Sprite>(fbempty).SetTransparency(1.f);
	}


	//Gives player a battery when they hit it
	if ((ECS::GetComponent<Sprite>(battery1).GetTransparency()) == 0) {
		batterys = batterys + 1;
		ECS::GetComponent<Transform>(batterytrigger).SetPosition(vec3(-1000, -1000, 0.f));
		ECS::GetComponent<Transform>(battery1).SetPosition(vec3(-1000, -1000, 0.f));
		ECS::GetComponent<Sprite>(battery1).SetTransparency(1);
	}

	if (batterys > 0 && timer1 > 10000) {
		batterys = batterys - 1;
		timer1 = 0;
	}
	if (batterys == 0 && timer1 > 10000) {
		usingbattery = false;
		ECS::GetComponent<Sprite>(flashlightid).SetTransparency(0.0f);
		ECS::GetComponent<Sprite>(flashlightoff).SetTransparency(0.85f);
	}
	else {
		usingbattery = true;
	}

	//cout << timer1 << "/n";

	//Sets things to follow the player
	ECS::GetComponent<Transform>(bignote1).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(bignote2).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(bignote3).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(bignote4).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(bignote5).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(bignote6).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(bignote7).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(flashlightoff).SetPosition(vec3(playerx, playery, 50.f));
	ECS::GetComponent<Transform>(fbfull).SetPosition(vec3(playerx - 90, playery + 90, 50.f));
	ECS::GetComponent<Transform>(fbhalf).SetPosition(vec3(playerx - 90, playery + 90, 50.f));
	ECS::GetComponent<Transform>(fbempty).SetPosition(vec3(playerx - 90, playery + 90, 50.f));
	ECS::GetComponent<Transform>(mkid).SetPosition(vec3(playerx + 100, playery + 100, 50.f));
	ECS::GetComponent<Transform>(gsid).SetPosition(vec3(playerx + 150, playery + 100, 50.f));
	ECS::GetComponent<Transform>(kpg).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(kpr).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(maintitle).SetPosition(vec3(playerx, playery, 100.f));

	ECS::GetComponent<Transform>(char1).SetPosition(vec3(playerx - 120, playery - 100, 50.f));
	ECS::GetComponent<Transform>(char2).SetPosition(vec3(playerx - 110, playery - 100, 50.f));
	ECS::GetComponent<Transform>(char3).SetPosition(vec3(playerx - 100, playery - 100, 50.f));
	ECS::GetComponent<Transform>(char4).SetPosition(vec3(playerx - 90, playery - 100, 50.f));


	//cout << playerx << "\n" << playery << "\n";d

	//library
	if (playery > 30 && playery < 40 && playerx > 280 && playerx < 320) {
		SetPlayerCoords(2172, 2050);
	}

	if (playery < 2040 && playery > 2000) {
		SetPlayerCoords(300, 8);
	}

	//mechanics
	if (playery > 30 && playery < 35 && playerx > 670 && playerx < 710 && openmech == true) {
		SetPlayerCoords(-1202, -2522);
	}

	if (playerx < -1148 && playerx > -1252 && playery > -2560 && playery < -2550 && openmech == true) {
		SetPlayerCoords(690, 20);
	}

	//Grocery
	if (playery > 30 && playery < 40 && playerx > 460 && playerx < 540 && opengro == true) {
		SetPlayerCoords(1216.25, -1100);
	}

	if(playery > -1282 && playery < -1200 && playerx > 1147.5 && playerx < 1285) {
		SetPlayerCoords(500, 8);
		for (b2Body* b = m_physicsWorld->GetBodyList(); b; b = b->GetNext())
		{
			if (b->GetUserData() != NULL) {
				if ((int)b->GetUserData() >= 0 && b->GetType() == b2_dynamicBody && b->IsFixedRotation()) {
					b->SetTransform(b2Vec2(cartCoords[(int)b->GetUserData()-1][0], cartCoords[(int)b->GetUserData()-1][1]), b->GetAngle());
				}
			}
		}
	}

	flashlightangle = flashlight.GetRotationAngleDeg();
	flashlight.SetPosition(b2Vec2(playerx, playery));

	if (pgangleup) {
		flashlight.SetRotationAngleDeg(flashlightangle + 2.f);
	}
	else if (pgangledown) {
		flashlight.SetRotationAngleDeg(flashlightangle - 2.f);
	}
	else if (!pgangleup && !pgangledown) {
		flashlight.SetRotationAngleDeg(flashlightangle);
	}


	//cout << ECS::GetComponent<Camera>(cameraid).GetPositionX();
	//ECS::GetComponent<Camera>(cameraid).GetPositionY();

	//Keypad in mechanics puzzle
	if (playery > -2170 && playery < -2130 && playerx < -950 && playerx > -990) {
		keypad = true;
	}
	else {
		ECS::GetComponent<Sprite>(kpr).SetTransparency(0.f);
		ECS::GetComponent<Sprite>(kpg).SetTransparency(0.f);
		keypad = false;
	}

	//circles when player inputs a number
	if (keypadnum.length() >= 1) {
		ECS::GetComponent<Sprite>(char1).SetTransparency(1.f);
	}
	if (keypadnum.length() >= 2) {
		ECS::GetComponent<Sprite>(char2).SetTransparency(1.f);
	}
	if (keypadnum.length() >= 3) {
		ECS::GetComponent<Sprite>(char3).SetTransparency(1.f);
	}
	if (keypadnum.length() >= 4) {
		ECS::GetComponent<Sprite>(char4).SetTransparency(1.f);
	}
	else {
		ECS::GetComponent<Sprite>(char1).SetTransparency(0.f);
		ECS::GetComponent<Sprite>(char2).SetTransparency(0.f);
		ECS::GetComponent<Sprite>(char3).SetTransparency(0.f);
		ECS::GetComponent<Sprite>(char4).SetTransparency(0.f);
	}

	if (keypadnum.length() > 3 && keypadnum != "1432") {
		kpl = true;
		ECS::GetComponent<Sprite>(kpr).SetTransparency(1.f);
		keypadnum = "";
		if (timer2 > 300) {
			ECS::GetComponent<Sprite>(kpr).SetTransparency(0.f);
			kpl = false;
		}
	}
	if (keypadnum == "1432") {
		kpl = true;
		ECS::GetComponent<Sprite>(kpg).SetTransparency(1.f);
		keypadnum = "";
		if (timer2 > 300) {
			ECS::GetComponent<Sprite>(kpg).SetTransparency(0.f);
			kpl = false;
			keyappear = true;
		}
	}

	if (keyappear == true) {
		ECS::GetComponent<Transform>(door).SetPosition(vec3(-200, -200, 50.f));
		ECS::GetComponent<PhysicsBody>(door).SetPosition(b2Vec2(-300, -300));
	}

	if (playerx < 1508 && playerx > 1472 && playery < -1230 && playery > -1282) {
		MessageBox(NULL, "Congratulations!", "You have saved Oliver's family!", NULL);
	}

	if (titleappear == false) {
		ECS::GetComponent<Sprite>(maintitle).SetTransparency(0.f);
	}

	if (ECS::GetComponent<Sprite>(mkid).GetTransparency() == 1) {
		openmech = true;
	}

	if (ECS::GetComponent<Sprite>(gsid).GetTransparency() == 1) {
		opengro = true;
	}

	if (tutorial1 == false) {
		ECS::GetComponent<Sprite>(tut).SetTransparency(0.f);
	}

	if (timer3 > 300) {
		tutorial1 = false;
	}

}