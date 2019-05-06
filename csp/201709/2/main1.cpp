/*
201709-2
孙峰
*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

struct Action{
    int type;               //操作类型,0还，1取
    int time;               //操作时间
    int number;             //操作编号
    Action(int Type,int Time,int Number):type(Type),time(Time),number(Number){}
};

bool compare(Action act1,Action act2)
{
	if(act1.time < act2.time)
		return true;
	else if(act1.time == act2.time && act1.type < act2.type)
		return true;
	else if(act1.time == act2.time && act1.type == act2.type && act1.number < act2.number)
		return true;
	else
		return false;
}

int main()
{
    int N,K;
    cin >> N >> K;
    vector <Action> action;
    vector <int> box(N+1);
    int i,j;
    int num,begin,time_long;
    for(i = 1;i <= N;i++)
        box[i] = i;
    for(i = 1;i <= K;i++)
    {
        cin >> num >> begin >> time_long;
        action.push_back(Action(1,begin,num));
        action.push_back(Action(0,begin+time_long,num));
    }
    sort(action.begin(),action.end(),compare);
    for(i = 0;i < action.size();i++)
    {
        Action &act = action[i];
        if(act.type == 0)
        {
            for(j = 1;j <= N;j++)
            {
                if(box[j] == -1)
                {
                    box[j] = act.number;
                    break;
                }
            }
        }
        else
        {
            for(j = 1;j <= N;j++)
            {
                if(box[j] == act.number)
                {
                    box[j] = -1;
                    break;
                }
            }
        }
    }
    for(i = 1;i <= N;i++)
        cout << box[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}