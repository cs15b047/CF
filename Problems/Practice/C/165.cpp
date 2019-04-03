#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,r1,r2;scanf("%lld%lld%lld",&n,&r1,&r2);
	vector<set<ll>> adj(n + 1);
	for(int i=1;i<=n;i++){
		if(i != r1){
			ll x;scanf("%lld",&x);
			adj[i].insert(x);
			adj[x].insert(i);
		}
	}
	vector<ll> visited(n + 1, 0),ans(n + 1, -1);
	queue<ll> q;
	q.push(r2);
	while(!q.empty()){
		ll top = q.front();q.pop();
		for(auto nbh:adj[top]){
			if(!visited[nbh]){
				visited[nbh] = 1;
				q.push(nbh);
				ans[nbh] = top;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i != r2)printf("%lld ",ans[i] );
	}
	printf("\n");
}