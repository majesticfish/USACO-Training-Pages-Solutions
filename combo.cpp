/*
ID: seanyu11
LANG: C++
PROB: combo
 */
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int a[2][3], n, counter = 0;
	cin >> n >> a[0][0] >> a[0][1] >> a[0][2] >> a[1][0] >> a[1][1] >> a[1][2];
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			for(int k = 0; k < n; k ++){
				int v1 = (a[0][0]-i+n)%n, v2 = (a[0][1]-j+n)%n, v3 = (a[0][2]-k+n)%n, v4 = (a[1][0]-i+n)%n, v5 = (a[1][1]-j+n)%n, v6 = (a[1][2]-k+n)%n;
				if(((v1 <= 2 || v1 >= n-2)&&(v2 <= 2 || v2 >= n-2)&&(v3 <= 2 || v3 >= n-2))||((v4 <= 2 || v4 >= n-2)&&(v5 <= 2 || v5 >= n-2)&&(v6 <= 2 || v6 >= n-2)))
					counter ++;
			}
		}
	}
	cout << counter << "\n";
}



