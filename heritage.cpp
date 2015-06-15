/*
ID: yusean11
LANG: C++
TASK: heritage
 */
#include <iostream>
#include <stdio.h>
using namespace std;
struct binaryTree{
public:
	char root;
	binaryTree* left = NULL;
	binaryTree* right = NULL;
};
void makeTree(binaryTree& a, string inOrder, string preOrder){
	if(inOrder.size() == 0 || preOrder.size()== 0)
		return;
	a.root = preOrder[0];
	binaryTree left, right;
	a.left = &left;
	a.right = &right;
	makeTree(*a.left, inOrder.substr(0,inOrder.find(a.root)),preOrder.substr(1, inOrder.find(a.root)));
	makeTree(*a.right, inOrder.substr(inOrder.find(a.root)+1,inOrder.size()-inOrder.find(a.root)-1),preOrder.substr(inOrder.find(a.root)+1, preOrder.size()-1-inOrder.find(a.root)));
	cout << a.root;
}
int main(){
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	string in, pre;
	cin >> in >> pre;
	binaryTree solution, dummy;
	makeTree(solution,in,pre);
	cout << endl;
}



