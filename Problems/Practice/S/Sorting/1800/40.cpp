#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n, k; cin >> n >> k;
	vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
	set<ll> unvis;for(int i=0;i<n;i++)unvis.insert(a[i]);
	vector<bool> vis(n, false);
	vector<ll> team(n, 0);
	map<ll,ll> val_pos;for(int i=0;i<n;i++)val_pos[a[i]] = i;
	set<ll> posns;for(int i = 0;i < n;i++)posns.insert(i);

	ll curr = 0;
	while(!unvis.empty()){
		ll largest = *unvis.rbegin();
		ll pos = val_pos[largest];
		vis[pos] = true;
		team[pos] = curr;
		auto it = posns.find(val_pos[largest]), it2 = it;
		vector<ll> r1, r2;
		for(int i = 0;i <= k;i++){
			r1.push_back(*it2);
			vis[*it2] = true;
			unvis.erase(a[*it2]);
			team[*it2] = curr;
			if(it2 == posns.begin()){
				break;
			} else{
				it2--;
			}
		}
		it2 = it;
		for(int i = 0;i <= k;i++){
			r2.push_back(*it2);
			vis[*it2] = true;
			unvis.erase(a[*it2]);
			team[*it2] = curr;
			if(*it2 == *posns.rbegin()){
				break;
			} else{
				it2++;
			}
		}
		for(auto x: r1){
			posns.erase(x);
			unvis.erase(a[x]);
		}
		for(auto x: r2){
			posns.erase(x);
			unvis.erase(a[x]);
		}
		curr = 1 - curr;
	}
	for(auto x:team)cout << x + 1;cout << endl;


}