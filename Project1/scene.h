#pragma once
#include<graphics.h>

class Scene
{
public:
	Scene() = default;
	~Scene() = default;
	//��Ա����
	virtual void on_enter() {}                                  // ��������ʱ�ĳ�ʼ���߼�
	virtual void on_update() {}                                  //��������
	virtual void on_draw() {}                                     //��Ⱦ��ͼ
	virtual void on_input(const ExMessage& msg) {}//�����������
	virtual void on_exit() {}                                    //�����˳�ʱ��ж���߼�



private:


};