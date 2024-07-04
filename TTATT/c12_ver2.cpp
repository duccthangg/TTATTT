#include <iostream>
#include <cmath>

void sieve_of_eratosthenes(bool* is_prime, int max_n) {
    std::fill(is_prime, is_prime + max_n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= max_n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int N;
    std::cout << "Nhập N: ";
    std::cin >> N;

    if (N < 10) {  // Vì tổng 4 số nguyên tố nhỏ nhất là 2 + 3 + 5 + 7 = 17 > 10
        std::cout << "Không có bốn số nguyên tố liên tiếp nào có tổng nhỏ hơn hoặc bằng " << N << std::endl;
        return 0;
    }

    int max_n = N;
    bool* is_prime = new bool[max_n + 1];
    sieve_of_eratosthenes(is_prime, max_n);

    int primes[4] = {2, 3, 5, 7};  // Khởi tạo bốn số nguyên tố đầu tiên
    int prime_sum = 2 + 3 + 5 + 7;

    for (int i = 7; prime_sum <= N; ++i) {
        if (is_prime[i]) {
            prime_sum -= primes[0];  // Bỏ số nguyên tố cũ nhất
            // Dịch chuyển các số nguyên tố về phía trước
            primes[0] = primes[1];
            primes[1] = primes[2];
            primes[2] = primes[3];
            primes[3] = i;
            prime_sum += i;  // Thêm số nguyên tố mới nhất

            if (is_prime[prime_sum] && prime_sum <= N) {
                std::cout << "Bốn số nguyên tố liên tiếp là: ";
                for (int j = 0; j < 4; ++j) {
                    std::cout << primes[j] << " ";
                }
                std::cout << "\nTổng của chúng là: " << prime_sum << std::endl;
                delete[] is_prime;
                return 0;
            }
        }
    }

    std::cout << "Không tìm thấy bốn số nguyên tố liên tiếp nào có tổng là số nguyên tố nhỏ hơn hoặc bằng " << N << std::endl;
    delete[] is_prime;
    return 0;
}
