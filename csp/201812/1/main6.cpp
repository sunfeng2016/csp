/*************************************
 * About: csp 201812-1 小明上学
 * Author: 孙峰
 * Date: 2019-3-14
 *************************************/
#include <iostream>
using namespace std;

int main()
{
    int r,g,y;              //分别表示红、绿、黄三种颜色的灯所亮的时长
    int n;
    int k,t;
    cin >> r >> y >> g;
    cin >> n;
    int time = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> k >> t;  
        if(k == 0)          //道路
            time += t;
        else if(k == 1)     //红灯
            time += t;
        else if(k == 2)     //黄灯
            time += (t + r);
        else                //绿灯
            continue;
    }
    cout << time << endl;
    system("pause");
    return 0;
}