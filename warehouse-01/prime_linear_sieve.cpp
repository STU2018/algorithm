#include <iostream>
#include <vector>

using namespace std;

vector<int> prime_linear_sieve(int n) {
    vector<int> prime;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
    return prime;
}

int main() {
    int n;
    cin >> n;
    vector<int> prime = prime_linear_sieve(n);
    for (int i = 0; i < prime.size(); i++) {
        cout << prime[i] << " ";
    }
    return 0;
}