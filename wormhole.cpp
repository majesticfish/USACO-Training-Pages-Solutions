/*
ID: seanyu11
LANG: C++
PROB: wormhole
 */
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef pair<int,int> ii;
int next[12], n, wormhole[12], ways = 0;;
ii holes[12];
bool assigned[12];
void iterate(int a){
	if(a == n/2){
		for(int i = 0; i < n; i ++){
			int c = i;
			while(c != -1){
				if(assigned[c]) c  = wormhole[c];
				else break;
				c = next[c];
				if(c == i){
					ways ++;
					i = n;
					break;
				}
			}
		}
	}else{
		for(int i = 0; i < n; i ++){
			if(!assigned[i]){
				assigned[i] = true;
				for(int j = i+1; j < n; j ++){
					if(!assigned[j]){
						assigned[j] = true;
						wormhole[i] = j;
						wormhole[j] = i;
						iterate(a+1);
						assigned[j] = false;
					}
				}
				assigned[i] = false;
				break;
			}
		}
	}
}
int main(){
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> holes[i].first >> holes[i].second;
		assigned[i] = false;
		wormhole[i] = -1;
	}
	for(int i = 0; i < n; i ++){
		int m = 2000000000, s = -1;
		for(int j = 0; j < n; j ++){
			if(j == i) continue;
			if(holes[i].second == holes[j].second && holes[i].first < holes[j].first && holes[j].first < m){
				m = holes[j].first;
				s = j;
			}
		}
		next[i] = s;
	}
	iterate(0);
	cout << ways << "\n";
}



