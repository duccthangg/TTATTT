//Một số gọi là siêu số nguyên tố nếu số lượng các số nguyên tố từ 1 đến X (ngoại trừ X) 
//là một số nguyên tố. 
//Hãy viết chương trình đếm số lượng các siêu số nguyên tố này trong khoảng [A,B] cho trước nhập từ bàn phím.
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
// Hàm đếm số lượng số nguyên tố từ 1 đến x-1
int count_primes_up_to(int x) {
    int count = 0;
    for (int i = 1; i < x; ++i) {
        if (isPrime(i,5)) {
            ++count;
        }
    }
    return count;
}

// Hàm kiểm tra siêu số nguyên tố
bool is_super_prime(int x) {
    int prime_count = count_primes_up_to(x);
    return isPrime(prime_count,4);
}

// Hàm đếm số lượng siêu số nguyên tố trong khoảng [A, B]
void count_super_primes_in_range(int A, int B) {
    int count = 0;
    for (int i = A; i <= B; ++i) {
        if (is_super_prime(i) && CheckPrimeFermat(i)) {
            ++count;
            cout << i << " ";
        }
    }
    cout<<" \n" << count;
}
int main(){
    int A, B;
    cin >> A >> B;
    count_super_primes_in_range(A,B);
    return 0;
}