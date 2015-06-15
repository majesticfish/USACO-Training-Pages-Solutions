/*
ID: seanyu11
LANG: C++
PROB: ttwo
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    int c = -1, pos[2][3] = {{0}}, di[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    char g[12][13];
    memset(g, '*', sizeof g);
    freopen("ttwo.in", "r", stdin), freopen("ttwo.out", "w", stdout);
    for (int i = 1; i <= 10; i++, getchar())
        for (int j = 1; j <= 10; j++) {
            g[i][j] = getchar();
            if (g[i][j] == 'C' || g[i][j] == 'F') pos[++c][0] = i, pos[c][1] = j;
        }

    for(int i=1; i<=400; i++){
        for(int j=0; j<2; j++){
            if(g[pos[j][0] + di[pos[j][2]][0]][pos[j][1] + di[pos[j][2]][1]]!='*')
                pos[j][0] += di[pos[j][2]][0], pos[j][1] += di[pos[j][2]][1];
            else
                pos[j][2] = (pos[j][2]+1)%4;
        }
        if(pos[0][0]==pos[1][0] && pos[0][1]==pos[1][1]){
            printf("%d\n", i);
            return 0;
        }
    }
    puts("0");
    return 0;
}



