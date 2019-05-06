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
	vector<string> ance_lab[101];//��ǩ���ȣ������� 
    vector<string> ance_id[101];//id���� �������� 
	int col;//ð�Ÿ��� 
	string label;//��ǩ
	string id;//id���� 
}ele[101];//Ԫ�� 
bool islegal(string a,string b)//������ǩ�Ƿ���ȣ���Сд�����У� 
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
		ele[i].col=num;//ð�Ÿ��� 
		
		if(str.find('#')!=string::npos)//��id���� 
		{
			ele[i].id=str.substr(str.find('#')+1);
			ele[i].label=str.substr(num,str.find('#')-num-1);
		}
		else //��id���� 
		{
			ele[i].id="";
			ele[i].label=str.substr(num);
		} 
		
		//������ 
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
		int ans=0,a[101];//��ѯ��� 
		mem(a,0);
		if(sel.find('#')==string::npos&&sel.find(' ')==string::npos)//��ǩѡ������ѯ 
		{
			for(int j=1;j<=n;j++)
				if(islegal(sel,ele[j].label))
				    a[++ans]=j;	
	        cout<<ans<<' ';
			for(int k=1;k<=ans;k++) cout<<a[k]<<' ';
			cout<<endl;	
		}
		
		else if(sel.find('#')!=string::npos&&sel.find(' ')==string::npos)//idѡ������ѯ
		{
			sel=sel.substr(1);//ȥ������ 
		        for(int j=1;j<=n;j++)
			    if(sel==ele[j].id)
				    a[++ans]=j;
			cout<<ans<<' ';
			for(int k=1;k<=ans;k++) cout<<a[k]<<' ';
			cout<<endl;	
		} 
		
		else //���ѡ���� 
		{
			string str;
			for(int j=1;j<=n;j++)
			{
				//�����ַ�������ջ�����ѡ�������Ӵ��͸�����˳�����ֳ��� 
				stringstream ss(sel);
				stack<string> temp;
				int cnt=0;//�Ӵ��͸��������� 
				while(ss>>str)
				{ 
					temp.push(str);
					cnt++;
				}
			
				//�Ӵ��Ƿ��������� 
				str=temp.top();
				temp.pop();
				if(str.find('#')==string::npos&&!islegal(str,ele[j].label)) 
					continue;
				else if(str.find('#')!=string::npos&&str.substr(1)!=ele[j].id) 
					continue;
 
				//�����Ƿ��������� 
				int sum=0;//�ҵ��ĸ������� 
				for(int p=(ele[j].col-2)/2;p>=0;p--)
				{
					str=temp.top();
					if(str.find('#')==string::npos) //��ǩ 
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
							string stri=str.substr(1);//û��#������id��ǵ�Ҫ��#ȥ�� 
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