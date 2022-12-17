#include <iostream>

using namespace std;

// 定义函数
double f(double x) {
    return x * x * x - 2 * x - 5;
}

// 三分法求解
double ternarySearch(double left, double right) {
    double mid1, mid2;
    while (right - left > 0.00001) {
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;
        if (f(mid1) > f(mid2))
            left = mid1;
        else
            right = mid2;
    }
    return (left + right) / 2;
}

int main() {
    double left = 1.0, right = 2.5;
    cout << ternarySearch(left, right) << endl;
    return 0;
}