#include <iostream>
using namespace std;
#include "workmanager.h"
#include <string>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main()
{
	//���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showIfo();
	//delete worker;
	//
	//worker = new Manager(2, "����", 2);
	//worker->showIfo();
	//delete worker;

	//worker = new Boss(3, "����", 3);
	//worker->showIfo();
	//delete worker;


	//ʵ���������߶���
	Workermanager wm;
	int choice = 0;
	while (true)
	{
		//����չʾ�˵���Ա����
		wm.Showmenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0 ://�˳�ϵͳ
			wm.Exitsystem();
			break;
		case 1 ://���ְ��
			wm.Add_Emp();
			system("cls");
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_File();
			break;
		default:
			cout << "������ndm" << endl;
			system("pause");
			system("cls");
			break;
		}


	}

    system("pause");
	return 0;


}