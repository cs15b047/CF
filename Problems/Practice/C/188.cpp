// F1. Tree Cutting (Easy Version)  CF# 540 - 3
// Root tree arbitrarily and Do DFS & answer(node -- parent(node)) = 1 if Red(ST(node)) == Blue(ST(Node)) or totRed -  Red(ST(node)) == totBlue - Blue(ST(Node))
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll> reds,blues,color,visited, parent;
vector<set<ll>>adj;

void dfs(ll node){
	visited[node] = 1;
	reds[node] = (color[node] == 1);blues[node] = (color[node] == 2);
	for(auto it:adj[node]){
		if(!visited[it]){
			parent[it] = node;
			dfs(it);
			reds[node] += reds[it];blues[node] += blues[it];
		}
	}
}


int main(){
	ll n; scanf("%lld",&n);
	color.resize(n + 1);for(int i=1;i<=n;i++)scanf("%lld",&color[i]);reds.resize(n+1);blues.resize(n+1);
	adj.resize(n+1);for(int i=1;i<=n-1;i++){ll s,d;scanf("%lld%lld",&s,&d);adj[s].insert(d);adj[d].insert(s);}
	visited.resize(n + 1);for(int i=1;i<=n;i++)visited[i] = 0;parent.resize(n + 1);

	parent[1] = -1;
	dfs(1);
	ll answer = 0;
	// for(int i=1;i<=n;i++){
	// 	cout << reds[i] << " " << blues[i] << endl;
	// }

	for(int i=2;i<=n;i++){
		if((reds[i] == reds[1] && blues[i] == 0) || (blues[i] == blues[1] && reds[i] == 0))answer++;
	}
	cout << answer << endl;

}