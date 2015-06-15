/*
ID: yusean11
LANG: C++
TASK: ratios
 */
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	int ratios[3][3], first, second, third, min = 20000000, ans1, ans2, ans3, ans4;
	cin >> first >> second >> third;
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 3; j++){
			cin >> ratios[i][j];
		}
	}
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			for(int k = 0; k < 100; k++){
				int a = i*ratios[0][0]+j*ratios[1][0]+k*ratios[2][0], b = i*ratios[0][1]+j*ratios[1][1]+k*ratios[2][1], c = i*ratios[0][2]+j*ratios[1][2]+k*ratios[2][2];
				if(a >= first &&b >= second && c >= third){
					if(a*second == b*first && b*third == c*second && (i+j+k)<min){
						min = i+j+k;
						ans1 = i;
						ans2 = j;
						ans3 = k;
						ans4 = a/first;
					}
				}
			}
		}
	}
	if(min != 20000000)cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << "\n";
	else cout << "NONE\n";
}



