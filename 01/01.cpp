#include<iostream>
using namespace std;
#include <string>
#define Max 1000
//设计联系人结构体
struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
//设计通讯录结构体
struct addressbooks 
{
	struct Person personarray[Max];
	int m_size;
};

//1.添加联系人
void addperson(addressbooks* absm)
{
	if (absm->m_size == Max)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		absm->personarray[absm->m_size].m_name = name;
		//添加性别
		cout << "请输入性别：" << endl;
		cout << "1.男" << endl;
		cout << "2.女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				absm->personarray[absm->m_size].m_sex = sex;
				break;
			}
			else 
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//添加年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age <=100)
			{
				absm->personarray[absm->m_size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//添加电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		absm->personarray[absm->m_size].m_phone = phone;
		//输入住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		absm->personarray[absm->m_size].m_addr = address;
		//更新通讯录人数
		absm->m_size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}
//2.显示联系人
void showperson(addressbooks* absm)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (absm->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < absm->m_size; i++)
		{
			cout << "姓名：" << absm->personarray[i].m_name<<"\t";
			cout << "性别：" << (absm->personarray[i].m_sex==1?"男":"女") << "\t";
			cout << "年龄：" << absm->personarray[i].m_age << "\t";
			cout << "电话：" << absm->personarray[i].m_phone << "\t";
			cout << "住址：" << absm->personarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//3.删除联系人先检测联系人是否存在
int isexist(addressbooks*absm,string name)
{
	for (int i = 0; i < absm->m_size; i++)
	{
		//找到用户姓名
		if (absm->personarray[i].m_name == name)
		{
			return i;//找到了所在的下标
		}
	}
	return -1;//并没有找到
}
//3.删除指定的联系人
void deleteperson(addressbooks* absm)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	//ret = -1  未查到
	//ret != -1  查到了
	int ret=isexist(absm, name);
	if (ret == -1)
	{
		cout << "未查到此人" << endl;
	}
	else
	{
		cout << "已删除" << endl;
		for (int i = ret; i < absm->m_size; i++)
		{
			absm->personarray[i] = absm->personarray[i + 1];
		}
		absm->m_size--;//更新通讯录中的人数
	}
	system("pause");
	system("cls");
}
//4.查找指定联系人的信息
void findperson(addressbooks* absm)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否在通讯录中
	int ret = isexist(absm, name);
	if (ret != -1)//找到了联系人
	{
		cout << "姓名：" << absm->personarray[ret].m_name << "\t";
		cout << "性别：" << (absm->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << absm->personarray[ret].m_age << "\t";
		cout << "电话：" << absm->personarray[ret].m_phone << "\t";
		cout << "住址：" << absm->personarray[ret].m_addr << "\t" ;
	}
	else//未找到联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5.修改联系人
void modifyperson(addressbooks* absm)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(absm, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入正确姓名：" << endl;
		cin >> name;
		absm->personarray[ret].m_name = name;
		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
		cin >> sex;

		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				absm->personarray[ret].m_sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄："<<endl;
		int age = 0;
		cin >> age;
		absm->personarray[ret].m_age = age;
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		absm->personarray[ret].m_phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		absm->personarray[ret].m_addr = address;


	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//6.清空联系人
void cleanperson(addressbooks* absm)
{
	cout << "是否确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.不确定" << endl;
	int choice = 0;
	cin >> choice;
	while (true)
	{
		if (choice == 1)
		{
			absm->m_size = 0;
			cout << "通讯录已清空" << endl;
			break;
		}
		else if(choice==2)
		{
			cout << "已退出选择" << endl;
			break;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			cin >> choice;
		}
	}
	system("pause");
	system("cls");
}
void showmenu() 
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出联系人  *****" << endl;
	cout << "**************************" << endl;
}
int main()
{
	addressbooks absm;
	absm.m_size = 0;
	int select = 0;//创建用户选择输入的变量
	//菜单调用
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addperson(&absm);
			break;
		case 2://2.显示联系人
			showperson(&absm);
			break;
		case 3://3.删除联系人
			deleteperson(&absm);
			break;
		case 4://4.查找联系人
			findperson(&absm);
			break;
		case 5://5.修改联系人
			modifyperson(&absm);
			break;
		case 6://6.清空联系人
			cleanperson(&absm);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}