/*
ID: yusean11
LANG: C++
TASK: range
 */
#include <iostream>
#include <stdio.h>
using namespace std;
int n;
bool squares[250][250][2];
int main(){
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			char a;
			cin >> a;
			squares[i][j][1] = (a=='1');
		}
	}
	for(int i = 2; i <= n; i ++){
		int counter = 0;
		for(int j = 0; j < n+1-i; j ++){
			for(int k = 0; k < n+1-i; k ++){
				if(squares[j][k][(i-1)%2] && squares[j+1][k][(i-1)%2] && squares[j][k+1][(i-1)%2] && squares[j+1][k+1][(i-1)%2]){
					squares[j][k][i%2] = true;
					counter++;
				}else
					squares[j][k][i%2] = false;
			}
		}
		if(counter > 0)
			cout << i <<" " << counter <<"\n";
	}
}



