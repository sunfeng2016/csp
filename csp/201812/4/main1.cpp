/*
201812-4
*/

#include <iostream>
using namespace std;
#include <algorithm>

struct Edge                     //�ߵ�����
{
    int start;                  //�ߵ����
    int end;                    //�ߵ��յ�
    int val;                    //�ߵ�Ȩֵ
    bool operator < (Edge &obj){//����<
        return this->val < obj.val;
    }
};

Edge edges[100001];             //��ű�
int pre[500001];                //����ڽӶ���
int MaxEdge = 0;
int n,m;

int find(int x)                 //����ĳ��·���ĵ�һ���㣬Ϊ���ж��Ƿ��л�·����
{
    if(pre[x] == x)
    {
        return x;
    }
    else
    {
        pre[x] = find(pre[x]);
        return pre[x];
    }
}

void kruskal()                  //ʹ�ÿ�³˹�����㷨������С������
{
    int total = 0;              
    int u,v;
    for(int i = 1;i <= m;i++)   //ÿ��ѡ����С��һ����
    {
        u = find(edges[i].start);
        v = find(edges[i].end);
        if(u == v)              //��Ȧ��
            continue;
        MaxEdge = max(MaxEdge,edges[i].val);
        pre[u] = v;
        total++;        
        if(total == n-1)        //ֱ������n-1����Ϊֹ
            break;
    }
}

int main()
{
    int i;
    cin >> n >> m;
    int root;
    cin >> root;
    for(i = 1;i <= n;i++)
        pre[i] = i;
    for(i = 1;i <= m;i++)
    {
        cin >> edges[i].start >> edges[i].end >> edges[i].val;
    }
    sort(edges + 1,edges + m + 1);
    kruskal();
    cout << MaxEdge << endl;
    system("pause");
    return 0;
}
