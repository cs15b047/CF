#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,m;cin >> n >> m;
	vector<set<ll>> adj(n+1);vector<ll>indegree(n+1);
	for(int i=0;i<m;i++){
		ll s,d;scanf("%lld%lld",&s,&d);
		adj[d].insert(s);
		indegree[s]++;
	}
	queue<ll> q;
	for(int i=1;i<=n;i++){
		if(indegree[i] == 0)q.push(i);
	}
	vector<pair<ll,ll>> answer;
	while(!q.empty()){
		if(q.size() >= 2){
			ll t1,t2;t1 = q.front();q.pop();t2 = q.front();q.pop();
			pair<ll,ll> step = make_pair(t1,t2);
			answer.push_back(step);
			for(auto it:adj[t1]){
				indegree[it]--;
				if(indegree[it] == 0){
					q.push(it);
				}
			}
			adj[t1].clear();
			for(auto it:adj[t2]){
				indegree[it]--;
				if(indegree[it] == 0){
					q.push(it);
				}
			}
			adj[t2].clear();
		}
		else if(q.size() == 1){
			ll t1 = q.front();q.pop();
			pair<ll,ll> step = make_pair(t1,-1);
			answer.push_back(step);
			for(auto it:adj[t1]){
				indegree[it]--;
				if(indegree[it] == 0){
					q.push(it);
				}
			}
			adj[t1].clear();
		}
	}
	printf("%lld\n",(ll)answer.size() );
	for(auto pair:answer){
		if(pair.second == -1)printf("1 %lld\n",pair.first );
		else printf("2 %lld %lld\n",pair.first, pair.second );
	}
}