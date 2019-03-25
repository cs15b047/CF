#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> w;
vector<set<pair<ll,ll>>> adj;
vector<ll> starts, through, answer, visited,parent;
void dfs(ll root){
	visited[root] = 1;

	int flag = 0;
	for(auto nbh:adj[root]){
		if(!visited[nbh.first]){
			parent[nbh.first] = root ;
			adj[nbh.first].erase(make_pair(root, nbh.second));
			dfs(nbh.first);
			flag = 1;
		}
	}
	if(flag == 0){
		starts[root] = w[root] ;through[root] = w[root];answer[root] = w[root];
	}
	else{
		if(adj[root].size() == 1){
			auto it = adj[root].begin() ;
			pair<ll,ll> nbh = *it;
			starts[root] = max(w[root], w[root] - nbh.second + starts[nbh.first]) ;
			through[root] = starts[root];
		}
		else {
			vector<ll> nbh_sts;
			for(auto nbh:adj[root]){
				if(nbh.first != parent[root])
					nbh_sts.push_back(- nbh.second + starts[nbh.first]);
			}
			sort(nbh_sts.begin(),nbh_sts.end(),greater<ll>());

			starts[root] = max(w[root], w[root] + nbh_sts[0]);
			through[root] = max(starts[root], w[root] + nbh_sts[0] + nbh_sts[1]) ; // 2nd term -ve ans can come
		}
		answer[root] = w[root];
		for(auto nbh:adj[root]){
			if(nbh.first != parent[root])answer[root] = max(answer[root], answer[nbh.first]);
		}
		answer[root] = max(answer[root], through[root]) ;
	}
}

int main(){
	ll n ;cin >> n ;
	w.resize(n+1);
	adj.resize(n+1);starts.resize(n+1);through.resize(n+1);answer.resize(n+1);visited.resize(n+1);parent.resize(n+1);
	for(ll i=1;i<=n;i++)scanf("%lld",&w[i]);
	for(ll i=1;i<n;i++){
		ll s,d,c;scanf("%lld%lld%lld",&s,&d,&c);
		adj[s].insert(make_pair(d,c));
		adj[d].insert(make_pair(s,c));
	}
	parent[1] = -1;
	dfs(1);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans, answer[i]);
	}
	cout << ans << endl;

}