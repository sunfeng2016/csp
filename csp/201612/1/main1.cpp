/*
201612-1
Ëï·å
*/

#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    int array[1000];
    int n;
    cin >> n;
    int i,j;
    int mid;
    for(i = 0;i < n;i++)
        cin >> array[i];
    sort(array,array+n);
    mid = n/2;
    i = mid;
    j = mid;
    while(array[i] == array[mid])
        i--;
    while(array[j] == array[mid])
        j++;
    if(i + 1 == n - j)
        cout << array[mid] << endl;
    else
        cout << -1 << endl;
    system("pause");
    return 0;
}