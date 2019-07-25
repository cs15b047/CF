#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, s; cin >> n >> s;
	vector<set<ll>> adj(n + 1);
	vector<ll> indegree(n + 1, 0);
	for(int i=0;i < n - 1;i++){
		ll s, d;cin >> s >> d;
		adj[s].insert(d);adj[d].insert(s);
		indegree[s]++;indegree[d]++;
	}
	ll num_leaves = 0;
	for(int i=1;i<=n;i++){
		num_leaves += (indegree[i] == 1);
	}
	printf("%.20f\n", (double)(2*s) / (double)num_leaves);
}