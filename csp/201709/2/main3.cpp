/*
201709-2
���
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Action
{
    int type;                   //�������ͣ�1����ȡԿ�ף�0����Կ��
    int num;                    //Կ�ױ��;
    int time;                   //����ʱ��
    Action(int Type,int Num,int Time):type(Type),num(Num),time(Time){}
};

vector <Action> actions;        //������в���������
int keys[1001];                 //ÿ���ҹ��ϵ�Կ�ױ��         

bool compare(Action act1,Action act2)
{
    if(act1.time < act2.time)   //�ȸ���ʱ������
        return true;
    else if(act1.time == act2.time && act1.type < act2.type)
        return true;            //ʱ����ͬ������ȡ�������ȷź�ȡ
    else if(act1.time == act2.time && act1.type == act2.type && act1.num < act2.num)
        return true;            //������ͬ������Կ�ױ������
    else
        return false;
}

int main()
{
    int N,K;                    //n����Կ��������k����ȡԿ�׵���ʦ��
    int i,j;
    int number;                 //Կ�ױ��
    int begin;                  //ȡԿ�׵�ʱ��
    int length;                 //�Ͽ�ʱ��
    cin >> N >> K;
    for(i = 1;i <= N;i++)       //һ��ʼԿ�װ���Ŵ�С�����˳����ڹҹ���
        keys[i] = i;            
    for(i = 1;i <= K;i++)
    {
        cin >> number >> begin >> length;
        actions.push_back(Action(1,number,begin));
        actions.push_back(Action(0,number,begin + length));
    }
    sort(actions.begin(),actions.end(),compare);
    for(i = 0;i < actions.size();i++)
    {
        Action &act = actions[i];
        if(act.type == 0)       //��Կ��
        {
            for(j = 1;j <= N;j++)
            {
                if(keys[j] == -1)
                {
                    keys[j] = act.num;
                    break;
                }
            }
        }
        else                    
        {
            for(j = 1;j <= N;j++)
            {
                if(keys[j] == act.num)
                {
                    keys[j] = -1;
                    break;
                }
            }
        }
    }
    for(j = 1;j <= N;j++)
        cout << keys[j] << " ";
    cout << endl;
    system("pause");
    return 0;
}
