/*
201812-2
С����ѧ
*/
#include <iostream>
using namespace std;

int main()
{
    long long lights[3];
    long long sum;
    long long n;                      //��·�ͺ��̵�����
    long long k,t;
    int i;
    long long time = 0;
    cin >> lights[0]            //��Ƶ�ʱ��
        >> lights[2]            //�ƵƵ�ʱ��
        >> lights[1];           //�̵Ƶ�ʱ��
    sum = lights[0] + lights[1] + lights[2];
    //�仯һ�����ڵ�ʱ��
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> k >> t;
        if(k == 0)              //��·
            time += t;
        else                    //���̵�
        {
            if(k == 1)          //���
                k = 0;
            else if(k == 3)     //�̵�
                k = 1;     
            t = lights[k] - t;  //����ʱ�̣���Ӧ���̵��Ѿ�����ʱ��
            t += time;          //�����̵�һֱ���䣬��ǰʱ���Ѿ�����״̬
            t = t % sum;        //���һ�����ڵ�ʣ��ʱ��
            while(t > lights[k])
            {
                t -= lights[k];
                k = (k + 1) % 3;//�����һ�ֵ�
            } 
            t = lights[k] - t;  //��ǰʱ�̣��õ��Ѿ����˵ĵ�ʱ��
            if(k == 0)          //��ǰʱ���Ǻ��
                time += t;
            else if(k == 2)     //��ǰʱ���ǻƵ�
                time += (t + lights[0]);
        }
    }
    cout << time << endl;
    system("pause");
    return 0;
}