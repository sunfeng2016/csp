/*
201809-2
2019.3.3
*/

#include <iostream>
using namespace std;
#include <memory.h>

int Point[1000001];

int main()
{
    int a,b;
    int n;
    int i,j;
    int time = 0;
    memset(Point,0,sizeof(Point));
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> a >> b;
        for(j = a;j < b;j++)
            Point[j] = 1;
    }
    for(i = 0;i < n;i++)
    {
        cin >> a >> b;
        for(j = a;j < b;j++)
        {
            if(Point[j] == 1)
                time++;
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}
