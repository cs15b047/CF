#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

map<string, ll> chain_len, vis;
map<string, set<string>> adj;

void dfs(string node){
	vis[node] = 1;
	if(adj.find(node) == adj.end())chain_len[node] = 1;
	for(auto it: adj[node]){
		if(!vis[it]){
			dfs(it);
			chain_len[node] = max(chain_len[node], chain_len[it] + 1);
		}
	}
}

int main(){
	ll n; cin >> n;
	for(int i=0;i<n;i++){
		string str1, s, str2; cin >> str1 >> s >> str2;
	    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

		adj[(str2)].insert(str1);
	}
	dfs("polycarp");
	cout << chain_len["polycarp"] << endl;
}