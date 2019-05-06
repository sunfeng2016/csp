/*
201709-1
Ëï·å
*/

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 0;
    count += (N / 50) * 7;
    N = N % 50;
    count += (N / 30) * 4;
    N = N % 30;
    count += (N / 10);
    cout << count << endl;
    system("pause");
    return 0;
}