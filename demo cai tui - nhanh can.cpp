#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Khai báo c?u trúc d? v?t d? d? s?p x?p
struct Item {
    int id;     // Ch? s? ban d?u c?a d? v?t
    int a;      // Tr?ng lu?ng (weight)
    int c;      // Giá tr? (cost/value)
    double don_gia; // Ðon giá = c/a
};

// Bi?n toàn c?c
int n;              // S? lu?ng d? v?t
float b;            // Tr?ng lu?ng t?i da c?a túi
Item items[100];    // M?ng ch?a các d? v?t
int x[100];         // Phuong án hi?n t?i dang xét (x[i] = 0 ho?c 1)
int Xopt[100];      // Phuong án t?i uu nh?t tìm du?c
float Fopt = -1.0;  // Giá tr? t?i uu (k? l?c) hi?n t?i

// Hàm so sánh d? s?p x?p d? v?t theo don giá gi?m d?n
bool compareItems(Item x, Item y) {
    return x.don_gia > y.don_gia;
}

// Hàm Nhánh c?n (Quay lui có dánh giá c?n)
// k: dang xét d? v?t th? k (dã s?p x?p)
// current_w: tr?ng lu?ng hi?n t?i trong túi
// current_v: giá tr? hi?n t?i trong túi
void Try(int k, float current_w, float current_v) {
    // Duy?t các kh? nang c?a d? v?t k: Nên th? ch?n (1) tru?c, không ch?n (0) sau
    // d? s?m tìm du?c phuong án t?t, giúp c?t t?a nhanh hon.
    for (int j = 1; j >= 0; j--) {
        
        x[k] = j; // Th? gán tr?ng thái j cho d? v?t k
        
        // Tính tr?ng lu?ng và giá tr? m?i n?u ch?n phuong án j
        float new_w = current_w + j * items[k].a;
        float new_v = current_v + j * items[k].c;

        // 1. Ki?m tra ràng bu?c tr?ng lu?ng
        if (new_w <= b) {
            
            // 2. N?u dã duy?t h?t n d? v?t (d?n lá c?a cây)
            if (k == n) {
                // C?p nh?t k? l?c n?u tìm du?c giá tr? l?n hon
                if (new_v > Fopt) {
                    Fopt = new_v;
                    // Luu l?i c?u hình t?i uu (theo ch? s? ban d?u)
                    for (int i = 1; i <= n; i++) {
                        Xopt[items[i].id] = x[i]; 
                    }
                }
            } 
            // 3. N?u chua h?t d? v?t, tính C?n trên (Upper Bound - g)
            else {
                // Công th?c c?n: g = Giá tr? hi?n t?i + (Tr?ng lu?ng còn l?i * Ðon giá v?t ti?p theo)
                float remaining_capacity = b - new_w;
                float g = new_v + remaining_capacity * items[k+1].don_gia;

                // 4. C?T T?A (Pruning): Ch? di ti?p n?u C?n g > K? l?c hi?n t?i (Fopt)
                if (g > Fopt) {
                    Try(k + 1, new_w, new_v);
                }
                // Ngu?c l?i, n?u g <= Fopt, ta c?t nhánh này (không g?i d? quy n?a)
            }
        }
    }
}

int main() {
    // 1. Nh?p d? li?u
    cout << "NHAP SO LUONG DO VAT n: ";
    cin >> n;
    cout << "NHAP TRONG LUONG TOI DA b: ";
    cin >> b;

    cout << "Nhap trong luong (a) va gia tri (c) cho tung vat:\n";
    for (int i = 1; i <= n; i++) {
        items[i].id = i; // Luu l?i s? th? t? ban d?u
        cout << "Vat " << i << " (trong luong, gia tri): ";
        cin >> items[i].a >> items[i].c;
        items[i].don_gia = (double)items[i].c / items[i].a;
    }

    // 2. S?p x?p các d? v?t theo don giá gi?m d?n
    // Luu ý: m?ng items tính t? ch? s? 1 d?n n, nên sort t? items+1 d?n items+n+1
    sort(items + 1, items + n + 1, compareItems);

    // In ra danh sách sau khi s?p x?p (d? ki?m tra)
    cout << "\n--- Danh sach sau khi sap xep giam dan don gia ---\n";
    cout << setw(5) << "ID" << setw(10) << "TrongLuong" << setw(10) << "GiaTri" << setw(10) << "DonGia" << endl;
    for (int i = 1; i <= n; i++) {
        cout << setw(5) << items[i].id 
             << setw(10) << items[i].a 
             << setw(10) << items[i].c 
             << setw(10) << items[i].don_gia << endl;
    }

    
    Try(1, 0, 0);

  
    cout << "\n---------------- KET QUA ----------------\n";
    cout << "Gia tri lon nhat (Fopt): " << Fopt << endl;
    cout << "Phuong an chon (Xopt): ";
    for (int i = 1; i <= n; i++) {
   
        cout << Xopt[i] << " "; 
    }
    cout << endl;
    cout << "Cac vat duoc chon la: ";
    for (int i = 1; i <= n; i++) {
        if (Xopt[i] == 1) cout << "Vat " << i << ", ";
    }
    cout << endl;

    return 0;
}
