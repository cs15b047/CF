#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;


int main(){
	ll n,m; cin >> n >> m;
	vector<set<ll>>adj(n + 1);
	vector<ll> degree(n + 1), visited(n + 1, 0);
	for(int i=0;i<m;i++){
		ll s,d;cin>>s>>d;
		adj[s].insert(d);adj[d].insert(s);
		degree[s]++;degree[d]++;
	}
	set<ll> deg_1,deg_0,deg_2;
	for(int i=1;i<=n;i++){
		if(degree[i] == 1)deg_1.insert(i);
		else if(degree[i] == 0)deg_0.insert(i);
		else deg_2.insert(i);
	}
	ll odd = 0;
	if(deg_0.size() % 2 == 1)odd++;
	for(auto it:deg_1){
		if(!visited[it]){
			ll len=1;
			visited[it] = 1;
			ll curr = it;
			// cout << curr << endl;
			while(!adj[curr].empty()){
				ll nxt = *adj[curr].begin();
				adj[curr].erase(nxt);
				adj[nxt].erase(curr);
				curr = nxt;
				visited[nxt] = 1;
				len++;
				// cout << curr << endl;
			}
			// cout << len << endl;
			if(len % 2 == 1)odd = (odd + 1) % 2;
		}
	}
	// cout << "Cycle" << endl;
	ll answer = odd;
	for(auto it: deg_2){
		
		if(!visited[it]){
			ll nbh = *adj[it].begin();
			adj[it].erase(nbh);adj[nbh].erase(it);
			ll len=1;
			visited[it] = 1;
			ll curr = it;
			// cout << it << " ";
			while(!adj[curr].empty()){
				ll nxt = *adj[curr].begin();
				adj[curr].erase(nxt);
				adj[nxt].erase(curr);
				curr = nxt;
				visited[nxt] = 1;
				len++;
				// cout << curr << " ";
			}
			// cout << endl;
			// cout << len << endl;
			if(len % 2 == 1)answer++;
		}
	}
	cout << answer << endl;
}