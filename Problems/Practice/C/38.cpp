#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n;cin>>n;
	vector<vector<ll>> adj(n+1);
	for(int i=0;i<n-1;i++){
		ll s,d;cin>>s>>d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans, (ll)adj[i].size());
	}
	ans++;
	map<ll,ll> color;

	map<ll,pair<ll,set<ll>>> alloc ;

	queue<ll>q;
	q.push(1);color[1] = 1;
	set<ll> temp ;temp.insert(1);
	alloc[1] = make_pair(2, temp);

	while(!q.empty()){
		ll t = q.front();q.pop();
		for(auto it: adj[t]){
			if(alloc.find(it) == alloc.end()){
				color[it] = alloc[t].first; alloc[t].second.insert(alloc[t].first);
				while(alloc[t].second.find(alloc[t].first) != alloc[t].second.end())alloc[t].first++;

				ll h=1;set<ll>s;
				s.insert(color[t]);s.insert(color[it]);
				while(s.find(h) !=s.end())h++;
				alloc[it] = make_pair(h, s);
				q.push(it);
			}
		}
	}

	cout << ans << endl ;
	for(auto it:color){
		cout << it.second << " ";
	}


}