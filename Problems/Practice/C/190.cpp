#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<set<ll>> adj;
map<ll,ll> node_dist;
vector<ll> pth, visited;
ll n,m,k;
int flag = 0;
void dfs(ll node){
	if(flag == 1)return;
	visited[node] = 1;
	pth.push_back(node);
	node_dist[node] = pth.size();
	for(auto it:adj[node]){
		if(flag == 1)return;
		if(!visited[it]){
			dfs(it);
			if(flag == 1)return;
		}
		else if(node_dist.find(it) != node_dist.end()){
			if(node_dist[node] - node_dist[it] + 1 >= k + 1){
				flag = 1;
				ll idx_st = node_dist[it];idx_st--;
				cout << node_dist[node] - node_dist[it] + 1 << endl;
				for(ll i = idx_st;i < pth.size();i++)cout << pth[i] << " ";cout << endl;
			}
		}
	}
	node_dist.erase(node);
	pth.pop_back();
	if(flag == 1)return;
}

int main(){
	cin >> n >> m >> k ;
	adj.resize(n + 1);
	for(int i=0;i<m;i++){ll s,d;cin>>s>>d;adj[s].insert(d);adj[d].insert(s);}
	visited.resize(n + 1);
	dfs(1);
}