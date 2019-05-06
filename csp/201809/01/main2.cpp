#include <iostream>
using namespace std;

int main()
{
    int price[1000];
    int n;
    int i;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> price[i];
    }
    cout << (price[0] + price[1]) / 2 << " ";
    for(i = 1;i < n-1;i++)
    {
        cout << (price[i-1] + price[i] + price[i+1]) / 3 << " ";
    }
    cout << (price[n-2] + price[n-1]) / 2 << endl;
    system("pause");
    return 0;
}