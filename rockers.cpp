/*
ID: yusean11
LANG: C++
TASK: rockers
 */
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	int n,t,m, space[20], lengths[20], max = 0;
	cin >> n >> t >> m;
	for(int i = 0; i < n; i ++) cin >> lengths[i];
	for(int i = 0; i < pow(2,n); i ++){
		for(int j = 0; j < m; j ++) space[j] = t;
		int temp = i, placeHolder = 0, counter = 0;
		//cout << i << ":\n";
		for(int j = 0; j < n; j ++){
			bool e = (temp%2)!=0;
			//cout << temp << "\n";
			temp = temp/2;
			if(!e) continue;
			counter++;
		//	co	ut << j << " " << placeHolder << " " << space[placeHolder] <<"\n";
			while(space[placeHolder] < lengths[j]){
				placeHolder++;
				if(placeHolder >= m) break;
			}
			if(placeHolder== m) break;
			space[placeHolder] -= lengths[j];
		}
		if(placeHolder==m) continue;
		if(counter > max) max = counter;
	}
	cout << max <<"\n";
}
