/*
/*
 * crosswords.cpp
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
	freopen("crosswords.in","r",stdin);
	freopen("crosswords.out","w",stdout);
	int n, m, solutions = 0;
	char a[50][50];
	ii s[2500];
	cin >> n >> m;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++){
				if(a[i][j] == '.'){
					bool qo = false;
					if(j <=  m-3 && a[i][j+1] == '.' && a[i][j+2] == '.'){
						if(j == 0) qo = true;
						else if(a[i][j-1] == '#') qo = true;
					}
					if(i <= n - 3 && a[i+1][j] == '.' && a[i+2][j] == '.' ){
						if(i == 0) qo = true;
						else if(a[i-1][j] == '#') qo = true;
					}
					if (qo){
						s[solutions].first = i + 1;
						s[solutions].second = j + 1;
						solutions ++;
					}
			}
		}
	}
	cout << solutions << "\n";
	for(int i = 0; i < solutions; i ++){
		cout << s[i].first << " " << s[i].second << "\n";
	}
}






