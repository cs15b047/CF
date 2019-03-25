#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
vector<vector<ll>> adj;
map<ll,bool> vis;
vector<int> init,final;
vector<ll> glob_ans ;
vector<ll> get_2nd_lvl_ch(ll node)
{
	vector<ll> ans ;	
	for(auto it1:adj[node]){
		if(vis.find(it1) == vis.end()){
			vis[it1] = true;
			for(auto it2: adj[it1]){
				if(vis.find(it2) == vis.end()){
					vis[it2] = true ;
					ans.push_back(it2);
				}
			}
		}
	}
	return ans; 
}

void dfs(ll node, bool to_be_changed, bool inverted)
{
	vector<ll> son_of_son = get_2nd_lvl_ch(node);
	if (to_be_changed)
	{
		glob_ans.push_back(node);
		for(auto it: son_of_son){
			bool tbc_son = !((init[it] != final[it]) ^ (inverted)) ;
			bool inv_son = !inverted ;
			dfs(it, tbc_son, inv_son) ;
		}
	}
	else{
		for(auto it: son_of_son){
			bool inv_son = inverted ;
			bool tbc_son = (init[it] != final[it]) ^ (inverted) ;
			dfs(it, tbc_son, inv_son) ;
		}
	}
}

int main()
{
	int n; cin >>n ;
	adj.resize(n+1);
	for(int i=0;i<n-1;i++){
		ll s,d;cin >> s >> d ;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}
	init.resize(n+1);final.resize(n+1);
	for(int i=1;i<=n;i++)cin >> init[i] ;
	for(int i=1;i<=n;i++)cin >> final[i] ;

	vis[1] = true;
	dfs(1, (init[1] != final[1]) , false);
	
	vis.clear();
	vis[1] = true;
	for(auto it: adj[1]){
		vis[it]= true ;
		dfs(it, (init[it] != final[it]) , false) ;
	}
	cout << glob_ans.size() <<endl ;
	for(auto it: glob_ans){
		cout << it <<endl ;
	}

	return 0;
}