#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n;

ll iterate(ll i, vector<ll>& attraction){
	ll ans = -1e9;
	for(int offset = 0; offset < i; offset++){
		ll tmp = 0;
		for(int j = 0;j < n / i;j++){
			tmp += attraction[j*i + offset];
		}
		ans = max(ans, tmp);
	}
	return ans;
}

int main(){
	scanf("%lld",&n);
	vector<ll> attraction(n); for(int i = 0;i < n; i++)scanf("%lld",&attraction[i]);
	ll total_sum = 0;
	for(auto it: attraction)total_sum += it;
	ll ans = total_sum;
	for(int i = 2;i <= (ll)sqrt(n);i++){
		if(n % i == 0){
			if(n/i >= 3){
				ans = max(ans, iterate(i, attraction));
			}
			if(i >= 3){
				ans = max(ans, iterate(n/i, attraction));
			}
		}
	}
	printf("%lld\n",ans);
}