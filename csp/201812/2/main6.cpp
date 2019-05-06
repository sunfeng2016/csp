/*********************************
 * About: csp 201812-2 小明放学
 * Author: 孙峰
 * Date: 2019-3-14
 *********************************/
#include <iostream>
using namespace std;

int main()
{
    long long Lights[3];            //Lights[0],Lights[1],Lights[2]分别表示红、绿、黄灯的时长
    long long sum;
    int n;
    int k;
    long long t;
    int i;
    long long time = 0;
    cin >> Lights[0] >> Lights[2] >> Lights[1];
    sum = Lights[0] + Lights[1] + Lights[2];
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> k >> t;
        if(k == 0)                  //道路
        {
            time += t;
        }
        else                        //红绿灯
        {
            if(k == 1)              //建立k与数组Lights的映射关系
                k = 0;
            else if(k == 3)
                k = 1;
            
            t = Lights[k] - t;      //出发时刻该灯已亮时间
            t += time;              //假设灯一直不变，当前时刻该灯已亮时间
            t %= sum;               //该灯在最后一个变化周期的时长
            while(t > Lights[k])
            {
                t -= Lights[k];
                k = (k + 1) % 3;    //变成下一种灯
            }
            t = Lights[k] - t;      //当前时刻该灯剩余时长
            
            if(k == 0)              //当前时刻为红灯
                time += t;          
            else if(k == 2)         //当前时刻为黄灯
                time += (t + Lights[0]);
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}