#include<bits/stdc++.h>
using namespace std;
int a[25], n ; 
void in(){
	// bau dau = 1
	for(int i = 1 ; i <= n; i ++ ) cout<< a[i] << " ";
	cout<<endl;
}
void Try(int i ){
	for(int j = 0 ; j <= 1; j++){
		a[i] = j;
		if(i == n) in();
		else Try(i + 1);
	}
}
int main(){
	cin >> n;
	// bat dau tu 1
	Try(1);
}
