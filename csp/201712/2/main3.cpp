/******************************
 * About: csp 20171202 ÓÎÏ·
 * Author: Ëï·å
 * Date: 2019-3-16
 ******************************/
#include <iostream>
using namespace std;
#include <memory.h>

#define MAX_N 1001

int main()
{
	int children[MAX_N];
	int n;
	int i;
	int k;
	int count;
	int num = 0;
	int index = -1;
	cin >> n >> k;
	count = n;
	memset(children,0,sizeof(children));
	while(count > 1)
	{
		num++;
		index = (index + 1) % n;
		while(children[index])
			index = (index + 1) % n;
		if(num % k == 0 || num % 10 == k)
		{
			children[index] = 1;
			count--;
		}
	} 
	for(i = 0;i < n;i++)
	{
		if(children[i] == 0)
		{
			cout << i + 1 << endl;
			break;
		}
	}
	system("pause");
	return 0;
}