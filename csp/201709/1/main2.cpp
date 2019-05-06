#include <iostream>
using namespace std;

int main()
{
    int N;
    int num = 0;
    cin >> N;
    num += (N / 50) * 7;
    N = N % 50;
    num += (N / 30) * 4;
    N = N % 30;
    num += (N / 10);
    cout << num << endl;
    system("pause");
    return 0;
}