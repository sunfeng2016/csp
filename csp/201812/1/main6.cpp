/*************************************
 * About: csp 201812-1 С����ѧ
 * Author: ���
 * Date: 2019-3-14
 *************************************/
#include <iostream>
using namespace std;

int main()
{
    int r,g,y;              //�ֱ��ʾ�졢�̡���������ɫ�ĵ�������ʱ��
    int n;
    int k,t;
    cin >> r >> y >> g;
    cin >> n;
    int time = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> k >> t;  
        if(k == 0)          //��·
            time += t;
        else if(k == 1)     //���
            time += t;
        else if(k == 2)     //�Ƶ�
            time += (t + r);
        else                //�̵�
            continue;
    }
    cout << time << endl;
    system("pause");
    return 0;
}