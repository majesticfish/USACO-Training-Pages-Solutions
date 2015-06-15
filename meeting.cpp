/*
 * meeting.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Sean
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> ii;
bool bes[10000], el[10000], solution = true;
int main(){
	freopen("meeting.in","r",stdin);
	freopen("meeting.out","w",stdout);
	int n,m, bessie[101][101], elsie[101][101];
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			bessie[i][j] = -1;
			elsie[i][j] = -1;
		}
	}
	for(int i = 0; i < 10000; i ++){
		bes[i] = false;
		el[i] = false;
	}
	for(int i = 0; i < m; i ++){
		int x,y,b,e;
		cin >> x >> y >> b>> e;
		bessie[x][y] = b;
		bessie[y][x] = b;
		elsie[x][y] = e;
		elsie[y][x] = e;
	}
	for(int i = 1; i < 10000; i ++){
		bool b = false, e = false;
		stack<ii> one, two;
		one.push(make_pair(1,0));
		while(!one.empty()){
			ii current = one.top();
			one.pop();
			if(current.second > i) continue;
			if(current.first == n && current.second == i){
				b = true;
				break;
			}
			for(int i = current.first + 1; i <= n; i ++){
				if(bessie[current.first][i] > 0) one.push(make_pair(i,bessie[current.first][i] +current.second));
			}
		}
		two.push(make_pair(1,0));
		while(!two.empty()){
					ii current = two.top();
					two.pop();
					if(current.second > i) continue;
					if(current.first == n && current.second == i){
						e = true;
						break;
					}
					for(int i = current.first + 1; i <= n; i ++){
						if(elsie[current.first][i] > 0) two.push(make_pair(i,elsie[current.first][i] +current.second));
					}
				}
		if(b && e){
			solution = false;
			cout << i;
			break;
		}
	}
	if(solution) cout << "IMPOSSIBLE";
}



