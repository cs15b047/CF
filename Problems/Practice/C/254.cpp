#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 998244353;

ll pwr(ll base, ll idx){
	if(idx == 0)return 1;
	ll tmp = pwr(base, idx >> 1);
	if(idx % 2 == 1)return ((tmp * tmp) % mod * base) % mod;
	return (tmp * tmp) % mod;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	vector<ll> answer(n + 1, 0), total(n + 1, 0), cum_sum(n + 1, 0), face_sum(n + 1, 0);
	answer[1] = 10;
	total[1] = 10;
	cum_sum[1] = 10;
	face_sum[1] = 10;
	for(int i = 2;i <= n;i++){
		total[i] = (total[i - 1] * 10 + pwr(10, i)) % mod;
		ll rest = (cum_sum[i - 1] + face_sum[i - 1]) % mod;
		answer[i] = (total[i] - rest + mod) % mod;
		face_sum[i] = (face_sum[i - 1] + answer[i]) % mod;
		cum_sum[i] = (rest + answer[i]) % mod;
	}
	for(int i = n;i >= 1;i--)cout << answer[i] << " ";cout << endl;
}