#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
map<ll,ll> dist,dp,leaves;
vector<ll> parent,cost,indegree;
vector<set<ll>> adj;
void calc_dist(ll index){
	if(dist.find(index) != dist.end())return ;
	else if(index == 1){
		dist[index] = 0;dp[index] = 0;
		return ;
	}
	else{
		calc_dist(parent[index]);
		dist[index] = dist[parent[index]] + cost[index] ;
		dp[index] = min(dp[parent[index]], dist[index]);
		return ;
	}
}

ll calc_leaves(ll root){
	if(leaves.find(root) != leaves.end())return leaves[root];
	else if(adj[root].empty()){
		leaves[root] = 1 ;
		return 1;
	}
	else{
		leaves[root] = 1;
		for(auto it: adj[root])leaves[root] += calc_leaves(it) ;
	}
	return leaves[root];
}

int main(){
	ll n;cin>>n;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	parent.resize(n+1);cost.resize(n+1);indegree.resize(n+1);
	adj.resize(n+1);
	for(int i=1;i<=n;i++)indegree[i] = 0;
	for(int i=1;i<=n-1;i++){
		ll pi,ci;scanf("%lld%lld",&pi,&ci);
		parent[i+1] = pi;
		cost[i+1] = ci ;
		indegree[pi]++;
		adj[pi].insert(i+1);
	}
	for(int i=1;i<=n;i++){
		calc_dist(i);
		// cout << i << " " << dist[i] << " " << dp[i] << endl ;
	}
	queue<ll> q;
	q.push(1);
	ll ans = 0;
	while(!q.empty()){
		ll top = q.front();q.pop();
		if(top == 1){
			for(auto it:adj[top])q.push(it);
		}
		else{
			if(dist[top] - dp[parent[top]] > a[top])ans += calc_leaves(top);
			else{
				for(auto it:adj[top])q.push(it);		
			}
		}

	}
	cout << ans << endl ;


}