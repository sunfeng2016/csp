/*
201812-1
С����ѧ
*/
#include <iostream>
using namespace std;

int main()
{
    int r,y,g;          //�ֱ��ʾ�졢�ơ��̵Ƶ�ʱ��
    int n;              //��·�ͺ��̵���
    int k,t;
    cin >> r >> y >> g;
    cin >> n;
    int time = 0;       //С����ѧ���ѵ���ʱ��
    for(int i = 0;i < n;i++)
    {
        cin >> k >> t;
        if(k == 0)      //��·
            time += t;
        else if(k == 1) //���
            time += t;
        else if(k == 2) //�Ƶ�
            time += (t + r);
        else            //�̵�
            continue;
    }
    cout << time << endl;
//    system("pause");
    return 0;
}