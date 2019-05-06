/*
201812-1
2019.3.3
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    int r,y,g;
    int k,t;
    int time = 0;
    cin >> r >> y >> g;
    cin >> n;
    for(int i = 0; i < n; i++)
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