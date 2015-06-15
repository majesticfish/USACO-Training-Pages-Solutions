/*
ID: seanyu11
LANG: C++
PROB: cowtour
 */
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stdio.h>
using namespace std;
typedef pair<int,int> ii;
ii points[150];
long long n, regions[150], r = 0, INF = 200000000,counter = 0;
double adjacencies[150][150], diameter[150], ans = INF, maxil[150];
int main(){
	ifstream in ("cowtour.in");
	ofstream out ("cowtour.out");
	in >> n;
	for(int i = 0; i < n; i ++){
		in >> points[i].first >> points[i].second;
		regions[i] = 0;
		adjacencies[i][i] = 0;
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			char a;
			in >> a;
			if(a == '0') adjacencies[i][j] = INF;
			else adjacencies[i][j] = sqrt((points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second));
		}
		adjacencies[i][i] = 0;
		maxil[i] = 0;
	}
	queue<int> q;
	while(counter < n){
		if(q.empty()) for(int i = 0; i < n; i ++) if(regions[i] == 0){
			q.push(i);
			break;
		}
		int c = q.front();
		if(regions[c] == 0){
			regions[c] = ++r;
		}
		for(int j = 0; j < n; j ++) if(adjacencies[c][j] < INF && regions[j] == 0){
			regions[j] = regions[c];
			q.push(j);
		}
		q.pop();
		counter ++;
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			for(int k = 0; k < n; k ++){
				if(j == i || k == i) continue;
				if(adjacencies[j][k] > adjacencies[j][i]+adjacencies[i][k]) adjacencies[j][k] =  adjacencies[j][i]+adjacencies[i][k];
			}
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j++){
			if(adjacencies[i][j] > maxil[i] && adjacencies[i][j]< 200000000) maxil[i] = adjacencies[i][j];
		}
	}
	for(int i = 1; i <= r; i ++){
		double max = 0;
		for(int j = 0; j < n; j ++){
			if(regions[j] == i){
				if(maxil[j] > max) max = maxil[j];
			}
		}
		diameter[i] = max;
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(i == j || regions[i] == regions[j]) continue;
			double a = (diameter[regions[i]]>diameter[regions[j]])? diameter[regions[i]]:diameter[regions[j]];
			double d = sqrt((points[i].first - points[j].first)*(points[i].first - points[j].first) +
					(points[i].second - points[j].second)*(points[i].second - points[j].second));
			d = d+maxil[i]+maxil[j];
			a = (a>d)? a: d;
			if(a < ans) ans = a;
		}
	}
	long long f = ans;
	out << f << ".";
	double i = ans * 1000000;
	f = i;
	if(i - f >= 0.5) f++;
	f = f%1000000;
	int b = (f>0)? log10(f)+1: 1;
	for(int i = 0; i < 6-b; i++){
		out << '0';
	}
	out << f <<"\n";
}
