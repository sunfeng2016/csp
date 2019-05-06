/*******************************
 About: csp201809-2 Âò²Ë
 Author: woxiang
 ******************************/

#include <iostream>
using namespace std;
#include <memory.h>

#define MAX_LEN 1000000
int Point[MAX_LEN];

int main()
{
    int N;
    int i,j;
    int p,q;
    cin >> N;
    int time = 0;
    memset(Point,0,sizeof(Point));
    for(i = 0;i < N;i++)
    {
        cin >> p >> q;
        for(j = p;j < q;j++)
            Point[j] = 1;
    }
    for(i = 0;i < N;i++)
    {
        cin >> p >> q;
        for(j = p;j < q;j++)
        {
            if(Point[j])
                time++;
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}