#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m; cin >> n >> m;
	vector<ll> len(m);
	ll total_len = 0;
	for(int i = 0;i < m ;i++){
		cin >> len[i];
		total_len += len[i];
	}
	ll answer = 0;
	if(total_len < n){
		answer = -1;
		cout << -1 << endl;
	} else{
		for(int i = 0;i < m ;i++){
			if(len[i] > n - (i)){
				answer = -1;
				break;
			}
		}
		if(answer != -1){
			vector<ll> posn(m), cover(m);
			posn[0] = 1;
			cover[0] = len[0];
			ll to_cover = n - m;
			for(int i = 0;i < m;i++){
				to_cover = min(to_cover, n - (i + 1 + len[i] - 1));
			}
			vector<ll> suffix_max(m);
			suffix_max[m - 1] = len[m - 1];
			for(int i = m - 2;i >= 0;i--){
				suffix_max[i] = max(suffix_max[i + 1], len[i]);
			}
			for(int i = 1;i < m;i++){
				// if covered all, start placing one by one
				if(cover[i - 1] == n || to_cover == 0){
					posn[i] = posn[i - 1] + 1;
				} else{
					// respect 1. own length, 2. to_cover dist
					posn[i] = min(n - len[i] + 1, (posn[i - 1] + 1) + to_cover);
					// respect coverage
					posn[i] = min(posn[i], cover[i - 1] + 1);
					
					cover[i] = max(cover[i - 1], posn[i] + len[i] - 1);
					to_cover = max(to_cover - (posn[i] - (posn[i - 1] + 1)), (ll)0);
				}
			}
			for(auto it: posn)cout << it << " ";cout << endl;
		} else{
			cout << -1 << endl;
		}
	}
}