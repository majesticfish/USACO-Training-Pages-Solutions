/*
ID: seanyu11
LANG: C++
PROB: maze1
 */
#include <iostream>
#include <fstream>
using namespace std;
int w,h,INF = 2000000000, great[2], weight[3800], c = 0, answer =0;
bool vert[100][39], hor[101][38], visited[3800];
int main(){
	ifstream in ("maze1.in");
	ofstream out ("maze1.out");
	char line[101];
	for(int i = 0; i < 101; i ++){
		for(int j = 0; j < 39; j++){
			vert[i][j] = false; hor[i][j] = false;
		}
	}
	for(int i = 0; i < 3800; i ++){
		weight[i] = INF; visited[i] = true;
 	}
	in >> w >> h;
	in.getline(line,2*w+1);
	for(int i = 0; i < h; i ++){
		in.getline(line,2*w+2);
		for(int j = 1; j < 2*w+1; j += 2){
			if(line[j] == '-'){ hor[i][(j-1)/2] = true;}
			if(line[j] == ' ' && i == 0){ great[c] = (j-1)/2; c++;}
		}
		in.getline(line,2*w+2);
		for(int j = 0; j < 2*w+1; j += 2){
			if(line[j] == '|') vert[i][j/2] = true;
			if(line[j] == ' ' && (j == 0||j==2*w)){	great[c] = (j == 0)? i*w : i*w+w-1;c++;}
		}
	}
	in.getline(line,2*w+2);
	for(int j = 1; j < 2*w+1; j += 2){
		if(line[j] == '-') hor[h][(j-1)/2] = true;
		if(line[j] == ' '){ great[c] = (j-1)/2 + w*(h-1); c++;}
	}
	weight[great[0]] = 1; weight[great[1]] = 1;
	for(int i = 0; i < h*w; i ++){
		int m = INF, interest;
			for(int j = 0; j < w*h; j ++){
				if(visited[j] && weight[j] < m){interest = j; m = weight[j];}
			}
			if(interest%w != 0 && !vert[(interest - interest%w)/w][interest%w] && weight[interest - 1] > weight[interest] + 1){
				weight[interest - 1] = weight[interest] + 1;
			}
			if(interest%w != w-1 && !vert[(interest - interest%w)/w][interest%w+1] && weight[interest+1]>weight[interest]+1){
				weight[interest+1] = weight[interest]+1;
			}
			if(interest-w >= 0 && !hor[(interest - interest%w)/w][interest%w] && weight[interest-w] > weight[interest]+1){
				weight[interest-w] = weight[interest] + 1;
			}
			if(interest+w < w*h && !hor[(interest - interest%w)/w+1][interest%w]&&weight[interest+w] > weight[interest]+1){
				weight[interest+w] = weight[interest] + 1;
			}
			visited[interest] = false;
	}
	for(int i = 0; i < w*h; i ++){
		if(weight[i] > answer) answer = weight[i];
	}
	out << answer << "\n";
}



