/*Cho mảng A nhập từ bàn phím gồm các số nguyên dương. Hãy viết chương trình tìm các cặp số (i,j) 
trong mảng A sao cho ước chung lớn nhất của chúng là một số nguyên tố*/
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
int Array_a[1001];
int main(){
    int n; cout << "Nhap do dai mang A: "; cin >> n;
    cout << "Mang A la: ";
    srand(time(0));
   for(int i = 0; i < n; i++){
        Array_a[i] = rand() % 1000;
        cout << Array_a[i] << " ";
    }

     cout<<endl << "Cau 39: "<< endl;
      int count =0;
   for(int i = 0; i <= n - 1; i++)
   {
    for(int j = i + 1; j < n; j++){
        if(isPrime(GCD(Array_a[i],Array_a[j]),5)) {
            cout << "(" << Array_a[i] <<","<<Array_a[j]<<") = " <<GCD(Array_a[i],Array_a[j])<<endl;
            count++;
        }
    }
   }
    cout << "Cau 40: so cap co UCLN la so nguyen to : "<< count;
    return 0;
}