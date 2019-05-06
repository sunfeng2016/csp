/*
201712-2
Ëï·å
*/

#include <iostream>
using namespace std;
#include <memory.h>

int main()
{
    int n,k;
    int i;
    int index = -1;
    int count = 0;
    int children[1000];
    cin >> n >> k;
    int num = n;
    memset(children,0,sizeof(children));
    while(num > 1){
        index = (index + 1) % n;
        while(children[index] == 1)
            index = (index + 1) % n;
        count++;
        if(count % 10 == k || count % k == 0)
        {
            children[index] = 1;
            num--;
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