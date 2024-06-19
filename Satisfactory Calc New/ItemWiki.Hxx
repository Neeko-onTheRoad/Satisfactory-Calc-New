#pragma once

#ifndef _ITEM_WIKI_HXX_
#define _ITEM_WIKI_HXX_

#include "ConsoleScene.Hxx"

class ItemWiki : public ConsoleScene {

private:

	


protected:
	
	void ConsoleScene::Initialize();
	void ConsoleScene::Update();


public:
	
	std::string ConsoleScene::GetTitle() const;


};


#endif