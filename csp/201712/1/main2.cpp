/*
201812-1
2019.3.3
*/

#include <iostream>
using namespace std;
#include <algorithm>

int numbers[1001];

int main()
{
    int n;
    int i;
    int min = 10000;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> numbers[i];
    }
    sort(numbers,numbers + n);
    for(i = 1;i < n;i++)
    {
        if(min > numbers[i] - numbers[i-1])
            min = numbers[i] - numbers[i-1];
    }
    cout << min << endl;
    system("pause");
    return 0;
}