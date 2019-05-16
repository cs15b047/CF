#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	vector<ll> letter_cost(26);for(int i=0;i<26;i++)cin >> letter_cost[i];
	string str; cin >> str;ll n = str.length();
	vector<ll> cost(n);for(int i=0;i<n;i++)cost[i] = letter_cost[str[i] - 'a'];
	vector<ll> prefix_cost(n);prefix_cost[0] = cost[0]; for(int i=1;i<n;i++)prefix_cost[i] = prefix_cost[i - 1] + cost[i];
	map<char, vector<ll>> char_pos;for(int i=0;i<n;i++)char_pos[str[i]].push_back(i);
	// for(auto it:prefix_cost)cout << it << " ";cout << endl;
	ll answer = 0;
	for(auto it: char_pos){
		vector<ll> pos = it.second;
		vector<ll> cts;cts.clear();
		ll curr = -1;
		// for(auto it2:pos)cout<< it2 << " ";cout << endl;
		map<ll,ll> val_cnt;for(int i = 1;i < pos.size(); i++)val_cnt[prefix_cost[pos[i] - 1]]++;
		for(int i = 0;i < pos.size() - 1; i++){
			if(i != 0)val_cnt[prefix_cost[pos[i] - 1]]--;
			if(val_cnt[prefix_cost[pos[i] - 1]] == 0)val_cnt.erase(prefix_cost[pos[i] - 1]);
			if(val_cnt.find(prefix_cost[pos[i]]) != val_cnt.end()){
				ll cnt = val_cnt[prefix_cost[pos[i]]];
				answer += cnt;
			}
		}
	}
	cout << answer << endl;
}