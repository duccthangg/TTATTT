/*Viết chương trình đếm,in,tong số các số Carmichael
(là các số giả nguyên tố n thoả mãn điều kiện là hợp số và thoả mãn b^(n-1)≡1 (mod n) 
với mọi số nguyên dương b nguyên tố cùng nhau với n) nhỏ hơn một số N cho trước nhập vào từ bàn phím 
(với điều kiện 0≤N≤10000.*/

#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
bool isCarmichael(int n){
    if(CheckPrimeFermat(n)) return false;
    for(int b = 2; b < n; b++){
        // if(GCD(b,n) != 1) return false;
        // if(powIndia(b,n-1,n) != 1) return false;
        if(GCD(b,n) == 1){
            if(powIndia(b,n-1,n) != 1) return false;
        }
    }
    return true;
}
int main(){
    int n; cin >> n;
    int count = 0;
    long long SumC = 0;
    cout <<"Cau 28: ";
    if(n >= 0 && n <= 10000){
        for(int i = 2; i <= n; i++){
            if(isCarmichael(i)){
                cout << i << " ";
                count++;
                SumC += i;
            }
        }
    }
    cout << "\n";
    cout << "So luong so Carmichael: " << count << "\n";
    cout << "Tong so Carmichael: " << SumC;
    return 0;
}