/*************************************
 * About: 图的链式前向星存储表示
 * Author:
 * Date:
 * 链式前向星：每个结点i都有一个链表，链表的所有数据是从i出发的所有边的集合
 *（对比邻接表存的是顶点集合），边的表示为一个四元组(u, v, w, next)，其中
 * (u, v)代表该条边的有向顶点对，w代表边上的权值，next指向下一条边。
 *************************************/

#include <iostream>
using namespace std;
#include <memory.h>

const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;

int head[maxn];                 //head[i]用于存储编号为i的点指向的第一条边的位置
struct Edge
{
    int to;                     //边的终点
    int w;                      //边权
    int next;                   //链式记录下一条边的位置
}edge[maxm];

int main()
{
    int m,n;
    int tol = 0;
    memset(head,-1,sizeof(head));
    cin >> n >> m;
    //建图方法
    while(m--){
        int f,t,w;
        cin >> f >> t >> w;
        edge[tol].to = t;
        edge[tol].w = w;
        edge[tol].next = head[f];
        head[f] = tol++;
    }
    //遍历方法
    for(int i = 1;i <= n;i++)
    {
        cout << i << ": ";
        for(int k = head[i]; k != -1; k = edge[k].next)
        {
            cout << edge[k].to << " * " << edge[k].w << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
