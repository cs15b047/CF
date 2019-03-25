#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n,m;cin>>n>>m;

	set<ll> valid_lang;
	vector<vector<ll>> lang_adj(m+1);
	ll z_count = 0 ;	
	for(int i=0;i<n;i++){
		int k;cin>>k;
		vector<ll> lang(k+1) ;
		if(k != 0){
			for(int j=0;j<k;j++){
				cin >> lang[j] ;
				valid_lang.insert(lang[j]);
			}
		}
		else z_count++;

		for(int j=0;j<k-1;j++){
			lang_adj[lang[j]].push_back(lang[j+1]) ;
			lang_adj[lang[j+1]].push_back(lang[j]) ;
		}
	}

	map<ll,int> vis ;
	queue<ll> q;
	ll ans = 0 ;
	int j = 1;
	while(j <= n){
		while(j <= n && (vis.find(j) != vis.end() || valid_lang.find(j) == valid_lang.end())){
			j++;
		}
		if(j > n)break ;
		// cout << j <<endl;
		q.push(j);vis[j] = 1;
		ans++;
		while(!q.empty()){
			ll t = q.front();q.pop();
			// cout <<t <<" " ;
			for(auto it:lang_adj[t]){
				if(vis.find(it)==vis.end()){
					vis[it] = 1;
					q.push(it);
				}
			}			
		}
	}
	if(ans > 0)ans--;	
	cout << ans + z_count  << endl ;

	return 0;
}