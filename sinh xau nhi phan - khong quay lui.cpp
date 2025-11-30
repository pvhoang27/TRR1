#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> B(n, 0);

    while(true){
        
        for(int x : B) cout << x << " ";
        cout << endl;

        
        int i = n - 1;
        while(i >= 0 && B[i] == 1){
            B[i] = 0;
            i--;
        }
        if(i < 0) break; 
        B[i] = 1;
    }
}

