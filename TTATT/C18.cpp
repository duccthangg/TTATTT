//Áp dụng thuật toán đã được học để viết chương trình tính tổng của hai số nguyên lớn,
// hiển thị dưới mạng mảng và dạng số nguyên.
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
int w = 8, t = 4;
void ArrayNumber(long long numberBig, int a[])
{
    int n = t - 1;
    while(n){
        a[n] = numberBig / (long long)pow(2,n*w);
        numberBig = numberBig %  (long long)pow(2,n*w);
        n--;
    }
    a[0] = numberBig;
}
int Epcinon(int &epa){
    return epa;
}
void SumTwoNumberBig(int A[], int B[], int C[]){
    int nho;
    int mu = pow(2,w);
    C[0] = A[0] + B[0];
    if(C[0] >= mu){
        nho = 1;
        C[0] %= mu;
    }
    else nho = 0;
    for(int i = 1; i < t; i++)
    {
        C[i] = A[i] + B[i] + nho;
        if(C[i] >= mu) {
            nho = 1;
            C[i] %= mu;
        }
        else nho = 0;
    }
   cout <<"(epci, C) = ("<<Epcinon(nho)<<",";
}
long long ConveterArray(int a[]){
    long long sumC  = 0;
    int n = t - 1;
    while (n)
    {
        sumC += a[n] * pow(2, n*w);
        n--;
    }
        sumC += a[0];
    return sumC;
}
void InputArrayNumber(int t, int a[]){
    for(int i = 0; i < t; i++){
        cin >> a[i];
    }
}
int main(){
    long long a, b;
    cin >> a >> b;
    int arr[1001], brr[1001], crr[1001];
    // InputArrayNumber(t,arr);
    // InputArrayNumber(t,brr);
    ArrayNumber(a,arr);
    ArrayNumber(b,brr);
    // ReverseArray(t,arr);
    // ReverseArray(t,brr);
    SumTwoNumberBig(arr,brr,crr);
    ReverseArray(t,crr);
    cout <<"(";
    for(int i = 0; i <= 2; i++){
        cout << crr[i] << ",";
    }
    cout<< crr[3] <<"))" << "\n";
    ReverseArray(t,crr);
    cout << ConveterArray(crr);
    return 0;
}