/*
201803-2
2019.3.3
*/

#include <iostream>
using namespace std;

int locations[101];
int directions[101];

int main()
{
    int i,j,k;
    int n,L,t;
    cin >> n >> L >> t;
    for(i = 1;i <= n;i++)
    {
        cin >> locations[i];
        directions[i] = 1;
    }
    for(k = 1;k <= t;k++)
    {
        for(j = 1;j <= n;j++)
        {
            locations[j] += directions[j];
            if(locations[j] == L || locations[j] == 0)
                directions[j] = 0 - directions[j];
        }
        for(i = 1;i <= n;i++)
        {
            for(j = 1;j <= n;j++)
            {
                if(locations[i] == locations[j])
                {
                    directions[i] = 0 - directions[i];
                    directions[j] = 0 - directions[j];
                    break;
                }
            }
        }
    }
    for(i = 1;i <= n;i++)
        cout << locations[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}