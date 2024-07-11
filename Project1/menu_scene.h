#pragma once
#include"Scene.h"
#include<iostream>
#include"scene_manager.h"
#include"animation.h"

extern SceneManager scene_manager;

extern Atlas atlas_peashooter_run_right;

class MenuScene :public Scene  //MenuScene类继承自Scene基类
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);
		animation_peashooter_run_right.set_interval(300);
		animation_peashooter_run_right.set_loop(true);
		animation_peashooter_run_right.set_callback(
			[]()
			{
				scene_manager.switch_to(SceneManager::SceneType::Game);
			}
	        );
	}
	void on_update(int delta)
	{
		animation_peashooter_run_right.on_update(delta);
	}
	void on_draw()
	{
		animation_peashooter_run_right.on_draw(100, 100);
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
	Animation animation_peashooter_run_right;
};