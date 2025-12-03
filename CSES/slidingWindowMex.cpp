#include<bits/stdc++.h>
using namespace std;
int main(){

	int n,k;
	cin>>n>>k;
	vector<int>input(n);
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	vector<int>freq(n+1,0);
	set<int>missing;
	for(int i=0;i<=n;i++){
		missing.insert(i);
	}
	for(int i=0;i<k;i++){
		if(input[i]<=n){
			if(freq[input[i]]==0) missing.erase(input[i]);
			freq[input[i]]++;
		}
	}
	cout<< *missing.begin();
	for(int i=k;i<n;i++){
		if(input[i-k]<=n){
			freq[input[i-k]]--;
			if(freq[input[i-k]]==0) missing.insert(input[i-k]);
		}
		if(input[i]<=n){
			if(freq[input[i]]==0) missing.erase(input[i]);
			freq[input[i]]++;
		}
		cout<< " "<< *missing.begin();
	}
	return 0;
}
