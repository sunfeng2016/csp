/***************************************************************************
 * About: 图的链式前向星存储方式和实现最短路径Dijkstra算法
 * Author: woxiang
 * Reference: https://blog.csdn.net/whereisherofrom/article/details/78922648
***************************************************************************/
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <queue>
#include <memory.h>

#define MaxNum 1000

//图的链式前向星存储结构
struct Edge
{
    int u;              //边的起点
    int v;              //边的终点
    int weight;         //边的权值
    int next;           //指向从u出来的下一条边
    Edge(){}
    Edge(int u1,int v1,int weight1,int next1):u(u1),v(v1),weight(weight1),next(next1){}
}edges[MaxNum];         //存储边的静态链表

int head[MaxNum];       //用head[i]来指向i结点的第一条边
int edgeCount = 0;      //初始化当前总边数为0
int visited[MaxNum];    //访问标志数组

//每读入一条边，调用AddEdge(u,v,w),其具体实现如下

void AddEdge(int u,int v,int w)
{                       
    edges[edgeCount] = Edge(u,v,w,head[u]);
    head[u] = edgeCount++;
}

/************************************************
 * 这个函数的含义是，每加入一条边(u,v),就在原有的静态链
 * 表首部插入这条边，使得每次插入的时间复杂度为O(1)，所
 * 以链表的边的顺序和读入顺序正好是逆序的。
 * 调用的时候只要通过head[i]就能访问到由i出发的第一条边
 * 的编号，通过编号到edges数组进行索引可以得到边的具体信
 * 息，然后根据这条边的next领域可以得到第二条边的编号，
 * 以此类推，直到next域为-1
 ************************************************/

//从顶点V出发对连通图做深度优先遍历
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

//图的深度优先遍历
void DFSTraverse(int n) //n为图的顶点数
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
    memset(head,-1,sizeof(head));   //初始化所有的head[i]为-1
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
