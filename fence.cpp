/*
ID: yusean11
TASK: fence
LANG: C++
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int f, answer[1024], connections[500], higherOdd, lowerOdd = 2000000, index = 0, fences[500][500] ;
bool hasOdd = false;
void findCircuit(int a) {
	if(connections[a] == 0) answer[index++] = a;
	else{
	for(int i = 0; i < 500; i ++){
		if(fences[a][i] > 0){
			fences[a][i]--;
			fences[i][a]--;
			findCircuit(i);
		}
	}
	answer[index++] = a;
	}
}
int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin >> f;
	for (int i = 0; i < 500; i++) {
		connections[i] = 0;
		for (int j = 0; j < 500; j++) fences[i][j] = 0;
	}
	for (int i = 0; i < f; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		fences[temp1 - 1][temp2 - 1] ++;
		fences[temp2 - 1][temp1 - 1] ++;
		connections[temp1 - 1]++;
		connections[temp2 - 1]++;
	}
	for(int i = 0; i < 500; i ++){
		if(connections[i]%2 == 1){
			findCircuit(i);
			break;
		}
		if(i == 499) findCircuit(0);
	}
	for(int i = index-1; i >= 0; i --){
		cout << answer[i] +1<<"\n";
	}
}
