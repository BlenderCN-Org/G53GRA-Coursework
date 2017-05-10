#pragma once

#include "../Framework/Engine/Scene.h"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};

private:
	void Initialise() override;
	void Projection() override;
	static void AddFlashlight();
};