/*
ID: yusean11
LANG: C++
TASK: agrinet
 */
#include <stdio.h>
#include <iostream>
using namespace std;
int cost = 0, n, neighbor[100][100], size = 1;
bool inTree[100];
int main(){
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j ++) cin >> neighbor[i][j];
		inTree[i] = false;
	}
	int distance[n];
	for(int i = 0; i < n; i++){
		distance[i] = neighbor[0][i];
	}
	inTree[0] = true;
	while(size <= n){
		int m = 2000000000, t;
		for(int i = 0; i < n; i ++){
			if(!inTree[i]&&(distance[i]<m)){
				m = distance[i];
				t = i;
			}
		}
		inTree[t] = true;
		cost += distance[t];
		size ++;
		for(int i = 0; i < n; i++) if(neighbor[t][i] < distance[i]) distance[i] = neighbor[t][i];
	}
	cout << cost <<"\n";
}



