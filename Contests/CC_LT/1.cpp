#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t;cin >> t;
	for(int q =0 ;q < t; q++){
		ll n; cin >> n;
		vector<ll> num(n);for(int i=0;i<n;i++)cin >> num[i];
		vector<ll> bit_counts(33, 0);
		for(int i=0;i<n;i++){
			for(int j = 0;j<=32;j++)bit_counts[j] += (num[i] >> j) % 2;
		}
		ll X = 0;
		for(int i=0;i<=32;i++){
			if(2*bit_counts[i] > n)X += (ll)pow((ll)2,(ll)i);
		}
		ll answer = 0;
		for(int i=0;i<n;i++){
			answer += num[i] ^ X;
		}
		cout << answer << endl;
	}
}