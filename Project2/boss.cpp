#include "boss.h"
//���캯��
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = dId;
}

//��ʾ������Ϣ
void Boss::showIfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:����ϰΰ�����ͱ�үү" << endl;
}

//��ȡ������Ϣ
string  Boss::getDeptName()
{
	return string("�ϰ�");
}