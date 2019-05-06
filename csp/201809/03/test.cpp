#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<iomanip>
#include<vector>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<map>
#define mem(a,b) memset(a,b,sizeof(a))
#define e 2.71828182
#define Pi 3.141592654
using namespace std;
struct node
{
	vector<string> ance_lab[101];//标签祖先（父代） 
    vector<string> ance_id[101];//id祖先 （父代） 
	int col;//冒号个数 
	string label;//标签
	string id;//id属性 
}ele[101];//元素 
bool islegal(string a,string b)//两个标签是否相等（大小写不敏感） 
{
	if(a.length()!=b.length()) return false;
	for(int i=0;i<a.length();i++)
	if(a[i]==b[i]) continue;
	else if(a[i]==b[i]+'A'-'a') continue;
	else if(b[i]==a[i]+'A'-'a') continue;
	else return false;
	return true;
}
int main()
{
	int n,m;
	cin>>n>>m;
	cin.ignore();
	for(int i=1;i<=n;i++)
	{
		string str;
		getline(cin,str);
		
		int num=str.find('.');
		while(str[num]=='.'||num==-1) num++;
		ele[i].col=num;//冒号个数 
		
		if(str.find('#')!=string::npos)//有id属性 
		{
			ele[i].id=str.substr(str.find('#')+1);
			ele[i].label=str.substr(num,str.find('#')-num-1);
		}
		else //无id属性 
		{
			ele[i].id="";
			ele[i].label=str.substr(num);
		} 
		
		//找祖先 
		for(int j=1;j<i;j++)
		{
			if(ele[j].col>=num) continue;
			int cnt=ele[j].col/2;
			if(ele[j].id!="")  ele[i].ance_id[cnt].push_back(ele[j].id);
			ele[i].ance_lab[cnt].push_back(ele[j].label);
			
		} 
	} 
	
	
	for(int i=1;i<=m;i++)
	{
		string sel;//selector
		getline(cin,sel);
		int ans=0,a[101];//查询结果 
		mem(a,0);
		if(sel.find('#')==string::npos&&sel.find(' ')==string::npos)//标签选择器查询 
		{
			for(int j=1;j<=n;j++)
				if(islegal(sel,ele[j].label))
				    a[++ans]=j;	
	        cout<<ans<<' ';
			for(int k=1;k<=ans;k++) cout<<a[k]<<' ';
			cout<<endl;	
		}
		
		else if(sel.find('#')!=string::npos&&sel.find(' ')==string::npos)//id选择器查询
		{
			sel=sel.substr(1);//去掉井号 
		        for(int j=1;j<=n;j++)
			    if(sel==ele[j].id)
				    a[++ans]=j;
			cout<<ans<<' ';
			for(int k=1;k<=ans;k++) cout<<a[k]<<' ';
			cout<<endl;	
		} 
		
		else //后代选择器 
		{
			string str;
			for(int j=1;j<=n;j++)
			{
				//利用字符串流和栈将后代选择器的子代和父代按顺序区分出来 
				stringstream ss(sel);
				stack<string> temp;
				int cnt=0;//子代和父代的总数 
				while(ss>>str)
				{ 
					temp.push(str);
					cnt++;
				}
			
				//子代是否满足条件 
				str=temp.top();
				temp.pop();
				if(str.find('#')==string::npos&&!islegal(str,ele[j].label)) 
					continue;
				else if(str.find('#')!=string::npos&&str.substr(1)!=ele[j].id) 
					continue;
 
				//父代是否满足条件 
				int sum=0;//找到的父代个数 
				for(int p=(ele[j].col-2)/2;p>=0;p--)
				{
					str=temp.top();
					if(str.find('#')==string::npos) //标签 
					{	for(int q=0;q<ele[j].ance_lab[p].size();q++)
						{
							if(islegal(str,ele[j].ance_lab[p][q])) 
							{
								sum++;
								temp.pop();
								break;
							}	
						}
					}
					
					else //id
					{
						for(int q=0;q<ele[j].ance_id[p].size();q++)
						{
							string stri=str.substr(1);//没讲#保存在id里，记得要将#去掉 
							if(stri==ele[j].ance_id[p][q]) 
							{
								sum++;
								temp.pop();
								break;
							}
						}   
					}
					
					if(sum==cnt-1) 
					{
						a[++ans]=j;
						break;
					}
				}
					
			}
			cout<<ans<<' ';
			for(int k=1;k<=ans;k++) 
				cout<<a[k]<<' ';
			cout<<endl;	
		}
	}

    system("pause");
    return 0;
}