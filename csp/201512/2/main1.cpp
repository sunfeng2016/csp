/*
201512-2
*/
#include <iostream>
using namespace std;

int main()
{
    int board[31][31] = {0};        //棋盘
    int Remove[31][31] = {0};       //记录每个格子是否可消除
    int i,j;
    int N,M;
    int count = 0;
    int color;
    cin >> N >> M;
    for(i = 0;i < N;i++)
    {
        for(j = 0;j < M;j++)
            cin >> board[i][j];
    }    
    for(i = 0;i < N;i++)            //对于每一行
    {
        color = board[i][0];
        count = 1;
        for(j = 1;j <= M;j++)        //统计棋子左侧出现相同颜色棋子的个数
        {
            if(board[i][j] == color)
            {
                count++;
            }
            else
            {
                if(count >= 3)
                {
                    while(count)
                    {
                        Remove[i][j - count] = 1;
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
            {
                count++;
            }
            else
            {
                if(count >= 3)
                {
                    while(count)
                    {
                        Remove[i - count][j] = 1;
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
        for(j = 0;j < M;j++)
        {
            if(Remove[i][j])
                cout << 0 << " ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}