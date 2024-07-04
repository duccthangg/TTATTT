/*-	Tìm số nguyên tố k gần nhất với phần số của mã số sinh viên của mình (trong trường hợp khoảng cách bằng nhau thì lấy số nhỏ hơn).
-	Từ số k tìm được tính a^k mod n với a = SBD, n = 123456.
*/

#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
int MSV = 190348;
int n = 123456;
int SBD = 688;
int NearPrime(int n){
    if (n < 2) return 0;
    
    int lower = n, upper = n;

    // Tìm số nguyên tố nhỏ hơn hoặc bằng n
    while (lower > 2 && !isPrime(lower,4)) {
        --lower;
    }

    // Tìm số nguyên tố lớn hơn hoặc bằng n
    while (!isPrime(upper,4)) {
        ++upper;
    }

    // So sánh khoảng cách và trả về số nguyên tố gần nhất
    if (n - lower <= upper - n) {
        return lower;
    } else {
        return upper;
    }
}
int main(){
    int NumberPrime = NearPrime(MSV);
    cout << NumberPrime << endl;
    long long result = powIndia(SBD,NumberPrime,n);
    cout << n;
    return 0;
}
