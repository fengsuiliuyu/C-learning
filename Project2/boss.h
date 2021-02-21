//老板类文件
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Boss :public Worker
{
public:
	//构造函数
	Boss(int id, string name, int dId);

	//显示个人信息
	virtual void showIfo();

	//获取个人信息
	virtual string getDeptName();
};
