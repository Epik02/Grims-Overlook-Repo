#include "TrueFalseTrigger.h"
#include "ECS.h"

void TrueFalseTrigger::OnTrigger()
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

void TrueFalseTrigger::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		ECS::GetComponent<Sprite>(m_targetEntities[1]).SetTransparency(0);
		triggered = true;
	}
}

void TrueFalseTrigger::pleasework(bool& testing) {
	testing = triggered;
}

bool TrueFalseTrigger::GetTrigger() {
	return triggered;
}

void TrueFalseTrigger::OnExit()
{
	Trigger::OnExit();
	ECS::GetComponent<Sprite>(m_targetEntities[1]).SetTransparency(0);
	triggered = false;
}