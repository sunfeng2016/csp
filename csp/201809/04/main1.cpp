/***************************************************************************
 * About: ͼ����ʽǰ���Ǵ洢��ʽ��ʵ�����·��Dijkstra�㷨
 * Author: woxiang
 * Reference: https://blog.csdn.net/whereisherofrom/article/details/78922648
***************************************************************************/
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <queue>
#include <memory.h>

#define MaxNum 1000

//ͼ����ʽǰ���Ǵ洢�ṹ
struct Edge
{
    int u;              //�ߵ����
    int v;              //�ߵ��յ�
    int weight;         //�ߵ�Ȩֵ
    int next;           //ָ���u��������һ����
    Edge(){}
    Edge(int u1,int v1,int weight1,int next1):u(u1),v(v1),weight(weight1),next(next1){}
}edges[MaxNum];         //�洢�ߵľ�̬����

int head[MaxNum];       //��head[i]��ָ��i���ĵ�һ����
int edgeCount = 0;      //��ʼ����ǰ�ܱ���Ϊ0
int visited[MaxNum];    //���ʱ�־����

//ÿ����һ���ߣ�����AddEdge(u,v,w),�����ʵ������

void AddEdge(int u,int v,int w)
{                       
    edges[edgeCount] = Edge(u,v,w,head[u]);
    head[u] = edgeCount++;
}

/************************************************
 * ��������ĺ����ǣ�ÿ����һ����(u,v),����ԭ�еľ�̬��
 * ���ײ����������ߣ�ʹ��ÿ�β����ʱ�临�Ӷ�ΪO(1)����
 * ������ıߵ�˳��Ͷ���˳������������ġ�
 * ���õ�ʱ��ֻҪͨ��head[i]���ܷ��ʵ���i�����ĵ�һ����
 * �ı�ţ�ͨ����ŵ�edges��������������Եõ��ߵľ�����
 * Ϣ��Ȼ����������ߵ�next������Եõ��ڶ����ߵı�ţ�
 * �Դ����ƣ�ֱ��next��Ϊ-1
 ************************************************/

//�Ӷ���V��������ͨͼ��������ȱ���
void DFS(int v)                 
{
    visited[v] = true;
    cout << v << " ";
    for(Edge e = edges[head[v]]; head[v] != 1 && e.next != -1; e = edges[e.next])
    {
        if(!visited[e.v])
            DFS(e.v);
    }
}

//ͼ��������ȱ���
void DFSTraverse(int n) //nΪͼ�Ķ�����
{
    int v;
    for(v = 1;v <= n;v++)
        visited[v] = false;
    for(v = 1;v <= n;v++)
    {
        if(!visited[v])
            DFS(v);
    }
    cout << endl;
}

int main()
{
    memset(head,-1,sizeof(head));   //��ʼ�����е�head[i]Ϊ-1
    int n,m;
    int i;
    cin >> n >> m;
    int u,v,weight;
    for(i = 1;i <= m;i++)
    {
        cin >> u >> v >> weight;
        AddEdge(u,v,weight);
    }
    for(i = 0;i < edgeCount;i++)
    {
        cout << edges[i].u << " " 
             << edges[i].v << " "
             << edges[i].weight << " " 
             << edges[i].next << endl;
    }
    for(i = 1;i < n;i++)
        cout << head[i] << " ";
    cout << endl;
 //   DFSTraverse(n);
    for(i = 1;i <= n;i++)
    {
        cout << i << ": ";
        for(int k = head[i];k != -1;k = edges[k].next)
        {
            cout << edges[k].v << " * " << edges[k].weight << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
