#include "manager.h"
//构造函数
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = dId;
}

//显示个人信息
void Manager::showIfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:让任俊峰喊孙贤兵爷爷" << endl;
}

//获取个人信息
string  Manager::getDeptName()
{
	return string("经理");
}