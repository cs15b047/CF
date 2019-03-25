// D. Subway #95 -2
// Identify cycle and start BFS from all pts on cycle as dist = 0 and calc min dist for all other points
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> pth;
vector<bool> visited;
vector<set<ll>> adj;
map<ll,ll> cyc;
void dfs(ll curr, ll parent){
	visited[curr] = true;
	pth.push_back(curr);
	// for(auto it:pth)cout << it << " ";
	// cout << endl;
	cyc[curr]++;
	for(auto it: adj[curr]){
		if(it != parent && visited[it] == true){
			pth.push_back(it);
			cyc[it]++;
			return;
		}
		else if(it != parent && !visited[it]){
			dfs(it, curr);
			if(cyc[pth.back()] == 2 && pth.size() > 1)return;
		}
	}
	cyc.erase(pth.back());
	pth.pop_back();
}

int main(){
	ll n; cin >> n ;
	cyc.clear();
	adj.resize(n+1);

	for(int i=0; i < n; i++){
		ll src, dest; scanf("%lld%lld",&src,&dest);
		adj[src].insert(dest);adj[dest].insert(src);
	}
	visited.resize(n+1);
	dfs(1, -1);
	ll strt = pth.back();
	// for(auto it: pth)cout << it << " ";
	pth.pop_back();

	set<ll> cycle;
	vector<ll> distance(n+1);
	vector<bool> vis(n+1);
	queue<ll> q;

	int flag = 0;
	for(auto it: pth){
		if(it == strt)flag = 1;
		if(flag == 1){
			q.push(it);
			cycle.insert(it);
			distance[it] = 0;
			vis[it] = 1;			
		}
	}

	while(!q.empty()){
		ll top = q.front();q.pop();
		for(auto it: adj[top]){
			if(!vis[it]){
				q.push(it);
				distance[it] = distance[top] + 1;
				vis[it] = 1;
			}
		}
	}
	for(int i=1;i<=n;i++) cout << distance[i] << " ";
}