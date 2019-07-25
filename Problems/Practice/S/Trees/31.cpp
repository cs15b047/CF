#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; scanf("%lld",&t);
	for(int w = 0;w < t;w++){
		ll n, m; scanf("%lld%lld",&n, &m);
		vector<set<ll>> adj(n + 1), adj2(n + 1);
		for(int i=0;i<m;i++){
			ll s,d; scanf("%lld%lld",&s,&d);
			adj[s].insert(d);adj[d].insert(s);
		}
		vector<ll> cnt(2, 0);
		vector<bool> parity(n + 1, false);
		queue<ll> q;vector<bool> vis(n + 1, false);
		q.push(1);vis[1] = true;parity[1] = false;
		while(!q.empty()){
			ll top = q.front();q.pop();
			cnt[parity[top]]++;
			for(auto it: adj[top]){
				if(!vis[it]){
					vis[it] = true;
					q.push(it);
					parity[it] = !parity[top];
				}
			}
		}
		// for(int i=1;i<=n;i++)cout << parity[i] << " " ;cout << endl;
		cout << min(cnt[0], cnt[1]) << endl;
		ll idx = 1;
		if(cnt[0] < cnt[1])idx = 0;
		for(int i=1;i<=n;i++){
			if(parity[i] == idx)cout << i << " ";
		}
		cout << endl;
	}
}