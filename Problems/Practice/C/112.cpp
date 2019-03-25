//C. Socks - #376 - 2
// Make disjoint sets of connected nodes(socks) and take majority color among each set
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,m,k; cin >> n >> m >> k ;
	vector<ll> colors(n+1);for(ll i=1;i<=n;i++)cin >> colors[i] ;
	vector<set<ll>> adj(n+1);
	for(ll i=0;i<m;i++){
		ll src,dest; cin >> src >> dest ;
		adj[src].insert(dest);adj[dest].insert(src);
	}

	vector<bool> visited(n+1);

	queue<ll> q;
	ll answer = 0;
	for(ll i=1;i<=n;i++){
		if(!visited[i]){
			set<ll> component;
			q.push(i);visited[i] = 1;
			component.insert(i);
			while(!q.empty()){
				ll top = q.front();q.pop();
				for(auto nbh:adj[top]){
					if(!visited[nbh]){
						visited[nbh] = 1;
						q.push(nbh);
						component.insert(nbh);
					}
				}
			}
			map<ll,ll>color_count;
			for(auto point:component){
				color_count[colors[point]]++;
			}
			ll mx_color = -1,mx_count=-1;
			for(auto color:color_count){
				if(color.second > mx_count){
					mx_color = color.first;
					mx_count = color.second;
				}
			}
			answer += (component.size() - mx_count);
		}
	}
	cout << answer << endl ;
}