/*
201712-2
2019.3.3
*/

#include <iostream>
using namespace std;
#include <memory.h>

int children[1000];

int main()
{
    int n,k;
    cin >> n >> k;
    int count = n;
    int num = 0;
    int i;
    memset(children,0,sizeof(children));
    int index = -1;
    while(count > 1)
    {
        index = (index + 1) % n;
        while(children[index] == -1)
        {
            index = (index + 1) % n;
        }
        num++;
        if(num % k == 0 || num % 10 == k)
        {
            children[index] = -1;
            count--;
        }
    }
    for(i = 0;i < n;i++)
    {
        if(children[i] == 0)
            cout << i + 1 << endl;
    }
    system("pause");
    return 0;
} 