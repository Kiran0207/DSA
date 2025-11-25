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
	int totalXor=0;
	int xorr=0;
	for(int i=0;i<k;i++){
		xorr^=input[i];
	}
	totalXor=xorr;
	for(int i=1;i<n-k+1;i++){
		xorr^=input[i-1];
		xorr^=input[i+k-1];
		totalXor^=xorr;
	}
    cout << totalXor;
    return 0;
}
