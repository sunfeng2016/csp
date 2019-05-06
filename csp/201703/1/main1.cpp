/*
201703-1
Ëï·å
*/

#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int n,k;
    int weight = 0;
    int ai;
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> ai;
        weight += ai;
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
