#include<bits/stdc++.h>
using namespace std;
int a[25] , n ,k;
void in (){
	// nho la bat dau tu 1 va <= k nhe 
	for(int i = 1 ; i <= k ; i++) cout<< a[i] <<" ";
	cout <<endl;
}
void Try(int i){
	/// nho la j = a[i-1] + 1 nhe , va <= n - k + i 
	for(int j = a[i - 1] + 1 ; j <= n - k  + i ; j ++){
		a[i] = j;
		// nho la k nhe 
		if(i == k) in();
		else Try(i + 1);
	}
}
int main(){
	cin >> n >> k ;
	Try(1);
}
