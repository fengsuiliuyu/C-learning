#include "manager.h"
//���캯��
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = dId;
}

//��ʾ������Ϣ
void Manager::showIfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:���ο��庰���ͱ�үү" << endl;
}

//��ȡ������Ϣ
string  Manager::getDeptName()
{
	return string("����");
}