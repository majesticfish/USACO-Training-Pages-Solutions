/*
ID: yusean11
LANG: C++
TASK: fence9
 */
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	int n,m,p, answer = 0;
	double slope1, slope2;
	cin >> n >> m >> p;
	slope1 = (double)n/m;
	slope2 = (double)(p-n)/m;
	//cout << slope1 << " " << slope2 << endl;
	for(double yDisplacement = 1; m-yDisplacement > 0; yDisplacement++){
		int lower = (int)(n - slope1*yDisplacement);
		int upper = ((p-n)*(int)yDisplacement%m == 0)? n+slope2*yDisplacement-1: n+slope2*yDisplacement;
		answer += (upper-lower);
		//cout << yDisplacement << " " << upper << " " << lower << endl;
	}
	cout << answer <<endl;
}



