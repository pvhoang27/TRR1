#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n == 1) {
        cout << "a1 = 2";
        return 0;
    }

    long long a1 = 2, a2 = 3, an;
    for (int i = 3; i <= n; i++) {
        an = a1 + a2;
        a1 = a2;
        a2 = an;
    }

    cout << "a" << n << " = " << an << endl;
    return 0;
}

