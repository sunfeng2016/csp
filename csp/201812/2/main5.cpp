/*******************************************
 * About: csp 201812-2 С����ѧ
 * Author: ���
 * Date: 2018-3-11
 *******************************************/
#include <iostream>
using namespace std;

int main()
{
    long long Lights[3];                            //Lights[0...2]�ֱ��ʾ�졢�̡���������ɫ�Ƶ�ʱ��
    int n;
    int k;
    long long t;
    long long time = 0;   
    long long sum;            
    cin >> Lights[0] >> Lights[2] >> Lights[1];     //ע�⣬�����ǰ��պ졢�ơ��̵�˳�������
    sum = Lights[0] + Lights[1] + Lights[2];        //���̵Ʊ任һ�����ڵ���ʱ��
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> k >> t;
        if(k == 0)                                  //��·
        {
            time += t;
        }
        else
        {
            if(k == 1)                              //��ʼʱ��Ϊ���
            {
                k = 0;                              //����k��Lights��ӳ���ϵ
            }
            else if (k == 3) {                      //��ʼʱ��Ϊ�̵�
                k = 1;                              
            }
            t = Lights[k] - t;                      //��ʼʱ�̸�����ɫ�ĵ�������ʱ��
            t += time;                              //����һֱ���䣬��ǰʱ�̴�����ɫ�ĵ�������ʱ��
            t %= sum;                               //���һ�����ڵ�ʣ��ʱ��
            while(t > Lights[k])
            {
                t -= Lights[k];
                k = (k + 1) % 3;
            }
            t = Lights[k] - t;                      //��ǰʱ�̣��˵�ʣ��ʱ��
            if(k == 0)                              //��ǰʱ��Ϊ���
            {
                time += t;
            }
            else if(k == 2)                         //��ǰʱ��Ϊ�Ƶ�
            {
                time += (t + Lights[0]);
            }
        } 
    }
    cout << time << endl;
    system("pause");
    return 0;
}