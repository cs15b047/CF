#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<set<ll>> adj;
vector<set<ll>> pts, wts;
vector<ll> visited,wts;

void dfs(ll node){
	visited[node] = 1;
	pts[node].insert(node);wts[node].insert(wts[node]);
	for(auto it:adj[node]){
		if(!visited[node]){
			dfs(it);
			for(auto it2:pts[it]){
				pts[node].insert(it2);wts[node].insert(wts[it2]);
			}
		}
	}
}

int main(){
	ll t; scanf("%lld",&t);
	for(int w = 0;w < t; w++){
		ll n,q; scanf("%lld%lld",&n,&q);
		wts.resize(n + 1);for(int i=1;i<=n;i++)scanf("%lld",&wts[i]);
		visited.resize(n + 1);adj.resize(n + 1);for(int i=1;i<=n-1;i++){ll s,d;scanf("%lld%lld",&s,&d);adj[s].insert(d);adj[d].insert(s);}
		pts.resize(n + 1);visited.resize(n + 1);wts.resize(n + 1);
	}
	ll v=0,k=0;
	for(int x = 0;x < q; x++){
		scanf("%lld%lld",&a,&b);
		v = v ^ a;k = k ^ b;
		ll tmp = k;
		auto it1 = wts[v].begin(), it2 = wts[v].rbegin();
		ll pwr = 20;
		while(*it1 != *it2){
			ll pos = ((tmp >> pwr) << pwr);
		}
	}
}