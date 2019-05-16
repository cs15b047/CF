#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll> parent, sz;

void union_by_rank(ll node1, ll node2){
	if(llabs(parent[node1]) < llabs(parent[node2])){
		parent[node1] = node2;
		sz[node2] += sz[node1];
	}
	else if(llabs(parent[node2]) < llabs(parent[node1])){
		parent[node2] = node1;
		sz[node1] += sz[node2];
	}
	else{
		if(node1 < node2){			
			parent[node2]--;
			parent[node1] = node2;			
			sz[node2] += sz[node1];
		}
		else{
			parent[node1]--;
			parent[node2] = node1;
			sz[node1] += sz[node2];
		}
	}
}

ll find(ll node){
	if(parent[node] < 0)return node;
	else{
		ll tmp = find(parent[node]);
		parent[node] = tmp;
		return tmp;
	}
}

int main(){
	ll n, m; scanf("%lld%lld",&n,&m);
	// parent.resize(n + 1);sz.resize(n + 1);
	// for(int i=1;i<=n;i++)parent[i] = -1;
	// for(int i=1;i<=n;i++)sz[i] = 1;
	vector<set<ll>> adj(n + 1);
	for(int i=0;i<m;i++){
		ll k;scanf("%lld",&k);
		if(k > 0){
			// ll first;
			// for(int j = 0;j < k;j++){
			// 	ll node;scanf("%lld",&node);
			// 	if(j != 0){
			// 		ll node1 = find(first);
			// 		union_by_rank(node1, find(node));
			// 	}
			// 	else first = node;
			// }
			ll first;
			for(int j=0;j<k;j++){
				ll node;
				scanf("%lld",&node);
				if(j > 0){adj[node].insert(first);adj[first].insert(node);}
				else first = node;
			}
		}
	}
	vector<ll> vis(n + 1, 0);
	vector<set<ll>> answer;
	for(int i=1;i<=n;i++){
		if(vis[i] == 0){
			set<ll> ans;
			vis[i] = 1;
			queue<ll> q;q.push(i);
			while(!q.empty()){
				ll top = q.front();q.pop();
				ans.insert(top);
				for(auto it:adj[top]){
					if(!vis[it]){
						q.push(it);vis[it]= 1;
					}
				}
			}
			answer.push_back(ans);
		}
	}
	vector<ll> op(n + 1);
	for(auto st:answer){
		for(auto it:st){
			op[it] = st.size();
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",op[i]);printf("\n");
	
}