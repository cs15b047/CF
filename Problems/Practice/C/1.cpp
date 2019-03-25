#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
map<ll,ll> cost ;
vector<ll> v,ind;
vector<set<ll>> adj ;
class comp{
public:
	bool operator()(ll a,  ll b){
		return v[a] > v[b] ;
	}
};


int main(int argc, char const *argv[])
{
	cost.clear();v.clear();adj.clear();
	int n,m ;cin>>n>>m ;
	v.resize(n+1) ; ind.resize(n+1) ;
	for(int i=1;i<=n;i++)cin>>v[i] ;
	for(int i=1;i<=n;i++)ind[i] = i ;

	sort(ind.begin()+1,ind.end(),comp()) ;
	adj.resize(n+1) ;
	ll ans =0 ;
	for (int i = 0; i < m; ++i)
	{
		ll x,y ;cin>>x>>y;
		adj[x].insert(y) ;
		adj[y].insert(x) ;
		ans += min(v[x],v[y]) ;
	}
	cout << ans <<endl ;
	
	// for(int i=1;i<=n;i++){
	// 	cost[i] = 0 ;
	// 	for(auto it:adj[i]){
	// 		cost[i] += v[it] ;
	// 	}
	// }
	// map<ll,int> vis ;
	
	// for(int i=1;i<=n;i++)
	// {
	// 	vis[ind[i]] = 1 ;
	// 	ans += cost[ind[i]] ;
	// 	for(auto it: adj[ind[i]]){
	// 		if (vis.find(it) == vis.end())
	// 		{
	// 			cost[it] -= v[ind[i]] ;
	// 		}
	// 	}
	// }
	// cout << ans <<endl ;

	return 0;
}