/*
ID: yusean11
LANG: C++
TASK: game1
 */
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int n, board[100], dp[100][100][2];
int main(){
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> board[i];
	}
	for(int i = 0; i < n; i ++){
		dp[i][i][0] = board[i];
		dp[i][i][1] = 0;
	}
	for(int i = 1; i < n; i ++){
		for(int j = 0; i+j < n; j ++){
			dp[j][i+j][0] = max(dp[j+1][i+j][1]+board[j], dp[j][i+j-1][1]+board[i+j]);
			if(dp[j+1][i+j][1]+board[j] > dp[j][i+j-1][1]+board[i+j]){
				dp[j][i+j][1] = dp[j+1][i+j][0];
			}else
				dp[j][i+j][1] = dp[j][i+j-1][0];
		}
	}
	cout << dp[0][n-1][0] << " " << dp[0][n-1][1] << endl;
}



