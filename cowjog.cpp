/*
 * cowjog.cpp
 *
 *  Created on: Dec 12, 2014
 *      Author: Sean
 */
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
int main(){
	freopen("cowjog.in","r",stdin);
	freopen("cowjog.out","w",stdout);
	int n, minSpeed = 2000000000, ans = 0;
	ii a[100000];
	cin >> n;
	ans = n;
	for(int i = 0; i < n; i ++){
		cin >> a[i].first >> a[i].second;
		if(a[i].second < minSpeed) minSpeed = a[i].second;
	}
	for(int i = n - 2; i >=  0; i --){
		if(a[i].second > a[i+1].second){
			a[i].second = a[i+1].second;
			ans --;
		}
	}
	cout << ans;
}



