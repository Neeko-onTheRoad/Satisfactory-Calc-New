#pragma once

#ifndef _EMPTY_SCENE_HXX_
#define _EMPTY_SCENE_HXX_

#include "ConsoleScene.Hxx"

class EmptyScene : public ConsoleScene {
protected:
	void ConsoleScene::Initialize() {};
	void ConsoleScene::Update() {};

};


#endif