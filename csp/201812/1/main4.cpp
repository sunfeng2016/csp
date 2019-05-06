#include <iostream>
using namespace std;
#include <stdlib.h>

int main()
{
    int r,g,y;
    int k,t;
    int time = 0;
    int i;
    int n;
    cin >> r >> y >> g;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> k >> t;
        if(k == 0)
            time += t;
        else if(k == 1)
            time += t;
        else if(k == 2)
            time += (t + r);
        else
            continue;
    }
    cout << time << endl;
    system("pause");
    return 0;
}