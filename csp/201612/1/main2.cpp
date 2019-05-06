/*
201612-1
2019.3.3
*/

#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    int Array[1000];
    int n;
    int i,j;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> Array[i];
    }
    sort(Array,Array + n);
    int mid = n / 2;
    i = mid;
    j = mid;
    while(Array[i] == Array[mid])
        i--;
    while(Array[j] == Array[mid])
        j++;
    if(i + 1 == n - j)
    {
        cout << Array[mid] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    system("pause");
    return 0;
}