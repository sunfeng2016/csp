/*
201604-2
*/

#include <iostream>
using namespace std;

int a[19][10];
int b[4][4];

bool compareblock(int r,int c)
{
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(b[i][j] == 1 && a[i + r][j +c] == 1)
                return true;
        }
    }
    return false;
}

int main()
{
    int i,j;
    int n;
    int mark;
    for(i = 0;i < 15;i++)
    {
        for(j = 0;j < 10;j++)
        {
            cin >> a[i][j];
        }
    }
    for(i = 15;i < 19;i++)
    {
        for(j = 0;j < 10;j++)
        {
            a[i][j] = 1;
        }
    }
    for(i = 0; i < 4;i++)
    {
        for(j = 0;j < 4;j++)
        {
            cin >> b[i][j];
        }
    }
    cin >> n;
    for(i = 0;i < 15;i++)
    {
        if(compareblock(i,n-1))
            break;
        mark = i;
    }
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j <4;j++)
        {
            if(b[i][j] == 1)
            {
                a[i + mark][j + n-1] = 1;
            }
        }
    }
    for(i = 0;i < 15;i++)
    {
        for(j = 0;j < 10;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}