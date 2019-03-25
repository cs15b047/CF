#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,m;cin >> n >>m ;
	vector<vector<ll>> adj(n+1);
	vector<ll> c(n+1);
	for (int i = 1; i <= n; ++i)cin >> c[i] ;
	for (int i = 1; i <= m; ++i){
		ll s,d;cin>>s>>d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}

	map<ll,int> vis ;

	queue<ll> q ;	
	int j = 1;
	ll ans = 0;
	while(j <=n)
	{
		ll curr = 1e18;		
		while(j<=n && vis.find(j)!=vis.end())j++;
		if(j > n)break;
		q.push(j);vis[j] =1 ;
		curr = min(curr, c[j]) ;
		while(!q.empty()){
			ll t = q.front();q.pop();
			curr = min(curr, c[t]) ;
			for(auto it: adj[t]){
				if(vis.find(it) == vis.end()){
					vis[it] = 1;
					q.push(it) ;
				}
			}
		}
		ans += curr ;
	}
	cout << ans <<endl ;


	return 0;
}