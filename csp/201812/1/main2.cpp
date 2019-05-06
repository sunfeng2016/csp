/*
201812-1
小明上学
*/
#include <iostream>
using namespace std;

int main()
{
    int r,y,g;          //分别表示红、黄、绿灯的时长
    int n;              //道路和红绿灯数
    int k,t;
    cin >> r >> y >> g;
    cin >> n;
    int time = 0;       //小明上学花费的总时间
    for(int i = 0;i < n;i++)
    {
        cin >> k >> t;
        if(k == 0)      //道路
            time += t;
        else if(k == 1) //红灯
            time += t;
        else if(k == 2) //黄灯
            time += (t + r);
        else            //绿灯
            continue;
    }
    cout << time << endl;
//    system("pause");
    return 0;
}