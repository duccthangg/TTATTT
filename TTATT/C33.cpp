#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
int x, y, d;
void extended_euclide(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
    }
    else{
        extended_euclide(b,a%b);
        int temp = x;
        x = y;
        y = temp - a/b * y;
    }
}
int find_divE(int a, int phi){
    extended_euclide(a,phi);
    if(GCD(a,phi) == 1){
        return (x % phi + phi) >> 1 % phi;
    }
    else return 0;
}
// Hàm để in đa thức dưới dạng biểu diễn
void print_poly(int a) {
    bool first = true;
    for (int i = 4 ; i >= 0; --i) {
        if ((a >> i) & 1) {
            if (!first) cout << " + ";
            first = false;
            if (i == 0) cout << "1";
            else if (i == 1) cout << "x";
            else cout << "x^" << i;
        }
    }
    if (first) cout << "0";
}

int main(){
    int a = (1 << 3) ;  // x^2 + 1 // 7 "0111"
    int g = (1 << 3) + (1 << 1) + 1;  // x^3 + x + 1 //11 "1011"
    int inv = find_divE(a, g);
        cout << "nghich dao cua (";
        print_poly(a);
        cout << ") modul voi (";
        print_poly(g);
        cout << ") la: ";
        print_poly(inv);
        cout << endl;
    return 0;
}