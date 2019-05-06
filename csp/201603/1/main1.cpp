/*
201604-1
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    int i;
    int Array[1000];
    cin >> n;
    int count = 0;
    for(i = 0;i < n;i++)
    {
        cin >> Array[i];
    }
    for(i = 1;i < n;i++)
    {
        Array[i-1] = Array[i] - Array[i-1];
    }
    for(i = 1;i < n-1;i++)
    {
        if(Array[i-1] * Array[i] < 0)
            count++;
    }
    cout << count << endl;
    system("pause");
    return 0;
}