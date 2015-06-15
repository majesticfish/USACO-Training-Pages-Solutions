/*
ID: seanyu11
LANG: C++
TASK: fact4
 */
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	int n, a = 1, t[] ={2,4,8,6};
	cin >> n;
	for(int i = 1; i <= n; i++){
		int j = i;
		if(j%10 == 0){
			while(j%10 == 0)
				j /= 10;
		}
		if(j%5 == 0){
			int counter = 0;
			while(j%5 == 0){
				j /= 5;
				counter ++;
			}
			for(int j = 0; j < counter; j ++){
				if(a==2) a = 6;
				else if(a == 4) a = 2;
				else if(a == 8) a = 4;
				else if(a == 6) a = 8;
			}
			a *= j;
		}else{
			a*= j;
		}
		a = a%10;
	//	cout << i << " " << a << " \n";
	}
	cout << a <<"\n";
}



