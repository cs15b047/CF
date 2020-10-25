#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
	map<ll,ll> cnt_probs;
	ll prob;
	for(int i = 0;i < n;i++){
		cin >> prob;
		cnt_probs[prob]++;
	}
	vector<ll> cnts;
	for(auto it: cnt_probs)cnts.push_back(it.second);
	sort(cnts.begin(), cnts.end());
	ll curr = cnts.back(), len = 1, idx = (ll)(cnts.size()) - 1, strt = curr;
	ll answer = curr;

	for(int i = idx - 1;i >= 0;i--){
		if(curr == 1)break;
		strt = min(curr/2, cnts[i]);
		len++;
		ll tmp_ans = strt * ((ll)pow(2, len) - 1);
		// cout << strt << " " << len << endl;
		answer = max(answer, tmp_ans);
		curr = strt;
	}
	cout << answer << endl;
}