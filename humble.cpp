/*
ID: yusean11

LANG: C++
TASK: humble
 */
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
unsigned int a[2][100001], k, n, l, m;
int main(){
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	cin >> k >> n >> l;
	int q = (int) log(pow(2,32)-1)/log(l);
	int m = (q > n)? n : q;
	for(unsigned int i = 1; i <= m; i++){
		a[0][i] = (int)pow(l,i);
	}
	a[1][0] = 1;
	a[0][0] = 1;
	for(unsigned int i = 1; i < k; i ++){
		unsigned int x = 1, y = 0,p;
		cin >> p;
		for(unsigned int j = 1; j <= n; j ++){
			if(x > m){
				m = j;
				break;
			}
			if(a[i%2][y]*p > a[(i+1)%2][x]){
				a[i%2][j] = a[(i+1)%2][x];
				x ++;
			}else if(a[i%2][y]*p < a[(i+1)%2][x]){
				a[i%2][j] = a[i%2][y]*p;
				y ++;
			}else{
				a[i%2][j] = a[i%2][y]*p;
				x ++;
				y ++;
			}
			if(j == n)
				m = n;
		}
	}
	cout << a[(k-1)%2][n] << "\n";
}



