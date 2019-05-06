/*
201809-1
孙峰
*/
#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
	int n;
	int Price[1001];
	int i;
	cin >> n;
	for(i = 1;i <= n;i++)
	{
		cin >> Price[i];
	}	
	cout << (Price[1] + Price[2]) / 2 << " ";
	for(i = 2;i <= n-1;i++)
	{
		cout << (Price[i-1] + Price[i] + Price[i+1]) / 3 << " ";
	}
	cout << (Price[n-1] + Price[n]) / 2;
	system("pause");
	return 0;
} 
