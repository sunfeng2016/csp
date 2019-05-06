/*****************************************
 About:有向图的迪杰斯特拉(Dijkstra)算法实现
 Author: WoXiang
 Reference: www.WuTianQi.com(Blog)
 ****************************************/

#include <iostream>
using namespace std;

#define MaxNum  100
#define INFINITY INT_MAX

struct Graph
{
    int vexnum;
    int arcnum;
    int arcs[MaxNum][MaxNum];
};

//求源节点root到其他所有节点的最短路径
void Dijkstra(int root, int *dist, int *prev, Graph &G)
{
    int i,j;
    int min;
    int u;
    bool Status[MaxNum];        //判断是否已存入该点到S集合
    for(i = 1;i <= G.vexnum;i++)       //初始化
    {                           
        dist[i] = G.arcs[root][i];
        Status[i] = false;      
        if(dist[i] == INFINITY)
            prev[i] = 0;
        else    
            prev[i] = root;
    }
    dist[root] = 0;
    Status[root] = true;

    //依次将未放入S集合的结点中，取dist[]最小值的结点
    //放入集合S中，一旦S包含了所有V中的顶点，dist就记录
    //了从源点到所有其他顶点之间的最短路径长度。

    for(i = 2;i <= G.vexnum;i++)
    {
        min = INFINITY;
        u = root;
        //找出当前未使用的点j的dist[j]最小值
        for(j = 1;j <= G.vexnum;j++)
        {
            if(!Status[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
                //保存当前邻接点中距离最小的号码
            }   
        }
        Status[u] = true;      //表示u点存入集合S中
        //更新dist
        for(j = 1;j <= G.vexnum;j++)
        {
            if((!Status[j]) && G.arcs[u][j] < INFINITY)
            {
                if(dist[u] + G.arcs[u][j] < dist[j])
                {
                    dist[j] = dist[u] + G.arcs[u][j];
                    prev[j] = u;
                }
            }
        }
    }
}

void SreachPath(int *prev, int v,int u)
{
    int que[MaxNum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int temp = prev[u];
    while(temp != v)
    {
        que[tot] = temp;
        tot++;
        temp = prev[temp];
    }
    que[tot] = v;
    for(int i = tot;i >= 1;i--)
    {
        if(i != 1)
            cout << que[i] << "---> ";
        else    
            cout << que[i] << endl;
    }
}

int main()
{
    int dist[MaxNum];           //表示当前点到源到的最短路径长度
    int prev[MaxNum];           //记录当前点的前一个结点
    Graph G;                    //无向图
    cin >> G.vexnum;            //输入顶点数
    cin >> G.arcnum;            //输入边数
    int p,q,weight;
    int i,j;
    for(i = 1;i <= G.vexnum;i++)
    {                           //初始化邻接矩阵
        for(j = 1;j <= G.vexnum;j++)
        {
            G.arcs[i][j] = INFINITY;
        }
    }
    for(i = 1;i <= G.arcnum;i++)
    {
        cin >> p >> q >> weight;
        G.arcs[p][q] = weight;
        G.arcs[q][p] = weight;  //无向图
    }
    for(i = 1;i <= G.vexnum;i++)
        dist[i] = INFINITY;
    Dijkstra(1,dist,prev,G);
    
    //最短路径长度
    cout << "源点到最后一个顶点的最短路径长度:" << dist[G.vexnum] << endl;

    //最短路径
    cout << "源点到最后一个顶点的路径为:";
    SreachPath(prev,1,G.vexnum);

    system("pause");
    return 0;
}