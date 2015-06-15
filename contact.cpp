/*
ID: yusean11
LANG: C++
TASK: contact
 */

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main(){
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	int a,b,n,freq[13][4096],sh =0;
	cin >> a >> b >> n;
	bool t[b];
	for(int i = a; i <= b; i ++){
		for(int j = 0; j < pow(2,i); j ++) freq[i][j] = 0;
	}
	char c;
	while(cin >> c){
		t[sh] = (c=='1');
		sh ++;
		if(sh >= b)
			break;
	}
	int counter = 0;
	if(sh == b){
	for(int i = 1; i <= b; i ++){
		counter *= 2;
		counter += t[i-1]? 1:0;
		if(i >= a) freq[i][counter]++;
	}
	while(cin >> c){
		counter = 0;
		for(int i = 1; i < b; i++){
			t[i-1] = t[i];
		}
		t[b-1] = (c=='1');
		for(int i = 0; i < b; i ++){
			counter *= 2;
			counter += t[i]? 1:0;
			if(i >= a-1) freq[i+1][counter]++;
		}
	}
	for(int i = 1; i <= sh-a; i ++){
		counter = 0;
		for(int j = 1; j <= sh-i;j++){
			t[j-1] = t[j];
		}
		for(int j = 0; j < sh-i; j ++){
			counter *= 2;
			counter += t[j]? 1:0;
			if(j >= a-1) freq[j+1][counter]++;
		}
	}
	}else{
		for(int i = 0; i <= sh-a; i ++){
				counter = 0;
				if(i != 0){
				for(int j = 1; j <= sh-i;j++){
					t[j-1] = t[j];
				}
				}
				for(int j = 0; j < sh-i; j ++){
					counter *= 2;
					counter += t[j]? 1:0;
					if(j >= a-1) freq[j+1][counter]++;
				}
		}
	}
	int max[n+1];
	for(int k = 0; k < n; k ++){
		max[0] = 2000000000;
		int m = 0;
		for(int i = a; i <= b; i ++){
			for(int j = 0; j < pow(2,i); j ++){
				if(freq[i][j] > m && freq[i][j] < max[k]){;
					m = freq[i][j];
				}
			}
		}
		if(m == 0) break;
		max[k+1] = m;
		cout << m << "\n";
		int counter = 0;
		for(int i = a; i <= b; i ++){
			for(int j = 0; j < pow(2,i); j ++){
				if(freq[i][j] == m){
					if(counter%6 != 0) cout << " ";
					int c = j, helper[i];
					for(int q = 0; q < i; q ++){
						helper[i - q - 1] =  c%2;
						c -= c%2;
						c /= 2;
					}
					for(int q = 0; q < i; q ++) cout << helper[q];
					counter ++;
					if(counter %6 == 0) cout << "\n";
				}
			}
		}
		if(counter%6 != 0)cout << "\n";
	}
}


