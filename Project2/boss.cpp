#include "boss.h"
//构造函数
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = dId;
}

//显示个人信息
void Boss::showIfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:让倪习伟喊孙贤兵爷爷" << endl;
}

//获取个人信息
string  Boss::getDeptName()
{
	return string("老板");
}