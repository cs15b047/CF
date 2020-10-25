#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> cvt_bag(ll sz){
	vector<ll> ans(64, 0);
	ll idx = 0;
	while(sz != 0){
		if(sz % 2 == 1){
			ans[idx] = 1;
		}
		sz = sz / 2;
		idx++;
	}
	return ans;
}

void print(vector<ll> &pwr_cnt){
	for(auto it: pwr_cnt)cout << it << " ";cout << endl;
}

void accumulate_pwrs(vector<ll> &pwr_cnt, ll pwr, ll strt){
	ll i = strt;
	ll cum_sum = 0;
	while(i < pwr){
		cum_sum += pwr_cnt[i] * (ll)pow(2, i);
		pwr_cnt[i] = 0;
		i++;
	}
	pwr_cnt[pwr] += (cum_sum / (ll)pow(2, pwr));
	// print(pwr_cnt);
}

ll get_max_pwr(vector<ll> &pwr_cnt){
	ll ans = -1;
	for(int i = 0;i < 61;i++){
		if(pwr_cnt[i] != 0)ans = i;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0; t < tests; t++){
		ll n, m; cin >> n >> m;
		vector<ll> arr(m);for(int i =0;i < m;i++)cin >> arr[i];

		vector<ll> pwr_cnt;pwr_cnt.resize(64, 0);
		vector<ll> bag_pwrs = cvt_bag(n);

		ll total = 0;

		for(int i = 0;i < m;i++){
			pwr_cnt[(ll)log2(arr[i])]++;
			total += arr[i];
		}
		ll answer = 0;
		if(total < n){
			cout << -1 << endl;
		} else{
			for(int i = 0;i < 60;){
				if(bag_pwrs[i] == 1){
					if(pwr_cnt[i] >= 1){
						pwr_cnt[i]--;
					} else{
						while(i < 60 && pwr_cnt[i] == 0){
							i++;
							answer++;
						}
						pwr_cnt[i]--;
						continue;
					}
				}
				pwr_cnt[i + 1] += pwr_cnt[i] / 2;
				i++;
			}
			cout << answer << endl;
		}
	}
}