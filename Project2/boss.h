//�ϰ����ļ�
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showIfo();

	//��ȡ������Ϣ
	virtual string getDeptName();
};
