#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, k;
    cin >> n >> k;
 
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
 
    vector<long long> input(n);
    input[0] = x;
 
    for (long long i = 1; i < n; i++) {
        input[i] = (input[i - 1] * a + b) % c;
    }
 
    long long sum = 0;
    for (long long i = 0; i < k; i++) {
        sum += input[i];
    }
 
    long long xorSum = sum;
 
    for (long long i = 1; i < n - k + 1; i++) {  // FIXED
        sum = sum - input[i - 1] + input[i + k - 1];
        xorSum ^= sum;
    }
 
    cout << xorSum;
    return 0;
}