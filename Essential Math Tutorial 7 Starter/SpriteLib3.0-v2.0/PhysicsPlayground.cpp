#include "PhysicsPlayground.h"
#include "Utilities.h"
#include "Camera.h"
#include "PopUpTrigger.h"
#include "windows.h"
#include "winuser.h"
#include <ctime>

#include <random>
using namespace std;
//int playerid;
//int playerid;
int flashlightid;
int flashlightoff;
int cameraid;
int cursorid;
int playerid;
int oops;
int oops2;
int bignote1;
bool pgangleup;
bool pgangledown;
int flashlightclick = 0;
int fbfull;
int fbhalf;
int fbempty;
int mkid;
//float energy;


PhysicsPlayground::PhysicsPlayground(std::string name)
	: Scene(name)
{
	//No gravity this is a top down scene
	m_gravity = b2Vec2(0.f, 0.f);
	m_physicsWorld->SetGravity(m_gravity);

	m_physicsWorld->SetContactListener(&listener);
}

int assetMaker(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy) {
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

int pushObject(b2World* m_physicsWorld, string asset, int sizex, int sizey, int posx, int posy)
	{
		float playerx, playery;
		playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
		playery = ECS::GetComponent<Transform>(playerid).GetPositionY();
		return 0;
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
		tempDef.type = b2_dynamicBody;
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

		//Sets up the components
		std::string fileName = "Player.png";
		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 40, 30);
		ECS::GetComponent<Sprite>(entity).SetTransparency(1.f);
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 30.f, 2.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		float shrinkX = 0.f;
		float shrinkY = 0.f;

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_dynamicBody;
		tempDef.position.Set(float32(-1000.f), float32(-2330.f));

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		//tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, PLAYER, ENEMY | OBJECTS | PICKUP | TRIGGER, 0.5f, 3.f);
		tempPhsBody = PhysicsBody(entity, tempBody, float((tempSpr.GetHeight() - shrinkY)/2.f), vec2(0.f, 0.f), false, PLAYER, ENVIRONMENT | ENEMY | OBJECTS | PICKUP | TRIGGER | HEXAGON, 5.f, 3.f);
		//std::vector<b2Vec2> points = {b2Vec2(-tempSpr.GetWidth()/2.f, -tempSpr.GetHeight()/2.f), b2Vec2(tempSpr.GetWidth()/2.f, -tempSpr.GetHeight()/2.f), b2Vec2(0.f, tempSpr.GetHeight()/2.f)};
		//tempPhsBody = PhysicsBody(entity, BodyType::TRIANGLE, tempBody, points, vec2(0.f, 0.f), false, PLAYER, ENEMY | OBJECTS | PICKUP | TRIGGER, 0.5f, 3.f);

		tempPhsBody.SetRotationAngleDeg(180.f);
		tempPhsBody.SetFixedRotation(true);
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
		ECS::GetComponent<Sprite>(entity).SetTransparency(0.0f);
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
		puzzleWall1 = entity;

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
		tempDef.position.Set(float32(100), float32(100));

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
		tempDef.position.Set(float32(100), float32(90)); //coords

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

	////Setup trigger
	//{
	//	//Creates entity
	//	auto entity = ECS::CreateEntity();

	//	//Add components
	//	ECS::AttachComponent<Transform>(entity);
	//	ECS::AttachComponent<PhysicsBody>(entity);
	//	ECS::AttachComponent<Trigger*>(entity);
	//	
	//	//Sets up components
	//	std::string fileName = "boxSprite.jpg";
	//	ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 80.f));
	//	ECS::GetComponent<Trigger*>(entity) = new TranslateTrigger();
	//	ECS::GetComponent<Trigger*>(entity)->SetTriggerEntity(entity);
	//	ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall1);
	//	TranslateTrigger* temp = (TranslateTrigger*)ECS::GetComponent<Trigger*>(entity);
	//	temp->movement = b2Vec2(0.f, 15.f);
	//	
	//	//ECS::GetComponent<Trigger*>(entity)->AddTargetEntity(puzzleWall2);

	//	auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

	//	float shrinkX = 0.f;
	//	float shrinkY = 0.f;
	//	b2Body* tempBody;
	//	b2BodyDef tempDef;
	//	tempDef.type = b2_staticBody;
	//	tempDef.position.Set(float32(295.f), float32(-30.f));

	//	tempBody = m_physicsWorld->CreateBody(&tempDef);

	//	tempPhsBody = PhysicsBody(entity, tempBody, float(40.f - shrinkX), float(40.f - shrinkY), vec2(0.f, 0.f), true, TRIGGER, PLAYER | OBJECTS);
	//	tempPhsBody.SetColor(vec4(1.f, 0.f, 0.f, 0.3f));
	//}
	
	int truck = assetMaker(m_physicsWorld, "Truck.png",75, 125, -100, 0);
	int repairshop = assetMaker(m_physicsWorld, "Repairshop.png", 100, 100, 700, 100);
	int library = assetMaker(m_physicsWorld, "library.png", 100, 100, 300, 100);

	int road00 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, -200, 0);
	int road0 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 0, 0);
	int road = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 200, 0);
	int road2 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 400, 0);
	int road3 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 600, 0);
	int road4 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 800, 0);
	int road5 = assetMakerbg(m_physicsWorld, "road.png", 200, 100, 1000, 0);

	//inside library
	assetMaker(m_physicsWorld, "darkbrown.jpg", 400, 26, 1943, 2085);
	assetMaker(m_physicsWorld, "darkbrown.jpg", 250, 26, 2326, 2085);//bottom wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 400, 100, 1943, 2035);
	assetMaker(m_physicsWorld, "darkbrown.jpg", 250, 100, 2326, 2035); //bottom wall fill in
	assetMaker(m_physicsWorld, "darkbrown.jpg", 70, 20, 2170, 1995); //door

	assetMaker(m_physicsWorld, "darkbrown.jpg", 20, 610, 1745, 2385); //left wall

	assetMaker(m_physicsWorld, "darkbrown.jpg", 710, 20, 2103, 2680); //top wall

	assetMaker(m_physicsWorld, "darkbrown.jpg", 20, 630, 2450, 2355); //right wall

	//library maze 	
	assetMaker(m_physicsWorld, "darkbrown.jpg", 110, 25, 1808, 2359); //little wall left
	assetMaker(m_physicsWorld, "darkbrown.jpg", 300, 26, 1990, 2278); //bottom wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 210, 1941, 2373); //connected to bottom wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 120, 25, 2065, 2374); //little wall right
	assetMaker(m_physicsWorld, "darkbrown.jpg", 20, 420, 2130, 2480); //right wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 170, 25, 1976, 2470); //middle
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 205, 1810, 2510); //leftmost wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 262, 26, 1930, 2622); //top wall
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 106, 1884, 2510); //connected to middle (little)
	assetMaker(m_physicsWorld, "darkbrown.jpg", 97, 26, 1926, 2550); //backwards L bottom
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 100, 1965, 2588); //backwards L top
	assetMaker(m_physicsWorld, "darkbrown.jpg", 90, 26, 2080, 2543); //little wall top right

	//library room
	assetMaker(m_physicsWorld, "darkbrown.jpg", 230, 26, 2336, 2283); //bottom
	assetMaker(m_physicsWorld, "darkbrown.jpg", 20, 330, 2219, 2435); //top


	//office maze
	assetMakerturn(m_physicsWorld, "bookshelf.png", 40, 80, 2270, 2580);
	assetMakerturn(m_physicsWorld, "bookshelf.png", 40, 80, 2350, 2580);
	assetMakerturn(m_physicsWorld, "bookshelf.png", 40, 80, 2310, 2500);
	assetMaker(m_physicsWorld, "bookshelf.png", 40, 80, 2370, 2480);
	assetMakerturn(m_physicsWorld, "bookshelf.png", 40, 80, 2350, 2420);
	assetMaker(m_physicsWorld, "bookshelf.png", 30, 60, 2250, 2410);
	assetMaker(m_physicsWorld, "bookshelf.png", 40, 80, 2370, 2351);

	//props
	//Assorted Tools.png
	//Plant.png
	//Pile of Books.png
	objectMaker(m_physicsWorld, "Assorted Tools.png", 20, 20, 2280, 2580, 0);
	objectMaker(m_physicsWorld, "Pile of Books.png", 20, 20, 2310, 2500, 0);
	objectMaker(m_physicsWorld, "Pile of Books.png", 20, 20, 2310, 2330, 0);
	assetMaker(m_physicsWorld, "Plant.png", 40, 40, 2416, 2331);
	objectMaker(m_physicsWorld, "Plant.png", 10, 10, 2250, 2435, 0);
	objectMaker(m_physicsWorld, "Plant.png", 10, 10, 2250, 2390, 0);
	objectMaker(m_physicsWorld, "Pile of Books.png", 15, 15, 2330, 2330, 45);
	//objectMaker(m_physicsWorld, "Assorted Tools.png", 15, 15, );

	assetMaker(m_physicsWorld, "table.png", 100, 67, 2290, 2330); //table


	//outside library background
	assetMakerbg(m_physicsWorld, "black.png", 1500, 1500, 2000, 2650);

	//mechanics
	assetMaker(m_physicsWorld, "darkbrown.jpg", 460, 26, -928, -2550); //bottom
	assetMaker(m_physicsWorld, "darkbrown.jpg", 40, 26, -1270, -2550); //bottom left
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 440, -710, -2340); //right
	assetMaker(m_physicsWorld, "darkbrown.jpg", 600, 26, -995, -2110); //top
	assetMaker(m_physicsWorld, "darkbrown.jpg", 26, 440, -1280, -2340); //left

	assetMaker(m_physicsWorld, "darkbrown.jpg", 135, 20, -1212, -2280); //room bottom
	assetMaker(m_physicsWorld, "darkbrown.jpg", 25, 65, -1150, -2255); //left of door
	assetMaker(m_physicsWorld, "darkbrown.jpg", 25, 65, -1150, -2140); //right of door

	//cars
	assetMaker(m_physicsWorld, "car.png", 80, 160, -1025, -2380); //left of door
	assetMaker(m_physicsWorld, "car.png", 80, 160, -830, -2380); //right of door

	//HUD
	fbfull = HUD(m_physicsWorld, "flashbarfull.png", 140, 100, 0, 0, 51);
	fbhalf = HUD(m_physicsWorld, "flashbarempty.png", 140, 100, 0, 0, 51);
	fbempty = HUD(m_physicsWorld, "flashbarempty.png", 140, 100, 0, 0, 51);

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

		if (ImGui::ImageButton((void*)(intptr_t)TextureManager::FindTexture(imageLoad1)->GetID(), ImVec2(100.f, 100.f), ImVec2(0,1), ImVec2(1,0)))
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
		if (flashlightclick % 2 == 0) {
			ECS::GetComponent<Sprite>(flashlightoff).SetTransparency(0.0f);
			ECS::GetComponent<Sprite>(flashlightid).SetTransparency(0.85f);
			//tempenergy = clock();
		}
		else {
			ECS::GetComponent<Sprite>(flashlightid).SetTransparency(0.0f);
			ECS::GetComponent<Sprite>(flashlightoff).SetTransparency(0.85f);
			//energy = tempenergy - clock();
			//cout << energy;
		}
	//	if (energy >= 50) {
	//		ECS::GetComponent<Sprite>(fbfull).SetTransparency(1.f);
	//		ECS::GetComponent<Sprite>(fbhalf).SetTransparency(0.f);
	//		ECS::GetComponent<Sprite>(fbempty).SetTransparency(0.f);
	//	}
	//	else if (energy <= 50 && energy > 0) {
	//		ECS::GetComponent<Sprite>(fbfull).SetTransparency(0.f);
	//		ECS::GetComponent<Sprite>(fbhalf).SetTransparency(1.f);
	//		ECS::GetComponent<Sprite>(fbempty).SetTransparency(0.f);
	//	}
	//	else {
	//		ECS::GetComponent<Sprite>(fbfull).SetTransparency(0.f);
	//		ECS::GetComponent<Sprite>(fbhalf).SetTransparency(0.f);
	//		ECS::GetComponent<Sprite>(fbempty).SetTransparency(1.f);
	//	}
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
	ECS::GetComponent<PhysicsBody>(playerid).SetPosition(b2Vec2(x,y));
}

