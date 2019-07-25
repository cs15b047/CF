#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, m, k; cin >> n >> m >> k;
	vector<ll>a(n);for(int i=0;i<n;i++)	cin >> a[i];
	vector<ll> len(n), dp(n, 0); 
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(i == 0){
			dp[i] = a[i];
			len[i] = 1 ;
		} else {
			if(len[i - 1] % m == 0){
				if(a[i] < dp[i - 1] + a[i] - k){
					dp[i] = dp[i - 1] + a[i] - k;
					len[i] = len[i - 1] + 1;
				} else{
					dp[i] = a[i];
					len[i] = 1;
				}
			} else {
				if(a[i] < dp[i - 1] + a[i]){
					dp[i] = dp[i - 1] + a[i];
					len[i] = len[i - 1] + 1;
				} else{
					dp[i] = a[i];
					len[i] = 1;	
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		ans = max(ans, dp[i] - k);
	}
	cout << ans << endl;
}