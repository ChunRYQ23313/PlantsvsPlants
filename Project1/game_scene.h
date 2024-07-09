#pragma once
#include"Scene.h"
#include<iostream>
#include"scene_manager.h"

extern SceneManager scene_manager;

class GameScene :public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter()
	{
		std::cout << "������Ϸ������Ϸ����" << std::endl;
	}
	void on_update()
	{
		std::cout << "��Ϸ��������..." << std::endl;
	}
	void on_draw()
	{
		outtextxy(10, 10, _T("��Ϸ���ڻ�ͼ����"));
	}

	void on_input(const ExMessage& msg)
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}
	}

	void on_exit()
	{
		std::cout << "��Ϸ�����˳�" << std::endl;
	}

private:

};