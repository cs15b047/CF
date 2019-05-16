// A. Partial Teacher  CF# Manthan 2011
// Top sort graph formed by edges of comparison L,R. Handle = by eliminating those nodes by keeping map from multiple equal to a representative node
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	string str; cin >> str;
	vector<set<ll>> adj(n + 1);
	ll curr = 1;
	map<ll,ll> equals;
	vector<set<ll>> eq(n +1);
	vector<ll> indegree(n + 1, 0);
	for(int i=1;i<=n-1;i++){
		if(str[i - 1] == '='){equals[i+1] = curr;eq[curr].insert(i+1);}
		else if(str[i - 1] == 'L'){adj[i + 1].insert(curr);indegree[curr]++;curr = i + 1;}
		else if(str[i - 1] == 'R'){adj[curr].insert(i + 1);indegree[i + 1]++;curr = i + 1;}
	}
	queue<ll> q;
	vector<ll> val(n + 1, 0);
	for(int i=1;i<=n;i++){
		if((equals.find(i) == equals.end() && indegree[i] == 0)){
			q.push(i);
			val[i] = 1;
			for(auto it:eq[i])val[it] = val[i];
		}
	}
	// for(int i=1;i<=n;i++)cout << val[i] << " ";cout << endl;

	while(!q.empty()){
		ll top = q.front();q.pop();
		// cout << top << endl;
		for(auto nbh: adj[top]){
			indegree[nbh]--;
			if(indegree[nbh] == 0){
				q.push(nbh);
				val[nbh] = val[top] + 1;
				for(auto it:eq[nbh])val[it] = val[nbh];
			}
		}
		// for(int i=1;i<=n;i++)cout << val[i] << " ";cout << endl;
	}
	for(int i=1;i<=n;i++)cout << val[i] << " ";cout << endl;

}