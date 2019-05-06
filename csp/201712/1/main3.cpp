/******************************************
 * About: csp 201712-1 ×îÐ¡²îÖµ 
 * Author: sunfeng
 * Date: 2019-3-16
 ******************************************/

#include <iostream>
using namespace std;
#include <algorithm>

#define MAX_N 1001
#define INFINITY INT_MAX

int main()
{
    int n;
    int Array[MAX_N];
    int i;
    int min = INFINITY;
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        cin >> Array[i];
    }
    sort(Array + 1, Array + 1 + n);
    for(i = 2;i <= n;i++)
    {
        if(min > (Array[i] - Array[i-1]))
            min = Array[i] - Array[i-1];
    }
    cout << min << endl;
    system("pause");
    return 0;
}