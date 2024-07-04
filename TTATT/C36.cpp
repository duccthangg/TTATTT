/*Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Boyer-Moore, in giá trị của bảng. 
Trong trường hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm vét cạn.*/
#include <bits/stdc++.h>
#include <string>
#include "funsion_math.h"
using namespace std;
//getline(cin,a) nhap co dau cach
// cin >> a nhap khong co dau cach
//cin.ignore(n); xoa dau enter, voi n la so ky tu can xoa
//<string>.length() || <string>.size() tra ve so ky tu trong sau
int lastArray[256];
void handlePattern(string pattern){
    memset(lastArray,-1,sizeof(lastArray));
    int m = pattern.length();
    for(int i = 0; i < m; i++){
        lastArray[(int)pattern[i]] = i;
    }
}
void BM_Algorithm(string  text, string pattern){
    handlePattern(pattern);
   int m =pattern.size();
   int n =text.size();
    int s = 0; // s là chỉ số dịch chuyển của pattern với text

    while (s <= (n - m)) {
        int j = m - 1;

        // Giảm dần j khi ký tự tại vị trí j trong pattern khớp với ký tự tại vị trí tương ứng trong text
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        // Nếu pattern khớp hoàn toàn với text
        if (j < 0) {
            cout << "mau duoc tim thay tai: " << s << endl;

            // Dịch chuyển pattern sao cho ký tự tiếp theo trong text sánh với vị trí xuất hiện cuối cùng của ký tự không khớp trong pattern
            s += (s + m < n) ? m - lastArray[text[s + m]] : 1;
        } else {
            // Dịch chuyển pattern sao cho ký tự không khớp trong text khớp với vị trí xuất hiện cuối cùng của ký tự đó trong pattern
            s += max(1, j - lastArray[text[s + j]]);
        }
    }
}

int main(){
    string S1, S2;
    cout <<"Nhap noi dung: ";
    getline(cin,S2);
    cout <<"Nhap mau can kiem tra trong noi dung: ";
    getline(cin,S1);
    BM_Algorithm(S2,S1);
    return 0;
}