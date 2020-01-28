#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void printvec(vector<ll> vec){
	for(auto it:vec)cout << it << " ";
	cout<< endl;
}

int main(){
	ll t; cin >> t;
	for(int q = 0;q < t; q++){
		ll n, g, m; cin >> n >> g >> m;
		vector<pair<ll,ll>> positions_clock, positions_anti;
		for(int i = 0;i < g; i++){
			ll idx; string dir;
			cin >> idx >> dir;
			if(dir == "C")positions_clock.push_back(make_pair(i, idx - 1));
			if(dir == "A")positions_anti.push_back(make_pair(i, idx - 1));
		}
		
		// for(auto it:positions_clock)cout << it.first << " " << it.second << endl;

		map<ll, vector<ll>> groups_c, groups_a;
		for(auto it: positions_clock)groups_c[(it.second + m) % n].push_back(it.first);
		for(auto it: positions_anti)groups_a[(it.second - m + (ll)1e9*n) % n].push_back(it.first);

		// cout << "Cis:";
		// for(auto it: groups_c){
		// 	cout << it.first << ": " ;
		// 	printvec(it.second);
		// }
		// cout << "Anti:";
		// for(auto it: groups_a){
		// 	cout << it.first << ": " ;
		// 	printvec(it.second);
		// }

		vector<ll>group_c_pos;for(auto it:groups_c)group_c_pos.push_back(it.first);
		vector<ll>group_a_pos;for(auto it:groups_a)group_a_pos.push_back(it.first);

		// cout << "Grp pos" << endl;
		// printvec(group_a_pos);printvec(group_c_pos);

		vector<pair<ll,ll>> consulates_visit_c(n, make_pair(-1, -1)), consulates_visit_a(n, make_pair(-1, -1));

		ll sz_c = group_c_pos.size(), sz_a = group_a_pos.size();
		for(int i = 0;i < sz_c ;i++){

			ll j = 0;
			ll pos = group_c_pos[i];

			// steps are enough and not collide with previous one in chain
			ll shifted_pos = (pos - j + (ll)1e9*n) % n;
			ll rot_prev_idx = (i - 1 + sz_c) % sz_c;

			while(j <= m && (sz_c == 1 || shifted_pos != group_c_pos[rot_prev_idx])){
				consulates_visit_c[shifted_pos] = make_pair(m - j, i);
				j++;
				shifted_pos = (shifted_pos - 1 + n) % n;
			}
		}

		for(int i = 0;i < sz_a ;i++){
			ll j = 0;
			ll pos = group_a_pos[i];

			// steps are enough and not collide with previous one in chain
			ll shifted_pos = (pos + j) % n;
			ll rot_prev_idx = (i + 1) % sz_a;
			while(j <= m && (sz_a == 1 || shifted_pos != group_a_pos[rot_prev_idx])){
				consulates_visit_a[shifted_pos] = make_pair(m - j, i);
				j++;
				shifted_pos = (shifted_pos + 1) % n;
			}
		}

		// for(auto it: consulates_visit_c)cout << it.first << " " << it.second << endl;
		// for(auto it: consulates_visit_a)cout << it.first << " " << it.second << endl;

		vector<ll> consulates_c(n, -1), consulates_a(n, -1);
		// iterate through consulates and assign 1 or 2 grps for 1 consulate depending on time
		for(int i = 0;i < n;i++){
			pair<ll,ll> not_vis = make_pair((ll)-1, (ll)-1);
			if(consulates_visit_c[i] == not_vis && consulates_visit_a[i] != not_vis){
				consulates_a[i] = consulates_visit_a[i].second;
			} else if(consulates_visit_c[i] != not_vis && consulates_visit_a[i] == not_vis){
				consulates_c[i] = consulates_visit_c[i].second;
			} else if(consulates_visit_c[i] != not_vis && consulates_visit_a[i] != not_vis){
				if(consulates_visit_c[i].first > consulates_visit_a[i].first){
					consulates_c[i] = consulates_visit_c[i].second;
				}
				else if(consulates_visit_c[i].first < consulates_visit_a[i].first){
					consulates_a[i] = consulates_visit_a[i].second;
				}else{
					consulates_c[i] = consulates_visit_c[i].second;
					consulates_a[i] = consulates_visit_a[i].second;
				}
			}
		}
		// printvec(consulates_c);printvec(consulates_a);
		map<ll, vector<ll>> c_grp_to_consulates, a_grp_to_consulates;
		for(int i = 0;i < n;i++){
			if(consulates_c[i] != -1){
				c_grp_to_consulates[consulates_c[i]].push_back(i);
			}
			if(consulates_a[i] != -1){
				a_grp_to_consulates[consulates_a[i]].push_back(i);
			}
		}
		vector<ll> cnts(g, 0);
		for(auto it: a_grp_to_consulates){
			vector<ll> idxs = groups_a[group_a_pos[it.first]];
			for(auto id: idxs)cnts[id] = it.second.size();
		}
		for(auto it: c_grp_to_consulates){
			vector<ll> idxs = groups_c[group_c_pos[it.first]];
			for(auto id: idxs)cnts[id] = it.second.size();
		}
		cout << "Case #" << q + 1 << ": " ;
		for(auto it:cnts)cout << it << " ";
		cout << endl;
	}
}
