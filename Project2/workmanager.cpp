#include "workmanager.h"

Workermanager::Workermanager()
{
	//��ʼ������
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ�Ϊ���ļ�
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ���ļ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ������Ҳ�Ϊ��,��¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];//����ְ������������
	init_Emp();//��ʼ��ְ��
}


void Workermanager::Showmenu()
{
	cout << "************************************" << endl;
	cout << "********��ӭʹ��ְ������ϵͳ********" << endl;
	cout << "*********0.�˳��������*************" << endl;
	cout << "*********1.����ְ����Ϣ*************" << endl;
	cout << "*********2.��ʾְ����Ϣ*************" << endl;
	cout << "*********3.ɾ����ְְ��*************" << endl;
	cout << "*********4.�޸�ְ����Ϣ*************" << endl;
	cout << "*********5.����ְ����Ϣ*************" << endl;
	cout << "*********6.���ձ������*************" << endl;
	cout << "*********7.��������ĵ�*************" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void Workermanager::Exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��Ӻ���
void Workermanager::Add_Emp()
{
	cout << "���������Ա����������" << endl;
	int addNum = 0;
	while (true)
	{
		cin >> addNum;
		if (addNum > 0 && addNum < 10)
		{
			//���
			//��������¿ռ��С
			int newSize = this->m_EmpNum + addNum;

			//�����¿ռ�
			Worker** newSpace = new Worker * [newSize];

			//��ԭ���ռ������ݣ��������¿ռ���
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}

			//���������
			for (int i = 0; i < addNum; i++)
			{
				int id;//ְ�����
				string name;//ְ������
				int dSelect;//����ѡ�� 
				
				while (true)
				{
					cout << "�������" << i + 1 << "λ��ְ�����:" << endl;
					cin >> id;
					if (IsExist(id) == -1)
					{
						break;
					}
					else
					{
						cout << "�˱���ѱ�ʹ�á�" << endl;
					}
				}
				cout << "�������" << i + 1 << "λ��ְ������:" << endl;
				cin >> name;
				cout << "��ѡ���ְ����λ" << endl;
				cout << "1.��ְͨ��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				while (true)
				{
					cin >> dSelect;
					if (dSelect == 1 || dSelect == 2 || dSelect == 3)
					{
						break;
					}
					else
					{
						cout << "���滨���ˣ���ү�������룡" << endl;
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
				//��������ְ�����ݣ����浽������
				newSpace[this->m_EmpNum + i] = worker;


			}
			//�ͷ�ԭ�еĿռ�
			delete[]this->m_EmpArray;
			
			//�����¿ռ��ָ��
			this->m_EmpArray = newSpace;
			
			//�����µ�ְ������
			this->m_EmpNum = newSize;
			
			//����ְ����Ϊ�ձ�־
			this->m_FileIsEmpty = false;

			//��ʾ��ӳɹ�
			cout << "�ɹ����" << addNum << "����ְ��" << endl;
			
			//�������ݽ����ļ�
			this->save();
			system("pause");
			break;
		}
		else
		{
			cout << "wdnmd,�������Ķ���" << endl;
			cout << "�������������룬10������tm�����ִ�����" << endl;
		}
	}
	
}

//���溯��
void Workermanager::save()
{
	//���ļ�
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ������
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
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ������
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
		//���ݲ�ͬ���Ŵ�����ͬ����
		if (dId == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		if (dId == 3)//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

//չʾ����
void Workermanager::Show_Emp()
{
	//�ж��ļ��Ƿ񲻴��ڻ���Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showIfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����,�����ض�������λ��
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

//ɾ��ְ��
void Workermanager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)//ְ�����ڣ�����ɾ�������Ӧλ��
		{
			for (int i = index; i < this->m_EmpNum - 1;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;//���������м�¼��Ա����
			this->save();//����ͬ�����µ��ļ���
			cout << "ɾ���ɹ���" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ����޴��ˡ�" << endl;
		}

	}
	if (m_EmpNum == 0)
	{
		this->m_FileIsEmpty = true;
	}
	system("pause");
	system("cls");
     
}

//�޸�ְ����Ϣ
void Workermanager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = " ";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ������������ְ����" << endl;
			while (true)
			{
				cout << "������������ְ�����:" << endl;
				cin >> id;
				if (IsExist(id) == -1)
				{
					break;
				}
				else
				{
					cout << "�˱���ѱ�ʹ�á�" << endl;
				}
			}
			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			while (true)
			{
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3)
				{
					break;
				}
				else
				{
					cout << "ү��������������ɣ�" << endl;
				}
			}
			Worker* worker = NULL;
			if (dSelect == 1)//��ͨԱ��
			{
				worker = new Employee(id, newName, dSelect);
			}
			if (dSelect == 2)//����
			{
				worker = new Manager(id, newName, dSelect);
			}
			if (dSelect == 3)//�ϰ�
			{
				worker = new Boss(id, newName, dSelect);
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˡ�" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//����ְ��
void Workermanager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)//����Ų���
		{
			int id = 0;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showIfo();
			}
			else
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else if (select == 2)//����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			bool flag = false;//���ҳɹ����ı�־
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						 << m_EmpArray[i]->m_id
						 << "�ŵ���Ϣ���£�" << endl;
					flag = true;
					this->m_EmpArray[i]->showIfo();
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ѡ�������޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "�ⶼ����������������������" << endl;
		}
	}
	//���������
	system("pause");
	system("cls");
}

//����ְ��
void Workermanager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1.��ְ����Ž�������" << endl;
		cout << "2.��ְ����Ž��н���" << endl;
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
				cout << "ү����˵�����ö���������һ�Σ�" << endl;
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
		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}
}

//����ļ�
void Workermanager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

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
			cout << "ү����˵�����ö���������һ�Σ�" << endl;
		}
	}
	if (select == 1)
	{
		//���ļ���ɾ��
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
		cout << "��ճɹ���" << endl;
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
