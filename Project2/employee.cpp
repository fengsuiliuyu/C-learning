#include "employee.h"
//���캯��
Employee::Employee(int id,string name,int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = dId;
}

//��ʾ������Ϣ
void Employee::showIfo()
{
	cout << "ְ����ţ�" << this->m_id
		 << "\tְ��������" << this->m_name
		 << "\t��λ:" << this->getDeptName()
		 << "\t��λְ��:�ù�ǿ�����ͱ�үү" << endl;
}

//��ȡ������Ϣ
string  Employee::getDeptName()
{
	return string("Ա��");
}
