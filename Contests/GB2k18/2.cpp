#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n ;
	vector<ll> o_x(n),o_y(n);
	vector<ll> a(n), b(n);

	for(int i=0;i<n;i++)cin >> o_x[i] >> o_y[i];
	for(int i=0;i<n;i++)cin >> a[i] >> b[i];

	set<pair<ll,ll>> possible_ans;possible_ans.clear();
	
	for(int i=0;i<n;i++){
		possible_ans.insert(make_pair(a[0] + o_x[i], b[0] + o_y[i] ));
	}

	for(int i=1;i<n;i++){
		set<pair<ll,ll>> new_ans;new_ans.clear();
		for(int j=0;j<n;j++){
			pair<ll,ll> nw_pair = make_pair(a[i] + o_x[j], b[i] + o_y[j]);
			if(possible_ans.find(nw_pair) != possible_ans.end())new_ans.insert(nw_pair);
		}
		possible_ans = new_ans ;
	}

	cout << possible_ans.begin()->first << " " << possible_ans.begin()->second << endl;
}