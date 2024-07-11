#pragma once
#include"Scene.h"
#include<iostream>
#include"scene_manager.h"
#include"animation.h"
#include"camera.h"
#include"timer.h"

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
		animation_peashooter_run_right.set_interval(75);
		animation_peashooter_run_right.set_loop(true);

		timer.set_wait_time(1000);
		timer.set_one_shot(false);
		timer.set_callback([]()
			{
				std::cout << "Shot!" << std::endl;
			});
	}
	void on_update(int delta)
	{
		timer.on_update(delta);
		camera.on_update(delta);
		animation_peashooter_run_right.on_update(delta);
	}
	void on_draw()
	{
		const Vector2& pos_camera = camera.get_position();
		animation_peashooter_run_right.on_draw((int)(100-pos_camera.x),(int)(100-pos_camera.y));
	}
	void on_input(const ExMessage& msg)
	{
		if (msg.message==WM_KEYDOWN)
		{
			camera.shake(10,350);
		}
	}
	void on_exit()
	{
		std::cout << "主菜单退出" << std::endl;
	}

private:
	Animation animation_peashooter_run_right;
	Camera camera;
	Timer timer;
};