/*
ID: yusean11
LANG: C++
TASK: stamps
 */
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	int k ,n,values[50], max = 0, ans = 0;
	int* a = new int[2000001];
	bool b[2000001];
	cin >> k >> n;
	for(int i = 0; i < n; i ++){
		cin >> values[i];
		if(values[i] > max)
			max = values[i];
	}
	max = max*k;
	ans = max;
	for(int i = 0; i <= max; i ++){
		b[i+1] = false;
		a[i+1] = 20000000;
	}
	b[0] = true;
	a[0] = 0;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j <= max; j ++){
			if(b[j]&& a[j] < k){
				b[j+values[i]] = true;
				if(1+a[j]<a[j+values[i]])
					a[j+values[i]] = a[j]+1;
	//			cout << i << " " << j << " " << j+values[i] << "\n";
			}
		}
	}
	for(int i = 0; i < max; i ++){
		if(!b[i]){
			ans = i-1;
			break;
		}
	}
	cout << ans << "\n";
}



