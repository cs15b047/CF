#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<ll,ll>> seg;

bool cmp(ll i1, ll i2){
	return (seg[i1].first < seg[i2].first);
}
bool cmp2(ll i1, ll i2){
	return (seg[i1].second < seg[i2].second);
}

int main(){
	ll n; scanf("%lld",&n);
	seg.resize(n);
	for(int i = 0;i < n;i++){
		ll l, r;
		scanf("%lld%lld",&seg[i].first,&seg[i].second);
	}
	vector<ll> idx1(n), idx2; for(int i = 0;i < n;i++)idx1[i] = i;
	idx2 = idx1;
	sort(idx1.begin(), idx1.end(), cmp);
	vector<ll> starts(n), ends(n);
	for(int i = 0;i <n;i++){
		starts[i] = seg[idx1[i]].first;
		ends[i] = seg[idx1[i]].second;
	}
	vector<vector<ll>> adj(n);
	ll tot_edges = 0;
	bool ok = true;
	// for(auto it: starts)cout << it << " ";cout << endl;
	// for(auto it: ends)cout << it << " ";cout << endl;
	for(int i = 0; i < n; i++){
		ll fin = seg[idx2[i]].second, strt = seg[idx2[i]].first;
		// cout << strt << " " << fin << " :" << endl;
		ll ind1 = lower_bound(starts.begin(), starts.end(), strt) - starts.begin();
		ll ind2 = upper_bound(starts.begin(), starts.end(), fin) - starts.begin();
		for(int j = ind1 + 1; j < ind2;j++){
			if(ends[j] > fin){
				tot_edges++;
				adj[idx1[j]].push_back(idx2[i]);
				adj[idx2[i]].push_back(idx1[j]);
				// cout << starts[j] << " " << ends[j] << endl;
				if(tot_edges > (n - 1)){
					ok = false;
					break;
				}
			}
		}
	}
	// cout << tot_edges << endl;
	if(ok){
		queue<ll> q;vector<ll> vis(n, 0);
		q.push(0);vis[0] = 1;
		ll cnt = 0;
		while(!q.empty()){
			ll top = q.front();q.pop();
			cnt++;
			for(auto it: adj[top]){
				if(!vis[it]){
					q.push(it);
					vis[it] = 1;
				}
			}
		}
		if(cnt != n){
			ok = false;
		}
		if(ok){
			printf("YES\n");
		} else{
			printf("NO\n");
		}
	} else{
		printf("NO\n");
	}

}