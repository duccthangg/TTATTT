/*
Tìm nghịch đảo của một số a trong trường F_p với a và p được nhập từ bàn phím.
*/
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
        return (x % phi + phi) % phi;
    }
    else return 0;
}
int main(){
    int a, p;
    cout << "nhap a va p: ";
    cin >> a >> p;
    int result = find_divE(a,p);
    cout << "Ket qua nghich dao cua a la: " << result;
    return 0;
}