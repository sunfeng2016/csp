/*
201803-2
���
*/
#include <iostream>
using namespace std;

int location[100];          //ÿ��С��ĳһʱ�̵�λ��
int direction[100];         //ÿ��С��ĳһʱ�̵ķ���,1�������ң�-1��������

int main()
{
    int n,L,t;
    cin >> n >> L >> t;
    int i,j,k;
    for(i = 0;i < n;i++)
    {
        cin >> location[i];
        direction[i] = 1;
    }
    for(k = 0;k < t;k++)
    {
        for(i = 0;i < n;i++)
        {
            location[i] += direction[i];
            if(location[i] == L || location[i] == 0)
                direction[i] = 0 - direction[i]; 
            for(j = 0;j < n;j++)
            {
                if(location[j] == location[i])
                {
                    direction[i] = 0 - direction[i];
                    direction[j] = 0 - direction[j];
                    break;
                }
            }
        }
    }
    for(i = 0;i < n;i++)
    {
        cout << location[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}