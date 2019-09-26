#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, m, v; cin >> n >> m >> v ;
	vector<ll> comp1;
	ll comp2 = 0;
	for(int i=1;i <= n;i++){
		if(comp2 == 0 && i != v){
			comp2 = i;
		} else if(i != v){
			comp1.push_back(i);
		}
	}
	if(m > (((n - 1)*(n - 2))/2) + 1){
		cout << -1 << endl;
	} else if( m < n - 1){
		cout << -1 << endl;
	} else {
		vector<pair<ll,ll>> edges;
		edges.push_back(make_pair(comp2, v));
		for(int i=0; i < n - 2;i++){
			if(i == 0)edges.push_back(make_pair(v, comp1[i]));
			else {
				edges.push_back(make_pair(comp1[i - 1], comp1[i]));
			}
		}
		int i = n;
		if(i <= m){
			for(int j = 0; j < comp1.size();j++){
				for(int k = j + 2; k < comp1.size();k++){
					edges.push_back(make_pair(comp1[j], comp1[k]));
					i++;
					if(i  > m)break;
				}
				if(i  > m)break;
			}
			if(i <= m){
				for(int j = 1;j < comp1.size();j++){
					edges.push_back(make_pair(v, comp1[j]));
					i++;
					if(i  > m)break;	
				}
			}
		}
		for(auto it:edges)cout << it.first << " " << it.second << endl;
	}
}