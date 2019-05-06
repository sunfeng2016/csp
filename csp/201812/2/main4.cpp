#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    long long lights[3];
    int k;
    long long t;
    long long time = 0;
    int n;
    int i;
    long long sum;
    cin >> lights[0] >> lights[2] >> lights[1];
    sum  = lights[0] + lights[1] + lights[2];
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        cin >> k >> t;
        if(k == 0)
            time += t;
        else
        {
            if(k == 1)
                k = 0;
            else if(k == 3)
                k = 1;
            t = lights[k] - t;
            t += time;
            t %= sum;
            while(t > lights[k])
            {
                t -= lights[k];
                k = (k + 1) % 3;
            }
            t = lights[k] - t;
            if(k == 0)
                time += t;
            else if(k == 2)
                time += (t + lights[0]);
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}