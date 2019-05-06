/*
201703-2
���
*/

#include <iostream>
using namespace std;

int students[1001];         //ÿ��λ���ϵ�ѧ��ѧ��
int locations[1001];        //ÿ��ѧ�����ڵ�λ��

int main()
{
    int n,m;
    int p,q;
    int i,j;
    cin >> n >> m;
    for(i = 1;i <= n;i++)
    {
        locations[i] = i;
        students[i] = i;
    }
    for(i = 1;i <= m;i++)
    {
        cin >> p >> q;
        if(q > 0)         //���
        {
            for(j = locations[p] + 1;j <= locations[p] + q;j++)
            {
                locations[students[j]]--;
            }
        }
        else            //��ǰ
        {
            for(j = locations[p] - 1;j >= locations[p] + q;j--)
            {
                locations[students[j]]++;
            }
        }
        locations[p] += q;
        for(j = 1;j <= n;j++)
        {
            students[locations[j]] = j;
        }
    }
    for(i = 1;i <= n;i++)
        cout << students[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}