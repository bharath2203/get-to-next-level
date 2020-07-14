#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;


int main() {
    int r, s, p;
    cin >> r >> s >> p;
    double dp[101][101][101];
    memset(dp, 0, sizeof(dp));
    dp[r][s][p] = 1;
    for(int i = r; i >= 0; i--) {
        for(int j = s; j >= 0; j--) {
            for(int k = p; k >= 0; k--) {
                if(i == 0 && j == 0) continue;
                if(i == 0 && k == 0) continue;
                if(k == 0 && j == 0) continue;
                int rs = i * j;
                int sp = j * k;
                int pr = k * i;
                int total = rs + sp + pr;
                if(total == 0) continue;
                double cur = dp[i][j][k];
                if(i != 0) dp[i - 1][j][k] += cur * ((double)pr / total);
                if(j != 0) dp[i][j - 1][k] += cur * ((double)rs / total);
                if(k != 0) dp[i][j][k - 1] += cur * ((double)pr / total); 
            }
        }
    }
    double a = 0, b = 0, c = 0;
    for(int i = 1; i < r; i++) a += dp[i][0][0];
    for(int i = 1; i < s; i++) b += dp[0][i][0];
    for(int i = 1; i < p; i++) c += dp[0][0][i];
    cout << a << " " << b << " " << c << "\n";
    return 0;
}