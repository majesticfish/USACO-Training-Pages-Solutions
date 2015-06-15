/*
ID: yusean11
LANG: C++
TASK: kimbits
 */
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
long long n,L,I, c = 0, ans, start;
long long choose(int n, int p){
	if(n > p)
		return 0;
	if(n > p/2)
		return choose(p-n, p);
	long long ans = 1;
	for(int i = 0; i < n; i ++){
		ans *= (p-i);
		ans /= (i+1);
	}
	return ans;
}
string decent(int n, int l){
	long long sum = 0;
	if(n == 1){
		if(I == 1) return "0";
		else return "1";
	}
	for(int i = 0; i <= l; i++){
		sum += choose(i,n-1);
	}
	if(sum >= I){
		return "0"+decent(n-1,l);
	}else{
		I -= sum;
		return "1"+decent(n-1,l-1);
	}
}
int main(){
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	cin >> n >> L >> I;
	cout << decent(n,L) << "\n";
}



