#pragma once
#include <vector>

class Trigger
{
public:
	//Depreciated use OnEnter and OnExit instead
	virtual void OnTrigger();

	virtual void OnEnter();
	virtual void OnExit();

	void SetTriggerEntity(int triggerEnt);
	int GetTriggerEntity();

	void AddTargetEntity(int entity);
	void SetTargetEntities(std::vector<int> entities);
	std::vector<int> GetTargetEntities();

	void SetObjCoords(int x, int y);

	void SetPlayerID(int id);
	void SetObjID(int id);
	virtual bool GetTrigger();

protected:
	int m_triggerEntity;
	std::vector<int> m_targetEntities;
	int objx, objy;
	int playerid;
	int objid;
};

