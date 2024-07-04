//Cho 2 số M và N thoả mãn điều kiện: 1<=N<=10000; 2<M<=100; 
//Hãy viết chương trình xác định xem số N có thể được phân tích thành tổng của M số nguyên tố hay không?
//Nếu có thì in ra các số đó. 
//Ví dụ: N=10 và M=3, thì 10=2+3+5 do đó kết quả trả về là thoả mãn và in ra 3 số 2,3,5
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

const int MAX_N = 10000;
const int MAX_M = 100;

// Hàm tìm các số nguyên tố nhỏ hơn MAX_N
void sieve(int *primes, int &count) {
    Eratosthenes_Prime();
    count = 0;
    for (int p = 2; p <= MAX_N; ++p) {
        if (prime[p]) {
            primes[count++] = p;
        }
    }
}

// Hàm kiểm tra xem N có thể phân tích thành tổng của M số nguyên tố hay không
bool findSumOfPrimes(int N, int M, int *result) {
    int primes[MAX_N];
    int prime_count;
    sieve(primes, prime_count);

    int sum = 0;
    for (int i = 0; i < M; ++i) {
        result[i] = primes[i];
        sum += primes[i];
    }

    if (sum > N) return false;

    int i = M - 1;
    while (sum < N && i >= 0) {
        while (sum + primes[i + 1] - result[i] <= N && i < prime_count - 1) {
            sum += primes[i + 1] - result[i];
            result[i] = primes[i + 1];
            i++;
        }
        if (sum == N) return true;
        i--;
    }

    return (sum == N);
}

int main() {
    int N, M;
    cout << "Nhập N: ";
    cin >> N;
    cout << "Nhập M: ";
    cin >> M;

    if (N < 1 || N > 10000 || M < 2 || M > 100) {
        cout << "Giá trị của N hoặc M không hợp lệ." << endl;
        return 1;
    }

    int result[MAX_M];
    if (findSumOfPrimes(N, M, result)) {
        cout << N << " = ";
        for (int i = 0; i < M - 1; ++i) {
            cout << result[i] << " + ";
        }
        cout <<result[M-1];
        cout << endl;
    } else {
        cout << "Không thể phân tích " << N << " thành tổng của " << M << " số nguyên tố." << endl;
    }

    return 0;
}
