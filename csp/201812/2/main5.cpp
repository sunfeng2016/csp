/*******************************************
 * About: csp 201812-2 小明放学
 * Author: 孙峰
 * Date: 2018-3-11
 *******************************************/
#include <iostream>
using namespace std;

int main()
{
    long long Lights[3];                            //Lights[0...2]分别表示红、绿、黄三种颜色灯的时长
    int n;
    int k;
    long long t;
    long long time = 0;   
    long long sum;            
    cin >> Lights[0] >> Lights[2] >> Lights[1];     //注意，输入是按照红、黄、绿的顺序输入的
    sum = Lights[0] + Lights[1] + Lights[2];        //红绿灯变换一个周期的总时长
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> k >> t;
        if(k == 0)                                  //道路
        {
            time += t;
        }
        else
        {
            if(k == 1)                              //初始时刻为红灯
            {
                k = 0;                              //建立k和Lights的映射关系
            }
            else if (k == 3) {                      //初始时刻为绿灯
                k = 1;                              
            }
            t = Lights[k] - t;                      //初始时刻该种颜色的灯已亮的时长
            t += time;                              //若灯一直不变，则当前时刻此种颜色的灯已亮的时长
            t %= sum;                               //最后一个周期的剩余时长
            while(t > Lights[k])
            {
                t -= Lights[k];
                k = (k + 1) % 3;
            }
            t = Lights[k] - t;                      //当前时刻，此灯剩余时长
            if(k == 0)                              //当前时刻为红灯
            {
                time += t;
            }
            else if(k == 2)                         //当前时刻为黄灯
            {
                time += (t + Lights[0]);
            }
        } 
    }
    cout << time << endl;
    system("pause");
    return 0;
}