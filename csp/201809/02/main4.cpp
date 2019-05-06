/***********************************
 * About: CSP 201809-2 Âò²Ë
 * Author: sunfeng
 * Date: 2019-3-15
 ***********************************/

#include <iostream>
using namespace std;
#include <memory.h>

#define MAX 1000001
int Point[MAX];

int main()
{
    int n;
    int p,q;
    int i,j;
    int time = 0;
    memset(Point,0,sizeof(Point));
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        cin >> p >> q;
        for(j = p; j < q;j++)
            Point[j] = 1;
    }
    for(i = 1;i <= n;i++)
    {
        cin >> p >> q;
        for(j = p;j < q;j++)
        {
            if(Point[j] == 1)
                time++;
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}
