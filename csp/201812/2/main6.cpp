/*********************************
 * About: csp 201812-2 С����ѧ
 * Author: ���
 * Date: 2019-3-14
 *********************************/
#include <iostream>
using namespace std;

int main()
{
    long long Lights[3];            //Lights[0],Lights[1],Lights[2]�ֱ��ʾ�졢�̡��ƵƵ�ʱ��
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
        if(k == 0)                  //��·
        {
            time += t;
        }
        else                        //���̵�
        {
            if(k == 1)              //����k������Lights��ӳ���ϵ
                k = 0;
            else if(k == 3)
                k = 1;
            
            t = Lights[k] - t;      //����ʱ�̸õ�����ʱ��
            t += time;              //�����һֱ���䣬��ǰʱ�̸õ�����ʱ��
            t %= sum;               //�õ������һ���仯���ڵ�ʱ��
            while(t > Lights[k])
            {
                t -= Lights[k];
                k = (k + 1) % 3;    //�����һ�ֵ�
            }
            t = Lights[k] - t;      //��ǰʱ�̸õ�ʣ��ʱ��
            
            if(k == 0)              //��ǰʱ��Ϊ���
                time += t;          
            else if(k == 2)         //��ǰʱ��Ϊ�Ƶ�
                time += (t + Lights[0]);
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}