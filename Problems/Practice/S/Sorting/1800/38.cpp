#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

map<char, set<char>> adj_list;
map<char, ll> cnts;
map<char, bool> vis;

vector<char> dfs(char curr){
	vis[curr] = true;
	for(auto it: adj_list[curr]){
		if(!vis[it]){
			vector<char> ret = dfs(it);
			reverse(ret.begin(), ret.end());
			for(int i = 0;i < cnts[curr];i++)ret.push_back(curr);
			reverse(ret.begin(), ret.end());
			return ret;
		}
	}
	vector<char> ret;for(int i = 0;i < cnts[curr];i++)ret.push_back(curr);
	return ret;
}

int main(){
	ll t; cin >> t;
	for(int q =0;q < t;q++){
		string str; cin >> str; ll l = str.length();
		cnts.clear();for(int i = 0;i < l;i++)cnts[str[i]]++;
		// for(auto it:cnts)cout << it.first << " " << it.second << endl;
		// graph
		adj_list.clear();ll n = cnts.size();
		set<char> complete;for(auto it: cnts)complete.insert(it.first);
		for(auto it: cnts){
			char letter = it.first;
			set<char> cpy = complete;
			cpy.erase(letter - 1);cpy.erase(letter + 1);cpy.erase(letter);
			adj_list[letter] = cpy;
		}
		// for(auto it:adj_list){
		// 	cout << it.first << " : " ;
		// 	for(auto it2: it.second)cout << it2 << " ";cout << endl;
		// }
		map<char, ll> degree;for(auto it: cnts)degree[it.first] = adj_list[it.first].size();
		ll tot = 0;for(auto it:degree)tot += it.second;
		// cout << strt << endl;
		vis.clear();
		if(tot < 2*(n - 1)){
			cout << "No answer" << endl;
		} else{
			for(auto it2: cnts){
				for(auto it:cnts)vis[it.first] = false;
				char let = it2.first;
				vector<char> x = dfs(let);
				if(x.size() == l){for(auto it: x)cout << it;cout << endl;break;}				
			}
		}
	}
}