#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll;

int main(){
	ll n; cin >> n;
	vector<set<ll>> sets(((n*(n-1))/2));
	ll sz2 = (n*(n-1))/2;
	for(int i=0;i<sz2;i++){
		ll sz; cin >> sz;
		for(int j = 0;j<sz;j++){ll x;cin >>x;sets[i].insert(x);}
	}
	if(n > 2){
		map<ll, set<ll>> locations;
		for(int j = 0;j < sz2 ; j++){
			for(auto it: sets[j]){
				locations[it].insert(j);
			}
		}
		map<set<ll>, set<ll>> mapping;
		for(auto it: locations){
			mapping[it.second].insert(it.first);
		}
		for(auto it: mapping){
			cout << it.second.size() << " ";
			for(auto it2: it.second)cout << it2 <<" ";cout << endl;
		}
	} else if(n == 2) {
		cout << 1 <<  " " << *(sets[0].begin()) << endl;
		sets[0].erase(*(sets[0].begin()));
		cout << sets[0].size() << " ";
		for(auto it: sets[0])cout << it << " "; cout << endl;
	}
}