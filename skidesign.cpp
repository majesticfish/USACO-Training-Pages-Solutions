/*
ID: seanyu11
LANG: C++
PROB: skidesign
 */
#include <iostream>
#include <stdio.h>
using namespace std;
int n, numbers[1000], minimum = 2000000000;
int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> numbers[i];
	}
	for(int i = 0; i + 17 <= 100; i ++){
		int sum = 0;
		for(int j = 0; j < n; j ++){
			if(numbers[j] < i) sum += (i-numbers[j])*(i-numbers[j]);
			if(numbers[j] > i + 17) sum += (numbers[j]-i-17)*(numbers[j]-i-17);
		}
		if(sum < minimum) minimum = sum;
	}
	cout << minimum <<"\n";
}



