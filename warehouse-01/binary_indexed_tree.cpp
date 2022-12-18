#include <iostream>
#define MAX_SIZE 100

using namespace std;

//树状数组
int c[MAX_SIZE];

//求lowbit
int lowbit(int x) {
    return x & (-x);
}

//更新
void update(int x, int v) {
    while (x < MAX_SIZE) {
        c[x] += v;
        x += lowbit(x);
    }
}

//查询
int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    int a[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 1; i <= 10; i++) {
        update(i, a[i]);
    }
    cout << query(10) << endl;
    return 0;
}