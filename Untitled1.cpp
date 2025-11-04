#include<bits/stdc++.h>
using namespace std;

int main(){
	int cnt = 0;
	for(int i = 1000 ; i <= 5000; i++){
		if(i  % 6 == 0  || i % 9 == 0) cnt++;
	}
	cout << cnt;	
}
