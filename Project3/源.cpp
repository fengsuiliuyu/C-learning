#include <iostream>
using namespace std;
#include<string.h>
int main()
{
	string a;
	cout << "除了1以外的任何输入都会被跳过，请输入：" << endl;
	cin >> a;
	if (a.compare("1"))
	{
		cout << "1都能打歪来！" << endl;
	}

	system("pause");
	return 0;
}