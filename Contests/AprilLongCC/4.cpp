#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> values,visited,A, parent, indegree;
ll n,x;
vector<set<ll>> adj;
ll dfs(ll node){
	ll part2 = -x, part1 = A[node];
	for(auto nbh:adj[node]){
		if(visited[nbh] == 0){
			visited[nbh] = 1;			
			values[nbh] = dfs(nbh);
			part1 += values[nbh];
		}
	}
	values[node] = max(part1, part2);
	return values[node];
}


int main(){
	ll t; scanf("%lld",&t);
	for(int q=0;q<t;q++){
		scanf("%lld%lld",&n,&x);
		A.clear();adj.clear();values.clear();visited.clear();parent.clear();indegree.clear();
		A.resize(n + 1);adj.resize(n + 1);values.resize(n + 1);visited.resize(n + 1);parent.resize(n + 1);indegree.resize(n + 1);
		parent[1]=-1;for(int i=1;i<=n;i++)visited[i]=0;
		for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
		for(int i=0;i<n-1;i++){
			ll u,v;scanf("%lld%lld",&u,&v);
			adj[u].insert(v);adj[v].insert(u);
		}
		visited[1] = 1;
		ll answer = dfs(1);
		cout << answer << endl;
	}
}