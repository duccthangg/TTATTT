/*Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Knutt-Morris-Patt. 
Trong trường hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm vét cạn?*/
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
// Hàm tạo mảng lps[] để lưu độ dài của tiền tố dài nhất cũng là hậu tố
void computeLPSArray(string pat, int M, int *lps) {
    int len = 0;  // Độ dài của tiền tố dài nhất cũng là hậu tố trước đó
    lps[0] = 0;  // lps[0] luôn bằng 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {  // (pat[i] != pat[len])
            if (len != 0) {
                len = lps[len - 1];  // Không tăng i
            } else {  // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Hàm tìm kiếm chuỗi con bằng thuật toán KMP
void KMPSearch(string pat, string txt) {
    int M = pat.size();
    int N = txt.size();

    int lps[M];  // Mảng lps

    // Tạo mảng lps
    computeLPSArray(pat, M, lps);

    int i = 0;  // Chỉ số cho txt[]
    int j = 0;  // Chỉ số cho pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            cout << "mau duoc tim thay tai " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            // Không khớp ký tự sau khi đã khớp j ký tự
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}
int main(){
    string S1, S2;
    cout <<"Nhap noi dung: ";
    getline(cin,S2);
    cout <<"Nhap mau can kiem tra trong noi dung: ";
    getline(cin,S1);
    KMPSearch(S1,S2);
    return 0;
}