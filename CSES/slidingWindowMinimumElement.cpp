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
	
	deque<int>de;
	int xorr=0;
	for(int i=0;i<=n-1;i++){
		if(!de.empty() && de.front()<=i-k){
			de.pop_front();
		}
		while(!de.empty() && input[de.back()]>=input[i]){
			de.pop_back();
		}
		de.push_back(i);
		if(i>=k-1) xorr^=input[de.front()];
	}
    cout << xorr;
    return 0;
}