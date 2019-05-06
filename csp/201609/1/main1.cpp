/*
201609-1
*/

#include <iostream>
using namespace std;
#include <math.h>

int main()
{
    int price[1000];
    int n;
    int i;
    int max = 0;
    cin >> n;
    cin >> price[0];
    for(i = 1;i < n;i++)
    {
        cin >> price[i];
        if(max < abs(price[i] - price[i-1]))
            max = abs(price[i] - price[i-1]);
    }
    cout << max << endl;
    system("pause");
    return 0;
}