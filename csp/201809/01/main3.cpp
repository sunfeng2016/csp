/***********************************
 About:csp 201809-1Âô²Ë
 Author:woxiang
 **********************************/
#include <iostream>
using namespace std;

#define MAX_N 1001
int Price[MAX_N];

int main()
{
    int i;
    int N;
    cin >> N;
    for(i = 1;i <= N;i++)
        cin >> Price[i];
    cout << (Price[1] + Price[2]) / 2 << " ";
    for(i = 2;i < N;i++)
        cout << (Price[i - 1] + Price[i] + Price[i + 1]) / 3 << " ";
    cout << (Price[N -1] + Price[N]) / 2 << endl;
    system("pause");
    return 0;
}