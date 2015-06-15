/*
ID: seanyu11
LANG: C++
PROB: camelot
 */
#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int,int> ii;
int r,c, row, n = 0, kr[8] = {2,2,1,1,-1,-1,-2,-2}, kc[8] = {1,-1,2,-2,2,-2,1,-1}, knightCosts[30][26], minKingCost = 2000000000, kingPath[30][26];
short path[30][26][30][26];
ii knights[780], king;
int main(){
	string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	cin >> r >> c;
	memset(path,-1,sizeof(path));
	memset(knightCosts,0,sizeof(knightCosts));
	char col;
	cin >> col >> row;
	king.first = row-1;
	king.second = a.find(col);
	while(cin >> col >> row){
		knights[n++] = make_pair(row-1,a.find(col));
	}
//	cout << knights[0].first <<" " << knights[0].second <<"\n";
	for(int i = 0; i < r; i ++){
		for(int j = 0; j < c; j ++){
			kingPath[i][j] = max(abs(i-king.first), abs(j - king.second));
			queue<ii> q;
			q.push(make_pair(i,j));
			path[i][j][i][j] = 0;
			//cout << i << " " << j <<endl;
			while(!q.empty()){
				ii current = q.front();
				//cout << current.first <<" " << current.second <<"\n";
				q.pop();
				for(int counter = 0; counter < 8; counter++){
					int a = current.first + kr[counter], b = current.second + kc[counter];
					if(a >= 0 && a< r && b>= 0 && b < c && path[i][j][a][b] ==-1){
						path[i][j][a][b] = path[i][j][current.first][current.second]+1;
					//	cout << i << " " << j << " " << a <<" " <<b << " Cost: " << path[i][j][a][b]<<"\n";
						q.push(make_pair(a,b));
					}
				}
			}
		}
	}
	for(int i = 0; i < r; i ++){
		for(int j = 0; j < c; j ++){
			for(int k = 0; k < n; k ++){
				knightCosts[i][j]+= path[i][j][knights[k].first][knights[k].second];
			}
		}
	}
	for(int i = 0; i < r; i ++){
		for(int j = 0; j < c; j ++){
			if(knightCosts[i][j] < 0) continue;
			if(knightCosts[i][j] > minKingCost) continue;
			int kcost = knightCosts[i][j], bestNewWeight = 200000000;
			for(int ii = 0; ii < r; ii++){
				for(int jj = 0; jj < c; jj++){
					for(int k = 0; k < n; k ++){
						if(path[ii][jj][knights[k].first][knights[k].second] < 0 || path[i][j][knights[k].first][knights[k].second] < 0) continue;
						int newWeight = kingPath[ii][jj]+ path[i][j][ii][jj]+path[ii][jj][knights[k].first][knights[k].second] - path[i][j][knights[k].first][knights[k].second];
						//cout << "i: " << i << " j: " << j << " II: " << ii << " JJ: " <<jj <<" "<<newWeight <<" " << kingPath[ii][jj]<< " "<<path[i][j][ii][jj] <<" " <<path[ii][jj][knights[k].first][knights[k].second] <<" " <<path[i][j][knights[k].first][knights[k].second]<<endl;
						if(newWeight < bestNewWeight) bestNewWeight = newWeight;
					}
				}
			}
			if(kingPath[i][j] < bestNewWeight) bestNewWeight = kingPath[i][j];
			kcost += bestNewWeight;
		//	cout << bestNewWeight <<" " << kcost <<"\n";
			if(kcost < minKingCost) minKingCost = kcost;
		}
	}
	cout << minKingCost <<"\n";
}
