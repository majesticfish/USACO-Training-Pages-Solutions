/*
ID: yusean11
LANG: C++
TASK: spin
 */
#include <iostream>
#include <stdio.h>
using namespace std;
typedef pair<int, int> ii;
int main(){
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	ii a[5][6];
	for(int i = 0; i < 5; i ++){
		cin >> a[i][0].first >> a[i][0].second;
		for(int j = 0; j <a[i][0].second; j++){
			cin >> a[i][j+1].first >> a[i][j+1].second;
		}
	}
	for(int i = 0; i < 360; i ++){
		if(i > 0){
			for(int j = 0; j < 5; j++){
				for(int k = 1; k <= a[j][0].second; k++){
					a[j][k].first +=a[j][0].first;
					a[j][k].first %= 360;
				}
			}
		}
		bool u = false;
		for(int j = 0; j < 360; j++){
			bool works = true;
			for(int k = 0; k < 5; k++){
				bool q = false;
				for(int l = 1; l <= a[k][0].second; l++){
					if((j - a[k][l].first + 360)%360 <= a[k][l].second){
						q = true;
						break;
					}
				}
				if(!q) works = false;
			}
			u = works;
			if(u){
				cout << i << "\n";
				return 0;
			}
		}
	}
	cout << "none\n";
}



