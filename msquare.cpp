/*
ID: yusean11
LANG: C++
TASK: msquare
 */
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;
typedef pair<string,string> ss;
int a[9] = {0,1,2,6,24,120,720,5040,40320};
bool visit[40320];
string target = "12348765", paths[40320];
int permutationToInt(string p){
	bool visited[8];
	int ans  = 0;
	for(int i = 0; i < 8; i ++) visited[i] = true;
	for(int i = 0; i < 8; i ++){
		char current = p.at(i);
		int counter = 0;
		for(int j	 = 0; j < 8; j ++){
			if(!visited[j]) continue;
			if(target.at(j) == current){
				visited[j] = false;
				break;
			}
			counter ++;
		}
		ans += counter *= a[8-i-1];
	}
	return ans;
}
int main(){
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	ss starting, current;
	starting.first = "12348765";
	starting.second = "";
	queue<string> q1,q2;
	char p;
	target = "";
	while(cin >> p)	target += p;
	p = target[4];
	target[4] = target[7];
	target[7] = p;
	p = target[5];
	target[5] = target[6];
	target[6] = p;
	for(int i = 0; i < 40320; i ++) visit[i] = false;
	q1.push(starting.first);
	q2.push(starting.second);
	while(!q1.empty()){
		ss current;
		current.first = q1.front();
		current.second = q2.front();
		q1.pop();
		q2.pop();
		//cout << current.first << " " << current.second <<"\n";
		if(current.first == target){
			//cout <<"BOOYA";
			cout << current.second.length() << "\n";
			cout << current.second << "\n";
			break;
		}
		string c = current.first;
		for(int i = 0; i < 4; i ++){
			char temp = c.at(i);
			c[i] = c[i+4];
			c[i+4] = temp;
		}
		int place = permutationToInt(c);
		if(!visit[place]){
			visit[place] = true;
			paths[place] = current.second + "A";
			//cout << "YAY" <<" " << c << " " << paths[place] << "\n";
			q1.push(c);
			q2.push(paths[place]);
		}

		c = current.first;
		for(int i = 0; i < 2; i ++){
			char temp = c[i*4+3];
			for(int j = 3; j > 0; j --){
				c[i*4+j] = c[i*4+j-1];
			}
			c[i*4] = temp;
		}
		place = permutationToInt(c);
		if(!visit[place]){
			visit[place] = true;
			paths[place] = current.second + "B";
			q1.push(c);
			q2.push(paths[place]);
			//cout << "YAY" <<" " << c << " " << paths[place] << "\n";
		}

		c = current.first;
		char temp = c[2];
		c[2] = c[1];
		c[1] = c[5];
		c[5] = c[6];
		c[6] = temp;
		place = permutationToInt(c);
		if(!visit[place]){
			visit[place] = true;
			paths[place] = current.second + "C";
			q1.push(c);
			q2.push(paths[place]);
			//cout << "YAY" <<" " << c << " " << paths[place] << "\n";
		}
	}
}



