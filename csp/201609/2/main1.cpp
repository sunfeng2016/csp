/*
201609-2
*/

#include <iostream>
using namespace std;

int main()
{
    int Seat[20];       //ÿ����ʣ����λ��
    int Order[100];     //��Ʊָ��
    int i,j,k;
    for(i = 0; i < 20;i++)
        Seat[i] = 5;
    int n;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> Order[i];
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < 20;j++)
        {
            if(Seat[j] >= Order[i])
            {
                for(k = 1;k <= Order[i];k++)
                {
                    cout << j * 5 + 5 - Seat[j] + k << " ";
                }
                Seat[j] -= Order[i]; 
                Order[i] = 0;
                break;
            }
        }
        while(Order[i] > 0)
        {
            for(j = 0;j < 20;j++)
            {
                while(Seat[j] > 0)
                {
                    cout << j * 5 + 5 - Seat[j] + 1 << " ";
                    Seat[j]--;
                    Order[i]--;
                }
            }
        }
        cout << endl;
    }
    system("pause");
    system("pause");
    system("pause");
    return 0;
}