/*
 * test.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Sean
 */

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	pii a;
	cin >> a.first >> a.second;
	vector<pii> v;
	v.push_back(a);
	cout << v[0].first;
}
