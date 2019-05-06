#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int board[31][31] = {0};
    bool remove[31][31] = {0};
    int N, M;
    scanf("%d%d", &N, &M);
    for(int n=0; n<N; n++) {
        for(int m=0; m<M; m++) {
            scanf("%d", &board[n][m]);
        }
    }
    int color;
    int cnt;
    for(int n=0; n<N; n++) {
        color = board[n][0];
        cnt = 1;
        for(int m=1; m<=M; m++) {
            if(board[n][m]==color) {
                cnt++;
            }
            else {
                if(cnt>=3) {
                    while(cnt) {
                        remove[n][m-cnt] = true;
                        cnt--;
                    }
                }
                color = board[n][m];
                cnt = 1;
            }
        }
    }
    for(int m=0; m<M; m++) {
        color = board[0][m];
        cnt = 1;
        for(int n=1; n<=N; n++) {
            if(board[n][m]==color) {
                cnt++;
            }
            else {
                if(cnt>=3) {
                    while(cnt) {
                        remove[n-cnt][m] = true;
                        cnt--;
                    }
                }
                color = board[n][m];
                cnt = 1;
            }
        }
    }
    for(int n=0; n<N; n++) {
        for(int m=0; m<M; m++) {
            if(remove[n][m]) printf("%d ", 0);
            else printf("%d ", board[n][m]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}