#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> operation, leaves, answer, parent;
vector<set<ll>> adj;

void calc_leaves(ll node){
	if(adj[node].empty())leaves[node] = 1;
	else{
		leaves[node] = 0;
		for(auto it:adj[node]){
			calc_leaves(it);
			leaves[node] += leaves[it];
		}
	}
}

ll calc_ans(ll node){
	if(adj[node].empty()){answer[node] = 1;return answer[node];}
	if(operation[node] == 1){
		ll mnm = 1e18;
		for(auto it:adj[node]){
			mnm = min(mnm, leaves[it] - calc_ans(it));
		}
		answer[node] = leaves[node] - mnm ;

	}
	else{
		ll temp=0;
		for(auto it:adj[node]){
			temp += (calc_ans(it) - 1);
		}
		temp++;
		answer[node] = temp;
	}
	return answer[node];
}

int main(){
	ll n; cin >> n;
	operation.resize(n + 1);adj.resize(n + 1);parent.resize(n+1);leaves.resize(n+1);answer.resize(n+1);
	for(int i=1;i<=n;i++)adj[i].clear();
	for(int i=1;i<=n;i++)cin >> operation[i];
	for(int i=2;i<=n;i++){cin >> parent[i];adj[parent[i]].insert(i);}
	parent[1] = -1;
	calc_leaves(1);
	// for(int i=1;i<=n;i++)cout << leaves[i] << " ";cout << endl;
	ll ans = calc_ans(1);
	// for(int i=1;i<=n;i++)cout << answer[i] << " ";cout << endl;
	cout << ans << endl;

}