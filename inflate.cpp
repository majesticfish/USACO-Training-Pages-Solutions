/*
ID: seanyu11
LANG: C++
TASK: inflate
 */
#include <stdio.h>
#include <iostream>
using namespace std;
int scores[10000], problem[2][10000],m,n;
int main(){
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	cin >> m >> n;
	for(int i = 0; i < n; i ++){
		cin >> problem[0][i] >> problem[1][i];
	}
	for(int i = 0; i <= m; i ++){
		scores[i] = 0;
	}
	for(int i = 0; i < n; i ++){
		for(int j = problem[1][i]; j <= m; j++){
			if(scores[j-problem[1][i]] + problem[0][i] > scores[j]) scores[j] = scores[j-problem[1][i]]+problem[0][i];
		}
	}
	cout << scores[m] <<"\n";
}



