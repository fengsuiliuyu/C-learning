#include <iostream>
using namespace std;
#include<string.h>
int main()
{
	string a;
	string b;
	while (True)
	{
		cout << "除了1以外的任何输入都会被跳过，请输入：" << endl;
		cin >> a;
		if (a == '1')
		{
			cout << "好！输入0退出程序" << end;
		}
		else
		{
			cout << "1都能输歪来，拉跨！" << endl << "再来！或者按0退出！" << endl;
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