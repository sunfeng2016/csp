/**********************
 * About: csp201809-1 Âô²Ë
 * Author: Ëï·å
 * Date: 2019-3-15
 **********************/

#include <iostream>
using namespace std;

#define MAX_N 1001
int Price[MAX_N];

int main()
{
    int n;
    int i;
    cin >> n;
    for(i = 1;i <= n;i++)
        cin >> Price[i];
    cout << (Price[1] + Price[2]) / 2 << " ";
    for(i = 2;i < n;i++)
        cout << (Price[i-1] + Price[i] + Price[i+1]) / 3 << " ";
    cout << (Price[n-1] + Price[n]) / 2 << endl;
    system("pause");
    return 0;
}