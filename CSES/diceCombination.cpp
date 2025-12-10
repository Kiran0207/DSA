#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1000100];
const int MOD=1e9+7;
int solve(int n){
	for(int i=0;i<=n;i++){
		if(i==0){
			dp[i]=1;
		}
		else{
			dp[i]=0;
			for(int j=1;j<7;j++){
				if(i>=j){
					dp[i]+=(dp[i-j])%MOD;
				}
			}
			dp[i]%=MOD;
		}
	}
	cout<< dp[n];
	return dp[n];
}

signed main(){
	int input;
	cin>>input;
	solve(input);
	return 0;
}
