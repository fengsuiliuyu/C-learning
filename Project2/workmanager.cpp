#include "workmanager.h"

Workermanager::Workermanager()
{
	//初始化属性
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件为空文件
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空文件" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在且不为空,记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];//根据职工数创建数据
	init_Emp();//初始化职工
}


void Workermanager::Showmenu()
{
	cout << "************************************" << endl;
	cout << "********欢迎使用职工管理系统********" << endl;
	cout << "*********0.退出管理程序*************" << endl;
	cout << "*********1.增加职工信息*************" << endl;
	cout << "*********2.显示职工信息*************" << endl;
	cout << "*********3.删除离职职工*************" << endl;
	cout << "*********4.修改职工信息*************" << endl;
	cout << "*********5.查找职工信息*************" << endl;
	cout << "*********6.按照编号排序*************" << endl;
	cout << "*********7.清空所有文档*************" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

//退出系统
void Workermanager::Exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加函数
void Workermanager::Add_Emp()
{
	cout << "请输入添加员工的数量：" << endl;
	int addNum = 0;
	while (true)
	{
		cin >> addNum;
		if (addNum > 0 && addNum < 10)
		{
			//添加
			//计算添加新空间大小
			int newSize = this->m_EmpNum + addNum;

			//开辟新空间
			Worker** newSpace = new Worker * [newSize];

			//将原来空间下数据，拷贝到新空间下
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}

			//添加新数据
			for (int i = 0; i < addNum; i++)
			{
				int id;//职工编号
				string name;//职工名称
				int dSelect;//部门选择 
				
				while (true)
				{
					cout << "请输入第" << i + 1 << "位新职工编号:" << endl;
					cin >> id;
					if (IsExist(id) == -1)
					{
						break;
					}
					else
					{
						cout << "此编号已被使用。" << endl;
					}
				}
				cout << "请输入第" << i + 1 << "位新职工姓名:" << endl;
				cin >> name;
				cout << "请选择该职工岗位" << endl;
				cout << "1.普通职工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				while (true)
				{
					cin >> dSelect;
					if (dSelect == 1 || dSelect == 2 || dSelect == 3)
					{
						break;
					}
					else
					{
						cout << "别玩花的了，给爷重新输入！" << endl;
					}


				}


				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
				}
				//将创建的职工数据，保存到数组中
				newSpace[this->m_EmpNum + i] = worker;


			}
			//释放原有的空间
			delete[]this->m_EmpArray;
			
			//更改新空间的指向
			this->m_EmpArray = newSpace;
			
			//更新新的职工人数
			this->m_EmpNum = newSize;
			
			//更新职工不为空标志
			this->m_FileIsEmpty = false;

			//提示添加成功
			cout << "成功添加" << addNum << "名新职工" << endl;
			
			//保存数据进入文件
			this->save();
			system("pause");
			break;
		}
		else
		{
			cout << "wdnmd,输点阳间的东西" << endl;
			cout << "给老子重新输入，10以外你tm不把手打歪来" << endl;
		}
	}
	
}

//保存函数
void Workermanager::save()
{
	//打开文件
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}

	//关闭文件
	ofs.close();
}

//统计人数
int Workermanager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

//初始化数组
void Workermanager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dId;
	
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//根据不同部门创建不同对象
		if (dId == 1)//普通员工
		{
			worker = new Employee(id, name, dId);
		}
		if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		if (dId == 3)//老板
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

//展示函数
void Workermanager::Show_Emp()
{
	//判断文件是否不存在或者为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showIfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}

//判断职工是否存在,并返回对于数组位置
int Workermanager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			break;
		}

	}
	return index;

}

//删除职工
void Workermanager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)//职工存在，并且删除数组对应位置
		{
			for (int i = index; i < this->m_EmpNum - 1;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;//更新数组中记录人员个数
			this->save();//数据同步更新到文件中
			cout << "删除成功！" << endl;

		}
		else
		{
			cout << "删除失败，查无此人。" << endl;
		}

	}
	if (m_EmpNum == 0)
	{
		this->m_FileIsEmpty = true;
	}
	system("pause");
	system("cls");
     
}

//修改职工信息
void Workermanager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = " ";
			int dSelect = 0;
			cout << "查到：" << id << "号职工，请输入新职工号" << endl;
			while (true)
			{
				cout << "请重新输入新职工编号:" << endl;
				cin >> id;
				if (IsExist(id) == -1)
				{
					break;
				}
				else
				{
					cout << "此编号已被使用。" << endl;
				}
			}
			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			while (true)
			{
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3)
				{
					break;
				}
				else
				{
					cout << "爷吐啦，阳间输入吧！" << endl;
				}
			}
			Worker* worker = NULL;
			if (dSelect == 1)//普通员工
			{
				worker = new Employee(id, newName, dSelect);
			}
			if (dSelect == 2)//经理
			{
				worker = new Manager(id, newName, dSelect);
			}
			if (dSelect == 3)//老板
			{
				worker = new Boss(id, newName, dSelect);
			}
			//更改数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;
			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人。" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//查找职工
void Workermanager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)//按编号查找
		{
			int id = 0;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showIfo();
			}
			else
			{
				cout << "查无此人！" << endl;
			}
		}
		else if (select == 2)//按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			bool flag = false;//查找成功与否的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功，职工编号为："
						 << m_EmpArray[i]->m_id
						 << "号的信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->showIfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "输入选项有误，无此人！" << endl;
			}
		}
		else
		{
			cout << "这都能输歪来，爬爬爬爬爬。" << endl;
		}
	}
	//任意键清屏
	system("pause");
	system("cls");
}

//排序职工
void Workermanager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式：" << endl;
		cout << "1.按职工编号进行升序" << endl;
		cout << "2.按职工编号进行降序" << endl;
		int select = 0;
		while (true)
		{
			cin >> select;
			if (select == 1 || select == 2)
			{
				break;
			}
			else
			{
				cout << "爷不多说，懂得都懂！再输一次！" << endl;
			}
		}
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minormax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (m_EmpArray[minormax]->m_id > m_EmpArray[j]->m_id)
					{
						minormax = j;
					}
				}
				else
				{
					if (m_EmpArray[minormax]->m_id < m_EmpArray[j]->m_id)
					{
						minormax = j;
					}
				}

			}
			if (i != minormax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minormax];
				m_EmpArray[minormax] = temp;
			}
		}
		cout << "排序成功，排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}

//清空文件
void Workermanager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1 || select == 2)
		{
			break;
		}
		else
		{
			cout << "爷不多说，懂得都懂！再输一次！" << endl;
		}
	}
	if (select == 1)
	{
		//打开文件并删除
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete []this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
	
}

Workermanager::~Workermanager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
