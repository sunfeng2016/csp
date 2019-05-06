/*
201712-1
Ëï·å
*/

#include <iostream>
using namespace std;
#include <algorithm>

#define MAX 1000

int main()
{
    int data[MAX];
    int n;
    int i;
    int min = 10000;
    cin >> n;
    for(i = 0;i < n;i++)
        cin >> data[i];
    sort(data,data+n);
    for(i = 1;i < n;i++)
    {
        if(min > data[i] - data[i-1])
            min = data[i] - data[i-1];
    }
    cout << min << endl;
    system("pause");
    return 0;
}