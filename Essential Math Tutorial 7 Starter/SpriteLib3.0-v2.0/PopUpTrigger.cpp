#include "PopUpTrigger.h"
#include "ECS.h"

void PopUpTrigger::OnTrigger()
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

void PopUpTrigger::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		ECS::GetComponent<Sprite>(m_targetEntities[2]).SetTransparency(1);

		triggered = true;
	}
}

void PopUpTrigger::pleasework(bool& testing) {
	testing = triggered;
}

bool PopUpTrigger::GetTrigger() {
	return triggered;
}

void PopUpTrigger::OnExit()
{
	Trigger::OnExit();
	triggered = false;
	ECS::GetComponent<Sprite>(m_targetEntities[2]).SetTransparency(0);
}