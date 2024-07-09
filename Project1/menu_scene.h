#pragma once
#include"Scene.h"
#include<iostream>
#include"scene_manager.h"


extern SceneManager scene_manager;

class MenuScene :public Scene  //MenuScene类继承自Scene基类
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		std::cout << "1" << std::endl;
	}
	void on_update()
	{
		std::cout << "主菜单正在运行..." << std::endl;
	}
	void on_draw()
	{
		outtextxy(10, 10, _T("主菜单绘图内容"));
	}
	void on_input(const ExMessage& msg)
	{
		if (msg.message==WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}
	void on_exit()
	{
		std::cout << "主菜单退出" << std::endl;
	}

private:
	
};