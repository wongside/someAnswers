#include <iostream>
#include <cstring>
#include <cmath> 
using namespace std;

struct Tree{
	
	struct Tree * left;
	struct Tree * right;
	char value;
	
	Tree(){
	}
	
	Tree(Tree * left, Tree * right, char value){
		this->left = left;
		this->right = right;
		this->value = value;
	}	
};

Tree * trees[1030];

void postorder(Tree * tree){ 
	if(tree->left != NULL){
		postorder(tree->left);
	}
	if(tree->right != NULL){
		postorder(tree->right);
	}
	cout << tree->value;
}

int main(){
	int n, len;
	string s;
	cin >> n >> s;
	len = s.length();
	
	for(int i = 0; i < len; i++){
		Tree * t = new Tree(NULL, NULL, s[i] == '0' ? 'B' : 'I');
		trees[i] = t;
	}
	
	for(int i = n; i > 0; i--){
		int s = 1 << (i-1);
		for(int j = 0; j < s; j++){		
			Tree * t = new Tree(NULL, NULL, 'F');	
			t->left = trees[2*j];
			t->right = trees[2*j+1];
			if((t->left)->value == (t->right)->value){				
				t->value = (t->left)->value;				
			}
			trees[j] = t;
		}
		
	}
	
	postorder(trees[0]);
	
	return 0;
}
