#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

map<pair<ll,ll>,bool> dp ;
map<ll,bool> vis ;
vector<vector<ll>>adj ;
vector<ll>c;
map<ll,set<ll>> mymap ;

bool dfs(ll x, ll y1)
{	
	vis[y1] = true;
	bool ans = true;
	for(auto it: adj[y1]){
		if(vis.find(it) == vis.end()){			
			dp[make_pair(y1,it)] = dfs(y1, it);
			ans = ans && dp[make_pair(y1,it)] ;
			ans = ans && (c[y1] == c[it]) ;
		}
	}
	dp[make_pair(x,y1)] = ans ;
	// cout << x << " " << y1 << " "<<ans <<endl ;
	return dp[make_pair(x,y1)] ;
}


void dfs2(ll x, ll y1){
	bool ans = true ;

	if((mymap[x].size() == 0) || (mymap[x].size() == 1 && mymap[x].find(y1) != mymap[x].end()) )ans = true ;
	else ans = false ;

	dp[make_pair(y1,x)] = ans ;
	if(!ans || (c[y1] != c[x])){
		mymap[y1].insert(x) ;
	}

	for(auto it: adj[y1]){
		if(it != x){
			dfs2(y1, it);
		}
	}
}

int main()
{
	int n;cin>>n ;
	adj.resize(n+1) ;
	c.resize(n+1);
	for(int i=0;i<n-1;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		adj[x].push_back(y) ;
		adj[y].push_back(x) ;
	}
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]) ;

	vis[1] = true ;
	for(auto it : adj[1]){
		dfs(1,it) ;
	}	

	for(ll i=1;i<=n;i++){
		set<ll> temp ;
		mymap[i] = temp ;
		for(auto it : adj[i]){
			if(dp.find(make_pair(i,it)) != dp.end()){
				if(!dp[make_pair(i,it)] || (c[i] != c[it])){
					mymap[i].insert(it) ;
				}
			}
		}
	}


	for(auto it : adj[1]){
		dfs2(1,it) ;
	}
	// cout << "############" <<endl;
	bool ans = true ;
	for (int i = 1; i <= n; ++i)
	{
		ans = true;
		for(auto it: adj[i]){
			// cout << i <<" " << it << " " << dp[make_pair(i,it)]<<endl ;
			ans = ans && dp[make_pair(i,it)] ;
		}
		if(ans){
			cout << "YES\n"<<i<<endl ;
			break;
		}		
	}
	if(!ans){
		cout << "NO"<<endl;
	}




	return 0;
}