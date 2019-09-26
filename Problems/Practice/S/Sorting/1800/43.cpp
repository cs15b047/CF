#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n; cin >> n;
	vector<ll>a(2*n + 1);for(int i = 1;i <=2*n;i++)cin >> a[i];
	map<ll,set<ll>> cnts;for(int i = 1;i <=2*n;i++)cnts[a[i]].insert(i);
	vector<ll> answer(2*n + 1, 0);
	vector<ll> remn, r2;
	for(auto it: cnts){
		if(it.second.size() > 1){
			ll num = it.first;
			int p = 0;
			ll last = *it.second.rbegin();
			for(auto it2:it.second){
				if(it.second.size() % 2 == 1 && it2 == last)break;
				answer[it2] = p + 1;
				p = 1 - p;
			}
			if(it.second.size() % 2 == 1)remn.push_back(last);
		} else{
			r2.push_back(*it.second.begin());
		}
	}
	int p = 0;
	for(auto it: r2){
		answer[it] = p + 1;
		p = 1 - p;
	}
	for(auto it: remn){
		answer[it] = p + 1;
		p = 1 - p;
	}
	set<ll> s1, s2;
	for(int i = 1;i <= 2*n;i++){
		if(answer[i] == 1)s1.insert(a[i]);
		else if(answer[i] == 2)s2.insert(a[i]);
	}
	ll distinct = s1.size() * s2.size();
	cout << distinct << endl;
	for(int i = 1;i <= 2*n;i++)cout << answer[i] << " ";
}