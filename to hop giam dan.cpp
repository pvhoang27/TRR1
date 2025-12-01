#include<bits/stdc++.h>
using namespace std;

int n, k;
int A[50], C[50], idx[50];

void in(){
    for(int i = 1; i <= k; i++){
        cout << C[i] << " ";
    }
    cout << endl;
}

void quaylui(int i){
    // ch?n ti?p ph?n t? th? i
    for(int j = idx[i-1] + 1; j <= n; j++){
        // n?u là ph?n t? d?u ho?c giá tr? gi?m d?n
        if(i == 1 || A[j] < C[i-1]){
            C[i] = A[j];   // luu giá tr?
            idx[i] = j;    // luu v? trí d? không ch?n lùi

            if(i == k) in();
            else quaylui(i+1);
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> A[i];

    idx[0] = 0;  // d? b?t d?u t? ph?n t? d?u
    quaylui(1);
}

