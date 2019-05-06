/*
201709-2
孙峰
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Action
{
    int type;                   //操作类型，1代表取钥匙，0代表还钥匙
    int num;                    //钥匙编号;
    int time;                   //操作时间
    Action(int Type,int Num,int Time):type(Type),num(Num),time(Time){}
};

vector <Action> actions;        //存放所有操作的向量
int keys[1001];                 //每个挂钩上的钥匙编号         

bool compare(Action act1,Action act2)
{
    if(act1.time < act2.time)   //先根据时间排序
        return true;
    else if(act1.time == act2.time && act1.type < act2.type)
        return true;            //时间相同，根据取放排序，先放后取
    else if(act1.time == act2.time && act1.type == act2.type && act1.num < act2.num)
        return true;            //操作相同，根据钥匙编号排序
    else
        return false;
}

int main()
{
    int N,K;                    //n代表钥匙总数，k代表取钥匙的老师数
    int i,j;
    int number;                 //钥匙编号
    int begin;                  //取钥匙的时间
    int length;                 //上课时间
    cin >> N >> K;
    for(i = 1;i <= N;i++)       //一开始钥匙按编号从小到大的顺序放在挂钩上
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
        if(act.type == 0)       //还钥匙
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
