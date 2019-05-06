/*
201512-2
*/
#include <iostream>
using namespace std;

int main()
{
    int board[31][31] = {0};            //棋盘上每个棋子的颜色
    int status[31][31] = {0};           //代表对应位置的棋子能否消除
    int M,N;
    int i,j;
    int count;
    int color;
    cin >> N >> M;
    for(i = 0;i < N;i++)                //棋盘初始化
    {
        for(j = 0;j < M;j++)
            cin >> board[i][j];
    }
    for(i = 0;i < N;i++)                //消除某一行时统计棋子左侧出现相同颜色的个数，出现次数大于3，则消除
    {
        color = board[i][0];
        count = 1;
        for(j = 1;j <= M;j++)           //统计每一行某个颜色的棋子出现的次数，注意这里区间是[1,M]
        {
            if(board[i][j] == color)
            {
                count++;
            }
            else
            {
                if(count >= 3)
                {
                    while(count){
                        status[i][j - count] = 1;
                        count--;
                    }
                }
                color = board[i][j];
                count = 1;
            }
        }     
    }
    for(j = 0;j < M;j++)
    {
        color = board[0][j];
        count = 1;
        for(i = 1;i <= N;i++)
        {
            if(board[i][j] == color)
                count++;
            else
            {
                if(count >= 3)
                {
                    while(count){
                        status[i-count][j] = 1;
                        count--;
                    }
                }
                color = board[i][j];
                count = 1;
            } 
        }
    }
    for(i = 0;i < N;i++)
    {
        for(j = 0; j < M;j++)
        {
            if(status[i][j])
                cout << 0 << " ";
            else
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}