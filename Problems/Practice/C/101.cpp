// E. New Reform #346 - 2
// For tree --> 1 node must have indegree = 0 --> root
// for component having cycle --> every node can have 1 indegree
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,m; cin >> n >> m;
	vector<set<ll>> adj(n+1);
	for(int i=0;i<m;i++){
		ll s,d;scanf("%lld%lld",&s,&d);
		adj[s].insert(d);adj[d].insert(s);
	}

	vector<bool> vis(n+1);
	queue<ll> q;
	ll answer = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ll V=0,E=0;
			q.push(i);
			vis[i] = 1;
			while(!q.empty()){
				ll top = q.front();q.pop();V++;E+=adj[top].size();
				for(auto it: adj[top]){
					if(!vis[it]){
						q.push(it);vis[it] = 1;
					}
				}
			}
			E = E/2;
			if(E >= V){}
			else if(E == V - 1){answer++;}
			else {printf("shit\n");}
		}
	}
	cout << answer << endl;
}