#include <iostream>
using namespace std;
#include<string.h>
int main()
{
	string a;
	string b;
	while (True)
	{
		cout << "����1������κ����붼�ᱻ�����������룺" << endl;
		cin >> a;
		if (a == '1')
		{
			cout << "�ã�����0�˳�����" << end;
		}
		else
		{
			cout << "1���������������磡" << endl << "���������߰�0�˳���" << endl;
			cin >> b;
			if (b == '0')
			{
				break
			}
		}
	}
	system("pause");
	return 0;
}