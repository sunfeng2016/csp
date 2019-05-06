#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Action{
	int number;		//钥匙编号
	int time;		//操作时间
	int type;		//操作类型 0:put,1:get
	Action(int Number,int Time,int Type):number(Number),time(Time),type(Type){}
};

bool cmp(Action act1,Action act2)
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
	int i,j;
	int number,start,length;
	cin >> N >> K;
	vector<Action>actions;
	vector<int>keys(N+1);
	for(i = 1;i <= N;i++)
	{
		keys[i] = i;
	}
	for(i = 0;i < K;i++)
	{
		cin >> number >> start >> length;
		actions.push_back(Action(number,start,1));
		actions.push_back(Action(number,start+length,0));
	}
	sort(actions.begin(),actions.end(),cmp);
	for(i = 0;i < actions.size();i++)
	{
		Action &act = actions[i];
		if(act.type == 0)
		{
			for(j = 1;j <= N;j++)
			{
				if(keys[j] == -1)
				{
					keys[j] = act.number;
					break;
				}
			}
		}
		else
		{
			for(j = 1;j <= N;j++)
			{
				if(keys[j] == act.number)
				{
					keys[j] = -1;
					break;
				}
			}
		}
	}
	for(i = 1;i <= N;i++)
		cout << keys[i] << " ";
    cout << endl;
    system("pause");
	return 0;
}
