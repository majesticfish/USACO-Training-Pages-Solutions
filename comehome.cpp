/*
ID: seanyu11
LANG: C++
PROB: comehome
 */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int p, paths[52][52], INF = 2000000000, lengths[52], b = INF, c = 13, m;
string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool visit[52];
int main(){
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	cin >> p;
	for(int i = 0; i < 52; i++){
		for(int j = 0; j < 52; j ++){
			paths[i][j] = INF;
		}
		lengths[i] = INF;
		visit[i] = false;
	}
	for(int i = 0; i < p; i ++){
		char q,p;
		cin >> q >> p;
		cin >> m;
		if(m < paths[a.find(p)][a.find(q)]){
			paths[a.find(q)][a.find(p)] = m;
			paths[a.find(p)][a.find(q)] = paths[a.find(q)][a.find(p)];
		}
	}
	lengths[51] = 0;
	for(int i = 0; i < 52; i ++){
		int m = INF, p = 51;
		for(int j = 0; j < 52; j ++){
			if(!visit[j]&&lengths[j] < m){
				m = lengths[j];
				p = j;
			}
		}
		visit[p] = true;
		for(int j = 0; j < 52; j ++){
			if(j == p) continue;
			if(lengths[p]+paths[p][j] < lengths[j]) lengths[j] = lengths[p]+paths[p][j];
		}
	}
	for(int i = 26; i < 51; i ++){
		if(lengths[i] < b){
			b = lengths[i];
			c = i;
		}
	}
	cout << a.at(c) << " " << b << "\n";
}


