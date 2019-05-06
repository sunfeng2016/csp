/*
201812-2
孙峰
*/
#include <iostream>
using namespace std;

int main()
{
    long long total = 0;          //小明回家的总时间
    long long n,k,t;
    long long light[3];           //存放红、绿、黄3种状态的时长
    cin >> light[0] >> light[2] >> light[1];
    long long sum = light[0] + light[1] + light[2];   //红绿灯周期
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> k >> t;
        if(k == 0)              //道路
            total += t;
        else                    //红绿灯
        {
            if(k == 1)          //初始时刻为红灯
                k = 0;
            else if(k == 3)     //初始时刻为绿灯
                k = 1;
            t = light[k] - t;   //在初始时刻已经亮的时间
            t = t + total;      //假设状态一直不变，当前时刻持续亮的时间
            t = t % sum;        //最后一个变化周期剩余的时长
            while(t > light[k]) //如果剩余时长大于当前状态的时长
            {   
                t -= light[k];  //调整剩余时长
                k = (k + 1) % 3;//转向下一个状态
            }
            if(k == 0)          //当前状态为红灯
                total += (light[0] - t);
            else if(k == 2)     //当前状态为黄灯
                total += (light[2] - t + light[0]);
        }
    }
    cout << total << endl;
    return 0;
}