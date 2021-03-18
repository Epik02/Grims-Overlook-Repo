#pragma once

#include "Trigger.h"

class PopUpTrigger : public Trigger 
{
public:
	void OnTrigger() override;

	void OnEnter() override;

	void pleasework(bool &testing);

	void OnExit() override;
	bool GetTrigger() override;
private:
	int objectid;
protected:
	int protect;
	bool triggered = false;
};

