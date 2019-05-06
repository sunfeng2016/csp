/*
201709-2
2019.3.3
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Action
{
    int num;                        //钥匙编号
    int type;                       //操作类型
    int time;                       //操作时间
    Action(int Num,int Type,int Time):num(Num),type(Type),time(Time){}
    bool operator <(Action &act){    //重载<
        if(this->time < act.time)
            return true;
        else if(this->time == act.time && this->type < act.type)
            return true;
        else if(this->time == act.time && this->type == act.type && this->num < act.num)
            return true;
        else
            return false;
    }
};

int main()
{
    int N,K;
    int i,j;
    cin >> N >> K;
    vector <Action> actions;
    vector <int> keys(N + 1);
    int number,begin,length;
    for(i = 1;i <= N;i++)
        keys[i] = i;
    for(i = 1;i <= K;i++)
    {
        cin >> number >> begin >> length;
        actions.push_back(Action(number,0,begin + length));
        actions.push_back(Action(number,1,begin));
    }
    sort(actions.begin(),actions.end());
    for(i = 0;i < actions.size();i++)
    {
        Action &act = actions[i];
        if(act.type == 0)               //还钥匙
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
    for(i = 1;i <= N;i++)
        cout << keys[i] << " ";
    system("pause");
    return 0;
}