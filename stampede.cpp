/*
 * stampede.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Sean
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> ii;
typedef pair<int, ii> cow;
bool compare(cow a, cow b){
	return(a.first < b.first);
}
bool sec[10000000];
int main(){
	freopen("stampede.in","r",stdin);
	freopen("stampede.out","w",stdout);
	int n, count = 0;
	vector<cow > cows;
	vector<ii> blocked;
	cin >> n;
	for(int i = 0; i < n; i ++){
		int x,y, time;
		cin >> x >> y >> time;
		ii temp = make_pair(x,time);
		cows.push_back(make_pair(y,temp));
	}
	sort(cows.begin(),cows.end(),compare);
	for(int i = 0; i < n; i ++){
		ii current, range;
		current = cows.at(i).second;
		range = make_pair(-(current.first+1)*current.second,-(current.first)*current.second);
		bool seen = false;
		for(long long j = range.first; j <= range.second; j ++){
			if(!sec[j]){
				seen = true;
				sec[j] = true;
			}
		}
		if(seen)count ++;
	}
	cout << count;
}



