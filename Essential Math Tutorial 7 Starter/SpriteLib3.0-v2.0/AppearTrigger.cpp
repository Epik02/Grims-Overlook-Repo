#include "AppearTrigger.h"
#include "ECS.h"

void AppearTrigger::OnTrigger()
{
	Trigger::OnTrigger();

	if (!triggered)
	{
		for (int i = 0; i < m_targetEntities.size(); i++)
		{
			ECS::GetComponent<PhysicsBody>(m_targetEntities[i]).SetPosition(b2Vec2(0, 0));
		}
		triggered = true;
	}
}

void AppearTrigger::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		ECS::GetComponent<Sprite>(m_targetEntities[2]).SetTransparency(1);
		triggered = true;
	}
}

void AppearTrigger::pleasework(bool& testing) {
	testing = triggered;
}

bool AppearTrigger::GetTrigger() {
	return triggered;
}

void AppearTrigger::OnExit()
{
	Trigger::OnExit();
	ECS::GetComponent<Sprite>(m_targetEntities[2]).SetTransparency(1);
	ECS::GetComponent<Sprite>(m_targetEntities[0]).SetTransparency(0);
	triggered = false;
}