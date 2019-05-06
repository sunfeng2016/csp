/***************************************
 * About: csp 201812-1 小明上学
 * Author:  孙峰
 * Date: 2019.3.11
 ***************************************/
#include <iostream>
using namespace std;

int main()
{
    int r,g,y;
    int time = 0;
    int n;
    int k,t;
    cin >> r >> y >> g;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> k >> t;
        if(k == 0)
        {
            time += t;
        }
        else if (k == 1) {
            time += t;
        }
        else if (k == 2) {
            time += (t + r);
        }
        else
        {
            continue;
        }
    }
    cout << time << endl;
    system("pause");;
    return 0;
}