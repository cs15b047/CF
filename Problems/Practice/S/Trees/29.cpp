#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<set<ll>> adj(n + 1);
	for(int i=0;i< n - 1;i++){
		ll s,d; cin >> s >> d; adj[s].insert(d);adj[d].insert(s);
	}
	vector<ll> seq(n);for(int i=0;i<n;i++)cin >> seq[i];

	queue<ll> q;vector<bool> vis(n + 1, false);
	q.push(1);vis[1] = true;
	bool match = true;
	ll ptr = 0;
	if(seq[0] != 1){
		match = false;
	}
	else{
		ptr = 1;
		while(!q.empty()){
			ll top = q.front(); q.pop();
			vector<ll> children;children.clear();
			for(auto it:adj[top]){
				if(!vis[it]){
					vis[it] = true;
					children.push_back(it);
				}
			}
			// for(auto it: children){cout << it << " ";}cout << endl;
			// for(int i = ptr;i < ptr + children.size();i++){cout << seq[i] << " ";}cout << endl;
			vector<ll> cop(children.size()), cop2;
			copy(seq.begin() + ptr, seq.begin() + (ptr + children.size()), cop.begin());
			cop2 = cop;
			sort(cop.begin(), cop.end());
			sort(children.begin(), children.end());
			if(children.size() != cop.size()){
				match = false;
				break;
			}
			for(int i = 0;i < cop.size();i++){
				if(cop[i] != children[i]){
					match = false;
					break;
				}
			}
			ptr += children.size();
			for(auto it: cop2)q.push(it);
		}
	}
	if(match)cout << "Yes" << endl;
	else cout << "No" << endl;
}