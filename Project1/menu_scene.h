#pragma once
#include"Scene.h"
#include<iostream>
#include"scene_manager.h"
#include"animation.h"
#include"camera.h"
#include"timer.h"

extern SceneManager scene_manager;


extern IMAGE img_menu_background;


class MenuScene :public Scene  //MenuScene类继承自Scene基类
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		mciSendString(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
	}

	void on_draw(const Camera& camera)
	{
		putimage(0, 0, &img_menu_background);
	}
	void on_input(const ExMessage& msg)
	{
		if (msg.message==WM_KEYUP)
		{
			mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
			scene_manager.switch_to(SceneManager::SceneType::Selector);
		}
	}



	
};