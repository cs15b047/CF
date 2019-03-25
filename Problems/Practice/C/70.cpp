#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

vector<ll>glob,parent;
vector<set<ll>> adj;
map<pair<ll,ll>,bool> bad;
map<ll,bool> vis;

void identify_parent(ll root){
	// cout << root << endl ;
	vis[root] = 1;
	if(root == 1)parent[root] = -1;
	else{
		for(auto it:adj[root]){
			if(vis.find(it) != vis.end()){
				parent[root] = it;
				break;
			}
		}
	}
	for(auto it:adj[root]){
		if(vis.find(it) == vis.end())identify_parent(it);
	}
}

ll dfs(ll node){
	pair<ll,ll> p = make_pair(node,parent[node]);
	vis[node] = true;
	ll sum = 0;
	for(auto it:adj[node]){
		if(vis.find(it) == vis.end()){
			sum += dfs(it);
		}
	}
	if(bad.find(p)!=bad.end()){
		if(sum == 0){glob.push_back(node);return 1;}
		return sum ;
	}
	else return sum ;
}

int main(){
	ll n;cin>>n;
	vis.clear();bad.clear();adj.clear();glob.clear();parent.clear();
	adj.resize(n+1);parent.resize(n+1);
	for(int i=0;i<n-1;i++){
		ll x,y,t;
		scanf("%lld%lld%lld",&x,&y,&t);
		adj[x].insert(y);
		adj[y].insert(x);
		if(t==2){bad[make_pair(x,y)] = true;bad[make_pair(y,x)] = true;}
	}
	identify_parent(1);
	// for(auto it:parent)cout<< it << " ";
	vis.clear();
	ll ans = dfs(1);
	cout << ans <<endl ;
	for(auto it: glob)cout << it << " ";
	cout << endl;
}