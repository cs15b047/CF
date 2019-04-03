#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;


int main(){
	ll n,m; scanf("%lld%lld",&n,&m);
	vector<ll> p(n + 1);for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
	vector<set<ll>> adj(n + 1);
	for(int i=0;i<m;i++){
		ll s,d;
		scanf("%lld%lld",&s,&d);
		adj[s].insert(d);adj[d].insert(s);
	}

	vector<ll> answer_vec(n + 1);

	vector<ll> visited(n + 1);
	queue<ll> q;

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			set<ll> posns,values;posns.clear();values.clear();
			q.push(i);
			visited[i] =1 ;
			posns.insert(i);
			values.insert(p[i]);
			while(!q.empty()){
				ll top = q.front();q.pop();
				for(auto it: adj[top]){
					if(!visited[it]){
						visited[it] = 1;
						q.push(it);
						posns.insert(it);
						values.insert(p[it]);
					}
				}
			}
			auto it2 = posns.begin();
			for(auto it1 = values.rbegin();it1 != values.rend() && it2 != posns.end();it1++,it2++){
				answer_vec[*it2] = *it1;
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",answer_vec[i]);
}