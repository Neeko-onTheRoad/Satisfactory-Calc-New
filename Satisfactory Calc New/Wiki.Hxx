#pragma once

#ifndef _WIKI_HXX_
#define _WIKI_HXX_

#include "ConsoleScene.Hxx"

class Wiki : public ConsoleScene {

private:

	


protected:
	
	void ConsoleScene::Initialize();
	void ConsoleScene::Update();


public:
	
	std::string ConsoleScene::GetTitle() const;


};


#endif