#pragma once
#include<iostream>
using namespace std;
#include<string>

//ְ��������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showIfo() = 0;
	//��ȡ������Ϣ
	virtual string getDeptName() = 0;
	//ְ�����
	int m_id;
	//ְ������
	string m_name;
	//���ű��
	int m_DepId;
};
