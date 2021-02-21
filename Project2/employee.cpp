#include "employee.h"
//构造函数
Employee::Employee(int id,string name,int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = dId;
}

//显示个人信息
void Employee::showIfo()
{
	cout << "职工编号：" << this->m_id
		 << "\t职工姓名：" << this->m_name
		 << "\t岗位:" << this->getDeptName()
		 << "\t岗位职责:让郭强喊孙贤兵爷爷" << endl;
}

//获取个人信息
string  Employee::getDeptName()
{
	return string("员工");
}
