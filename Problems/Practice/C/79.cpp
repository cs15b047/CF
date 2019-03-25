#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> p,t;
vector<set<ll>>adj;
vector<ll>dp,h;
ll dfs(ll node){
	dp[node] = t[node] ;
	if(p[node] == 0)h[node] = 0;
	else h[node] = h[p[node]] + 1;
	for(auto ch:adj[node]){
		dp[ch] = dfs(ch);
		dp[node] += dp[ch];
	}
	return dp[node];
}

bool cmp(ll a, ll b){
	return h[a] > h[b] ;
}

set<ll> get_ancestors(ll node){
	set<ll> s;
	node = p[node];
	while(p[node] != 0){
		s.insert(node);
		node = p[node];
	}
	return s;
}

int main(){
	adj.clear();p.clear();t.clear();dp.clear();h.clear();
	ll n;scanf("%lld",&n);
	p.resize(n+1);t.resize(n+1);dp.resize(n+1);h.resize(n+1);adj.resize(n+1);
	for(int i=1;i<=n;i++)adj[i].clear();
	ll root;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&p[i],&t[i]);
		if(p[i]!=0)adj[p[i]].insert(i);
		else root = i ;
	}
	ll sum = dfs(root);
	// cout << sum << endl ;
	if(sum % 3 != 0)cout<<-1<<endl;
	else{
		vector<ll> reqd;reqd.clear();
		for(int i=1;i<=n;i++){
			if(dp[i] == sum/3)reqd.push_back(i);
		}
		if(reqd.empty())cout << -1<<endl;
		else{
			sort(reqd.begin(),reqd.end(),cmp);

			ll v1 = reqd[0];
			set<ll> s = get_ancestors(v1);
			// for(auto it: s)cout << it << " ";
			// cout << endl ;

			bool take_anc = false;
			ll v = -1 ;
			
			for(auto it: s){
				if(dp[it] == 2*(sum/3)){
					// cout << "Yo"<< endl;
					v = it ;
					take_anc = true;
					break;
				}
			}
			if(take_anc){
				cout << v1 <<" " << v << endl ;
			}
			else{
				bool done = false;
				for(int i=1;i<reqd.size();i++){
					if(s.find(reqd[i]) == s.end() && reqd[i] != root){
						cout << v1 << " "<< reqd[i]<< endl ;
						done = true ;
						break ;
					}
				}
				if(!done)cout << -1 << endl ;
			}
		}
	}
}