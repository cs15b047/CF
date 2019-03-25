// A. Fair #485 - 1
//For every goods, start bfs from all pts selling that goods --> K BFS --> (N+M)K time 
// calculate distance of node from goods, not of each good from each node
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,m,k,s;cin >> n >> m >> k >> s ;
	vector<ll> goods(n+1);for(int i=1;i<=n;i++)scanf("%lld",&goods[i]);
	vector<set<ll>> goods_pts(k+1);for(int i=1;i<=n;i++)goods_pts[goods[i]].insert(i);
	vector<set<ll>> adj(n+1);
	for(int i=1;i<=m;i++){
		ll src,dest;
		scanf("%lld%lld",&src,&dest);
		adj[src].insert(dest);
		adj[dest].insert(src);
	}

	vector<vector<ll>> distance(n+1);
	for(int i=1;i<=n;i++)
		distance[i].resize(k+1);
	for(int i=1;i<=k;i++){
		bool visited[n+1] = {};
		queue<ll> q;
		for(auto it:goods_pts[i]){
			distance[it][i] = 0;
			visited[it] = 1;
			q.push(it);
		}
		while(!q.empty()){
			ll top = q.front();q.pop();
			for(auto nbh: adj[top]){
				if(!visited[nbh]){
					visited[nbh] = 1; q.push(nbh);
					distance[nbh][i] = distance[top][i] + 1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		sort(distance[i].begin(),distance[i].end());
		ll ans = 0;
		for(int j=1;j<=s;j++)ans += distance[i][j];
		cout << ans << " ";
	}
}