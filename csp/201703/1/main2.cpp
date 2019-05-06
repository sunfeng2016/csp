/*
201703-1
2019.3.3
*/

#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int n,k;
    int a;
    int weight = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a;
        weight += a;
        if(weight >= k)
        {
            weight = 0;
            count++;
        }
    }
    if(weight != 0)
        count++;
    cout << count << endl;
    system("pause");
    return 0;
}