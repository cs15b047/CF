#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n; cin >> n;
	map<ll,set<string>> grp;for(int i = 0;i<n;i++){string str;ll num;cin >> str >> num;grp[num].insert(str);}
	vector<string> order;for(auto it:grp)for(auto it2:it.second)order.push_back(it2);
	vector<string> ht_order;
	bool fail  = false;
	for(auto it:grp){
		if(it.second.size() + it.first > n){fail = true;break;}
		if(it.first > ht_order.size()){fail = true;break;}

		stack<string> temp;
		ll num_ele_popped = it.first;
		for(int i = 0;i < num_ele_popped;i++){temp.push(ht_order.back());ht_order.pop_back();}
		for(auto it2:it.second)ht_order.push_back(it2);
		while(!temp.empty()){ht_order.push_back(temp.top());temp.pop();}
	}
	if(!fail){
		map<string, ll> answer;ll init = 1;for(auto it:ht_order){answer[it] = init++;}
		for(auto it: order)cout << it << " " << answer[it] << endl;
	} else{
		cout << -1 << endl;
	}
}