#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流的头文件
using namespace std;//使用标准命名空间
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class Workermanager
{
public:
	//构造函数
	Workermanager();

	//展示菜单
	void Showmenu();

	//退出菜单
	void Exitsystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存职工信息
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化数组
	void init_Emp();

	//显示职工
	void Show_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~Workermanager();


};


