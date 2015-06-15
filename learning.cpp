/*
 * learning.cpp
 *
 *  Created on: Dec 12, 2014
 *      Author: Sean
 */
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
void quickSort(ii arr[], int left, int right)
{
 int i = left, j = right;
 int tmp, t2;
 int pivot = arr[(left + right) / 2].first;

 /* partition */
 while (i <= j) {
       while (arr[i].first < pivot)
             i++;
       while (arr[j].first > pivot)
             j--;
       if (i <= j) {
             tmp = arr[i].first;
             t2 = arr[i].second;
             arr[i].first = arr[j].first;
             arr[i].second = arr[j].second;
             arr[j].first = tmp;
             arr[j].second = t2;
             i++;
             j--;
   }
}
if (left < j)
   quickSort(arr, left, j);
if (i < right)
       quickSort(arr, i, right);
}
int main(){
	freopen("learning.in","r",stdin);
	freopen("learning.out","w",stdout);
	int n, a, b, ans = 0;
	ii weights[50000];
	cin >> n >> a >> b;
	for(int i = 0; i < n; i ++){
		string a;
		cin >> a;
		if(a == "S") weights[i].second = 1;
		else weights[i].second = 0;
		cin >> weights[i].first;
	}
	quickSort(weights,0,n-1);
	for(int i = 0; i < n; i ++){
		int j = weights[i].first, k = weights[i+1].first, mi, ma;
		if(j > b){
			break;
		}
		if(j == k){
			if(weights[i].second == 1 || weights[i+1].second == 1){
				weights[i+1].second = 1;
			}
			continue;
		}
		if(j == b){
			if(weights[i].second == 1)ans ++;
			break;
		}
		int midpoint = (j+k)/2;
		if(i == 0 && j > a && j <= b) ans += j - a;
		if(k <= a) continue;
		mi = (j > a)? j : a;
		ma = (k < b)? k : b;
		//cout << midpoint << " " << mi << " " << ma << " ";
		if(midpoint > b){
			if(weights[i].second == 1) ans +=  b - mi + 1;
		}else if(midpoint < a){
			if(weights[i+1].second == 1) ans += ma - a;
		}else{
			if((j - k)%2 == 0){
				if(weights[i].second == 1)ans += midpoint - mi ;
				if(weights[i+1].second == 1) ans += ma - (midpoint) - 1;
				if(weights[i].second == 1 || weights[i+1].second == 1) ans ++;
			}else{
				if(weights[i].second == 1 )ans += midpoint - mi + 1;
				if(weights[i+1].second == 1) ans += ma - midpoint - 1;
			}
			if(k > b && weights[i+1].second == 1) ans ++;
		}
		//cout << ans << "\n";
	}
	cout << ans;

}



