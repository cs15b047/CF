#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m; cin >> n >> m;
	vector<set<ll>> adj(n + 1);
	vector<pair<ll,ll>> edges;
	for(int i=0;i<m;i++){
		ll s,d; cin >> s >> d;
		adj[s].insert(d);adj[d].insert(s);
		edges.push_back(make_pair(s,d));
	}
	vector<ll> visited(n + 1), color(n + 1);
	queue<ll> q;
	visited[1] = 1 ;
	q.push(1);
	color[1] = 0;

	int flag = 0;

	while(!q.empty()){
		ll top = q.front();q.pop();
		for(auto nbh:adj[top]){
			if(!visited[nbh]){
				q.push(nbh);visited[nbh] = 1;color[nbh] = 1 - color[top];
			}
			else{
				if(color[nbh] != 1 - color[top]){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1)break;
	}
	if(flag == 1)cout << "NO" << endl;
	else{
		cout << "YES"<<endl;
		for(int i=0;i<m;i++){
			cout << color[edges[i].first];
		}
	}
}