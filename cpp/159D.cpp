#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;


int main() {
    string str;
    cin >> str;
    int n = str.size();
    bool is_palindrome[n + 1][n + 1];
    memset(is_palindrome, false, sizeof(is_palindrome));
    for(int i = 0; i < n; i++) is_palindrome[i][i] = true;
    for(int i = 1; i < n; i++) {
        if(str[i] == str[i - 1]) is_palindrome[i - 1][i] = true;
    }
    for(int len = 2; len < n; len++) {
        for(int i = 0; i + len < n; i++) {
            if(str[i] == str[i + len    ]) {
                is_palindrome[i][i + len] = is_palindrome[i + 1][i + len - 1];
            }
        }
    }
    long long total = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(is_palindrome[i][j]) total++;
        }
    }
    int pref;
    long long ans = 0;
    for(int i = 0; i < n - 1; i++) {
        pref = 0;
        for(int j = 0; j <= i; j++) {
            if(is_palindrome[j][i]) pref++;
        }
        for(int j = n - 1; j >= i; j--) {
            if(is_palindrome[i][j]) total--;
        }
        ans += (1LL * pref * total);
    }
    cout << ans << "\n";
}