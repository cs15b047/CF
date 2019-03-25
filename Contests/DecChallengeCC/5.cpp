#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t ;
	for(int q = 0;q<t;q++){
		ll n,m; cin >> n >> m;
		vector<set<ll>> adj;adj.clear();adj.resize(n+1);
		vector<ll>indegree(n+1);
		map<pair<ll,ll>,ll> edge_index;
		map<ll,pair<ll,ll>> index_edge;
		for(int i=0;i<m;i++){
			ll s,d;scanf("%lld%lld",&s,&d);
			adj[s].insert(d);adj[d].insert(s);
			indegree[s]++;indegree[d]++;
			edge_index[make_pair(s,d)] = i;
			index_edge[i] = make_pair(s,d);
		}
		if(m % 2 != 0)printf("-1\n");
		else{
			
		}
	}
}