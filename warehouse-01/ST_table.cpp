#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 100000 + 5;
int num[N];
int st[N][17];

//构建st表
void pre_deal_st(int n) {
    for (int i = 1; i <= n; ++i) {
        st[i][0] = num[i];
    }
    for (int j = 1; j <= 17; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main() {
    int n, m, l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    pre_deal_st(n);
    for (int i = 1; i <= m; ++i) {
        cin >> l >> r;
        int x = floor(log2(r - l + 1));
        int query = max(st[l][x], st[r - (1 << x) + 1][x]);
        cout << query << endl;
    }
    return 0;
}