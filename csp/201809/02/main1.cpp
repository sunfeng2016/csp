#include <iostream>
using namespace std;
#include <memory.h>

int Array[1000001];

int main()
{
    int a,b,n;
    int time = 0;
    int i,j;
    memset(Array,0,sizeof(Array));
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> a >> b;
        for(j = a; j < b; j++)
            Array[j] = 1;
    }
    for(i = 0;i < n;i++)
    {
        cin >> a >> b;
        for(j = a; j < b; j++)
        {
            if(Array[j] == 1)
                time++;
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}