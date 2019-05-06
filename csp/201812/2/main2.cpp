/*
201812-2
小明放学
*/
#include <iostream>
using namespace std;

int main()
{
    long long lights[3];
    long long sum;
    long long n;                      //道路和红绿灯总数
    long long k,t;
    int i;
    long long time = 0;
    cin >> lights[0]            //红灯的时长
        >> lights[2]            //黄灯的时长
        >> lights[1];           //绿灯的时长
    sum = lights[0] + lights[1] + lights[2];
    //变化一个周期的时长
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> k >> t;
        if(k == 0)              //道路
            time += t;
        else                    //红绿灯
        {
            if(k == 1)          //红灯
                k = 0;
            else if(k == 3)     //绿灯
                k = 1;     
            t = lights[k] - t;  //出发时刻，相应红绿灯已经亮的时长
            t += time;          //若红绿灯一直不变，当前时刻已经亮的状态
            t = t % sum;        //最后一个周期的剩余时长
            while(t > lights[k])
            {
                t -= lights[k];
                k = (k + 1) % 3;//变成下一种灯
            } 
            t = lights[k] - t;  //当前时刻，该灯已经亮了的的时间
            if(k == 0)          //当前时刻是红灯
                time += t;
            else if(k == 2)     //当前时刻是黄灯
                time += (t + lights[0]);
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}