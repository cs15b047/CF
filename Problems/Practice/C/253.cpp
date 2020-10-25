#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0;t < tests;t++){
		ll num_figs; cin >> num_figs;
		vector<ll> types(num_figs);for(int i = 0;i < num_figs;i++)cin >> types[i];

		vector<pair<ll,ll>> cnts;
		ll strt = 0, curr = 0;
		while(strt < num_figs){
			curr = strt;
			while(curr < num_figs && types[curr] == types[strt])curr++;
			cnts.push_back(make_pair(strt, curr - strt));
			strt = curr;
		}
		vector<ll> colors(num_figs, 1);
		ll num_colors = 3;
		ll sz = cnts.size();
		ll act_sz =(sz - (types[0] == types.back()));
		if(cnts.size() == 1 || (act_sz % 2 == 0) || ((act_sz % 2) == 1 && types[0] == types.back()) ){
			if(cnts.size() == 1)num_colors = 1;
			else num_colors = 2;
			for(int i = 0;i < cnts.size();i++){
				for(int j = cnts[i].first;j < cnts[i].first + cnts[i].second;j++){
					colors[j] = (i % 2) + 1;
				}
			}
		} else if(act_sz % 2 == 1){
			bool possible = false;
			ll idx = -1;
			for(int i = 0;i < cnts.size();i++){
				if(cnts[i].second > 1){
					possible = true;
					idx = i;
					break;
				}
			}
			if(!possible){
				num_colors = 3;
				colors[num_figs - 1] = 3;
				for(int i = 0;i < num_figs - 1;i++){
					colors[i] = (i) % 2 + 1;
				}
			} else{
				num_colors = 2;
				for(int i = 0;i < cnts.size();i++){
					for(int j = cnts[i].first;j < cnts[i].first + cnts[i].second;j++){
						if(i < idx){
							colors[j] = (i % 2) + 1;
						} else if(i == idx){
							if(j == cnts[i].first)colors[j] = (i % 2) + 1;
							else colors[j] = ((i + 1) % 2) + 1;
						} else{
							if(i == (ll)cnts.size() - 1 && types[0] == types.back()){
								colors[j] = 1;
							}
							colors[j] = ((i + 1) % 2) + 1;
						}
					}
				}
			}
		}
		cout << num_colors << endl;
		for(auto it: colors)cout << it << " ";cout << endl;
	}

}