void PhysicsPlayground::Update()
{
	auto& flashlight = ECS::GetComponent<PhysicsBody>(flashlightid);
	auto& cursor = ECS::GetComponent<PhysicsBody>(cursorid);
	auto& player = ECS::GetComponent<PhysicsBody>(playerid);
	float playerx, playery, flashlightangle, cx, cy;
	playerx = ECS::GetComponent<Transform>(playerid).GetPositionX();
	playery = ECS::GetComponent<Transform>(playerid).GetPositionY();

	for (b2Body* b = m_physicsWorld->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetLinearVelocity() != b2Vec2(0,0)) {
			b->SetLinearVelocity(b2Vec2(0, 0));
		}
	}

	POINT point;
	GetCursorPos(&point); //gets coordinates of cursor
	//SetCursorPos(900, 900);
	ShowCursor(false);

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


	//Sets things to follow the player
	ECS::GetComponent<Transform>(bignote1).SetPosition(vec3(playerx + 100, playery + 40, 50.f));
	ECS::GetComponent<Transform>(flashlightoff).SetPosition(vec3(playerx, playery, 50.f));
	ECS::GetComponent<Transform>(fbfull).SetPosition(vec3(playerx - 90, playery + 90, 50.f));
	ECS::GetComponent<Transform>(fbhalf).SetPosition(vec3(playerx - 90, playery + 90, 50.f));
	ECS::GetComponent<Transform>(fbempty).SetPosition(vec3(playerx - 90, playery + 90, 50.f));
	ECS::GetComponent<Transform>(mkid).SetPosition(vec3(playerx + 100, playery + 100, 50.f));


	cout << playerx << "\n" << playery << "\n";

	//library
	if (playery > 30 && playery < 40 && playerx > 280 && playerx < 320) {
		SetPlayerCoords(2172, 2050);
	}

	if (playery < 2040 && playery > 2000) {
		SetPlayerCoords(300, 8);
	}
	
	//mechanics
	if (playery > 30 && playery < 35 && playerx > 670 && playerx < 710) {
		SetPlayerCoords(-1202, -2522);
	}

	if (playerx < -1148 && playerx > -1252 && playery > -2560 && playery < -2550) {
		SetPlayerCoords(690, 20);
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

}