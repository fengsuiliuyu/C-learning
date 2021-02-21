#include<iostream>
using namespace std;
#include <string>
#define Max 1000
//�����ϵ�˽ṹ��
struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
//���ͨѶ¼�ṹ��
struct addressbooks 
{
	struct Person personarray[Max];
	int m_size;
};

//1.�����ϵ��
void addperson(addressbooks* absm)
{
	if (absm->m_size == Max)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		absm->personarray[absm->m_size].m_name = name;
		//����Ա�
		cout << "�������Ա�" << endl;
		cout << "1.��" << endl;
		cout << "2.Ů" << endl;
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
				cout << "������������������" << endl;
			}
		}
		//�������
		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age <=100)
			{
				absm->personarray[absm->m_size].m_age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		//��ӵ绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		absm->personarray[absm->m_size].m_phone = phone;
		//����סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		absm->personarray[absm->m_size].m_addr = address;
		//����ͨѶ¼����
		absm->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}
}
//2.��ʾ��ϵ��
void showperson(addressbooks* absm)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (absm->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < absm->m_size; i++)
		{
			cout << "������" << absm->personarray[i].m_name<<"\t";
			cout << "�Ա�" << (absm->personarray[i].m_sex==1?"��":"Ů") << "\t";
			cout << "���䣺" << absm->personarray[i].m_age << "\t";
			cout << "�绰��" << absm->personarray[i].m_phone << "\t";
			cout << "סַ��" << absm->personarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//3.ɾ����ϵ���ȼ����ϵ���Ƿ����
int isexist(addressbooks*absm,string name)
{
	for (int i = 0; i < absm->m_size; i++)
	{
		//�ҵ��û�����
		if (absm->personarray[i].m_name == name)
		{
			return i;//�ҵ������ڵ��±�
		}
	}
	return -1;//��û���ҵ�
}
//3.ɾ��ָ������ϵ��
void deleteperson(addressbooks* absm)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//ret = -1  δ�鵽
	//ret != -1  �鵽��
	int ret=isexist(absm, name);
	if (ret == -1)
	{
		cout << "δ�鵽����" << endl;
	}
	else
	{
		cout << "��ɾ��" << endl;
		for (int i = ret; i < absm->m_size; i++)
		{
			absm->personarray[i] = absm->personarray[i + 1];
		}
		absm->m_size--;//����ͨѶ¼�е�����
	}
	system("pause");
	system("cls");
}
//4.����ָ����ϵ�˵���Ϣ
void findperson(addressbooks* absm)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ���ͨѶ¼��
	int ret = isexist(absm, name);
	if (ret != -1)//�ҵ�����ϵ��
	{
		cout << "������" << absm->personarray[ret].m_name << "\t";
		cout << "�Ա�" << (absm->personarray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << absm->personarray[ret].m_age << "\t";
		cout << "�绰��" << absm->personarray[ret].m_phone << "\t";
		cout << "סַ��" << absm->personarray[ret].m_addr << "\t" ;
	}
	else//δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//5.�޸���ϵ��
void modifyperson(addressbooks* absm)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(absm, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "��������ȷ������" << endl;
		cin >> name;
		absm->personarray[ret].m_name = name;
		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
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
				cout << "������������������" << endl;
			}
		}
		//����
		cout << "���������䣺"<<endl;
		int age = 0;
		cin >> age;
		absm->personarray[ret].m_age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		absm->personarray[ret].m_phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		absm->personarray[ret].m_addr = address;


	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//6.�����ϵ��
void cleanperson(addressbooks* absm)
{
	cout << "�Ƿ�ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.��ȷ��" << endl;
	int choice = 0;
	cin >> choice;
	while (true)
	{
		if (choice == 1)
		{
			absm->m_size = 0;
			cout << "ͨѶ¼�����" << endl;
			break;
		}
		else if(choice==2)
		{
			cout << "���˳�ѡ��" << endl;
			break;
		}
		else
		{
			cout << "�����������������" << endl;
			cin >> choice;
		}
	}
	system("pause");
	system("cls");
}
void showmenu() 
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳���ϵ��  *****" << endl;
	cout << "**************************" << endl;
}
int main()
{
	addressbooks absm;
	absm.m_size = 0;
	int select = 0;//�����û�ѡ������ı���
	//�˵�����
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://1.�����ϵ��
			addperson(&absm);
			break;
		case 2://2.��ʾ��ϵ��
			showperson(&absm);
			break;
		case 3://3.ɾ����ϵ��
			deleteperson(&absm);
			break;
		case 4://4.������ϵ��
			findperson(&absm);
			break;
		case 5://5.�޸���ϵ��
			modifyperson(&absm);
			break;
		case 6://6.�����ϵ��
			cleanperson(&absm);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}