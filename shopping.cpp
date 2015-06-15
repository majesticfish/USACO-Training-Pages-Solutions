/*
ID: yusean11
LANG: C++
TASK: shopping
 */
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int prices[6][6][6][6][6], s, b, n, codes[5], quantities[5], defaultPrices[5];
class offer{
public:
	vector<ii> items;
	int price;
};
int main(){
	offer offers[104];
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin >> s;
	for(int i = 0; i < s; i ++){
		cin >> n;
		offer o;
		vector<ii> items;
		for(int j = 0; j < n; j ++){
			ii temp;
			cin >> temp.first >> temp.second;
			items.push_back(temp);
		}
		o.items = items;
		cin >> o.price;
		offers[i] = o;
	}
	cin >> b;
	for(int i = 0; i < b; i ++){
		offer o;
		cin >> codes[i] >> quantities[i] >> defaultPrices[i];
		o.items.push_back(make_pair(0,0));
		o.items.push_back(make_pair(i,1));
		o.price = defaultPrices[i];
		offers[s++] = o;
	}
	for(int i = 0; i < s; i ++){
		for(int j = 0; j < offers[i].items.size(); j ++){
			for(int k = 0; k < b; k ++){
				if(offers[i].items.at(j).first == codes[k]){
					offers[i].items.at(j).first = k;
					break;
				}
				if(k == b-1){
					offers[i].items.erase(offers[i].items.begin()+j);
				}
			}
		}
	}
	for(int a = 0; a < 6; a ++) for(int b = 0; b < 6; b++) for(int c = 0; c < 6; c++) for(int d = 0; d < 6; d++) for(int e = 0; e < 6; e ++) prices[a][b][c][d][e] = 200000000;
	int min = 0;
	prices[0][0][0][0][0] = 0;
	for(int i1 = 0; i1 < 6; i1++){
		for(int i2 = 0; i2 < 6; i2 ++){
			for(int i3 = 0; i3 < 6; i3++){
				for(int i4 = 0; i4 < 6; i4++){
					for(int i5 = 0; i5 < 6; i5++){
						for(int i = 0; i < s; i ++){
							int a[] = {i1,i2,i3,i4,i5};
							for(int j = 0; j < offers[i].items.size(); j++){
								ii pair = offers[i].items.at(j);
								//cout << "Offer Number: " << i << " Item Number: " << j << " Item Index: " << pair.first <<" Item Quantity: " << pair.second <<" Price " << offers[i].price <<"\n";
								if(a[pair.first] - pair.second >= 0){
									a[pair.first]-= pair.second;
								}else
									break;
							}
							if(prices[a[0]][a[1]][a[2]][a[3]][a[4]] + offers[i].price < min)
								min = prices[a[0]][a[1]][a[2]][a[3]][a[4]] + offers[i].price;
							//cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] <<" min: " << min <<"\n";
						}
						prices[i1][i2][i3][i4][i5] = min;
						min= 20000000;
					}
				}
			}
		}
	}
	cout << prices[quantities[0]][quantities[1]][quantities[2]][quantities[3]][quantities[4]] <<"\n";
}



