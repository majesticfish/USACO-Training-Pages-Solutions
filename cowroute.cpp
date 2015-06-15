/*
 * cowroute.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Sean
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef pair<long long, int> li;
li paths[1000][1000];
int main(){
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out","w",stdout);
	int a,b,n,cost,flight, temp;
	cin >> a >> b >> n;
	for(int i = 0; i < 1000; i ++){
		for(int j = 0; j < 1000; j ++){
			paths[i][j].first = pow(2,62)-1;
			paths[i][j].second = 0;
		}
	}
	for(int i = 0; i < n; i++){
		vector<int> f;
		cin >> cost >> flight;
		for(int j = 0; j < flight; j ++){
			cin >> temp;
			f.push_back(temp);
		}
		for(int j = 0; j < flight; j ++){
			temp = f.at(j);
			for(int k = j; k < flight; k ++){
				if(paths[temp-1][f.at(k)-1].first > cost){
					paths[temp-1][f.at(k)-1].first = cost;
					paths[temp-1][f.at(k)-1].second = k-j;
				}
			}
		}
	}
	bool visited[1000];
	li costs[1000];
	for(int i = 0; i < 1000; i ++){
		visited[i] = false;
		costs[i].first = pow(2,62);
		costs[i].second = 0;
	}
	costs[a-1].first = 0;
	for(int i = 0; i < 1000; i ++){
		long long min  = pow(2,62), target;
		for(int j = 0; j < 1000; j ++){
			if(!visited[j] && (costs[j].first < min)){
				min = costs[j].first;
				target = j;
			}
		}
		visited[target] = true;
		for(int j = 0; j < 1000; j ++){
			if(costs[target].first + paths[target][j].first < costs[j].first){
				costs[j].first = costs[target].first + paths[target][j].first;
				costs[j].second = costs[target].second + paths[target][j].second;
			}else if(costs[j].first == costs[target].first + paths[target][j].first){
				if(costs[j].second > costs[target].second + paths[target][j].second)
					costs[j].second = costs[target].second + paths[target][j].second;
			}
		}
	}
	cout << costs[b-1].first << " " << costs[b-1].second;
}



