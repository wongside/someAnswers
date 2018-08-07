#include <iostream>
#include <algorithm>
using namespace std;

int a[100000+10];

void quickSort(int a[], int l, int r){
	
	int i = l;
	int j = r-1;
	int x = a[i];
	if(i < j){
		while(i < j){
			while(i < j && a[j] > x){
				j--;
			}
			if(i < j){
				a[i++] = a[j];
			}
			while(i < j && a[i] < x){
				i++;
			}
			if(i < j){
				a[j--] = a[i];
			}			
		}		
		a[i] = x;
		quickSort(a, l, i);
		quickSort(a, i+1, r);				
	}	
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0; i < n; i++){
		cout << a[i];
		if(i < n-1){
			cout << " ";
		}else{
			cout << endl;
		}
	}
}
