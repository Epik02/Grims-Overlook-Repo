//#pragma once
//#include "Utilities.h"
//#include "Scene.h"
//class Assets
//{
//public:
//	Assets() {
//
//	}
//
//	friend class PhysicsPlayground;
//
//	void InitScene2(float windowWidth, float windowHeight) {
//		//Creates entity
//		auto entity = ECS::CreateEntity();
//
//		//Add components
//		ECS::AttachComponent<Sprite>(entity);
//		ECS::AttachComponent<Transform>(entity);
//		ECS::AttachComponent<PhysicsBody>(entity);
//
//		//Sets up components
//		std::string fileName = "boxSprite.jpg";
//		ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 80, 15);
//		ECS::GetComponent<Transform>(entity).SetPosition(vec3(30.f, -20.f, 2.f));
//
//		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
//		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
//
//		float shrinkX = 0.f;
//		float shrinkY = 0.f;
//		b2Body* tempBody;
//		b2BodyDef tempDef;
//		tempDef.type = b2_staticBody;
//		tempDef.position.Set(float32(322.f), float32(-15.f));
//
//
//		tempBody = PhysicsPlayground.m_physicsWorld->CreateBody(&tempDef);
//
//		tempPhsBody = PhysicsBody(entity, tempBody, float(tempSpr.GetWidth() - shrinkX), float(tempSpr.GetHeight() - shrinkY), vec2(0.f, 0.f), false, ENVIRONMENT, PLAYER | OBJECTS | ENEMY | HEXAGON);
//		tempPhsBody.SetColor(vec4(0.f, 1.f, 0.f, 0.3f));
//		tempPhsBody.SetRotationAngleDeg(90.f);
//	}
//private:
//
//};
//
