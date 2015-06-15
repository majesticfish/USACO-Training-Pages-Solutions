/*
 ID: seanyu11
 LANG: C++
 TASK: butter
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef pair<int, int> ii;
bool visited[800];
int n, p, c, pastures[800], paths[800][800], ans = 20000000,
		finalDistances[800][800];
	int size = 0, indexToPos[800];
	ii heap[802];
	void swap(int i, int j) {
		int temp = heap[i].first;
		heap[i].first = heap[j].first;
		heap[j].first = temp;
		indexToPos[heap[i].second] = j;
		indexToPos[heap[j].second] = i;
		temp = heap[i].second;
		heap[i].second = heap[j].second;
		heap[j].second = temp;
	}
	void swim(int i) {
		if (i <= 1)
			return;
		int t = (int) i / 2;
		while (heap[i].first < heap[t].first) {
			swap(i, t);
			i = t;
			t = (int) i / 2;
		}
	}
	void sink(int i) {
		while (2 * i <= size
				&& (heap[i].first > heap[2 * i].first
						|| heap[i].first > heap[2 * i + 1].first)) {
			if ((heap[2 * i].first < heap[2 * i + 1].first)) {
				swap(i, 2 * i);
				i = 2 * i;
			} else if (2 * i + 1 <= size) {
				swap(i, 2 * i + 1);
				i = 2 * i + 1;
			}
		}
	}
	void add(ii value) {
		heap[++size] = value;
		indexToPos[value.second] = size;
		swim(size);
	}
	ii peek() {
		return heap[1];
	}
	ii pop() {
		ii r = heap[1];
		swap(1, size);
		heap[size--].first = 200000000;
		indexToPos[r.second] = 801;
		sink(1);
		return r;
	}
	bool isEmpty() {
		return size < 1;
	}
	void decreaseKey(int index, int newKey) {
		if(visited[index]) return;
		if (newKey < heap[indexToPos[index]].first)
			heap[indexToPos[index]].first = newKey;
		if (indexToPos[index] != 801)
			swim(indexToPos[index]);
	}
class path {
public:
	pair<int, int> v;
	int length;
};
int main() {
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	cin >> n >> p >> c;
	for (int i = 0; i < p; i++) {
		pastures[i] = 0;
		for (int j = 0; j < p; j++)
			paths[i][j] = 20000000;
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		pastures[temp - 1]++;
	}
	for (int i = 0; i < c; i++) {
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;
		paths[temp1 - 1][temp2 - 1] = temp3;
		paths[temp2 - 1][temp1 - 1] = temp3;
	}
	for (int i = 0; i < p; i++) {
		if (pastures[i] > 0) {
			for (int j = 0; j < p; j++) {
				add(make_pair(2000000, j));
				visited[j] = false;
			}
			decreaseKey(i, 0);
			for (int j = 0; j < p; j++) {
				ii minimum = pop();
				visited[minimum.second] = true;
				for (int k = 0; k < p; k++) {
					if(paths[minimum.second][k] < 20000000)
						decreaseKey(k,paths[minimum.second][k] + minimum.first);
				}
				finalDistances[i][minimum.second] = minimum.first;
				finalDistances[minimum.second][i] = minimum.first;
			}
		}
	}
	for(int i = 0; i < p; i ++){
		int cur = 0;
		for(int j = 0; j < p; j ++){
			cur += pastures[j] * finalDistances[i][j];
		}
		if(cur < ans)
			ans = cur;
	}
	cout << ans << "\n";
}

