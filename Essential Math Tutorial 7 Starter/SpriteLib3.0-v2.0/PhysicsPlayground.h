#pragma once

#include "Scene.h"
#include "PhysicsPlaygroundListener.h"
#include <string>
#include "Tone Fire/ToneFire.h"
#include <unordered_map>

class PhysicsPlayground : public Scene
{
public:
	PhysicsPlayground(std::string name);

	void InitScene(float windowWidth, float windowHeight) override;

	void Update() override;
	void SetPlayerCoords(int x, int y);

	void GUI() override;

	void GUIWindowUI();
	void GUIWindowOne();
	void GUIWindowTwo();

	void myPlaySound(std::string filepath);

	//Input overrides
	void KeyboardHold() override;
	void KeyboardDown() override;
	void KeyboardUp() override;

protected:
	std::unordered_map<std::string, ToneFire::CoreSound*> sounds;
	ToneFire::FMODCore fmod{};
	bool m_firstWindow = false;
	bool m_secondWindow = false;

	std::string m_fileInput;

	PhysicsPlaygroundListener listener;

	int puzzleWall1;
	int puzzleWall2;
	int puzzleWall3;
	int puzzleWall4;
	int puzzleWall5;
	int puzzleWall6;
	int puzzleWall7;
	int puzzleWall8;
	int puzzleWall9;
	int puzzleWall10;
	int puzzleWall11;
	int puzzleWall12;
};
