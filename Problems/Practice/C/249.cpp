#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<ll,ll>> pairs;

bool cmp1(ll idx1, ll idx2){
	pair<ll,ll> pr1 = pairs[idx1], pr2= pairs[idx2];
	return pr1.first > pr2.first;
}

bool cmp2(ll idx1, ll idx2){
	pair<ll,ll> pr1 = pairs[idx1], pr2= pairs[idx2];
	return pr1.first < pr2.first;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	pair<ll,ll> pr;
	vector<ll> idxs1, idxs2;
	for(int i = 0;i < n;i++){
		ll first, second;
		cin >> first >> second;
		pr = make_pair(first, second);
		pairs.push_back(pr);
		if(first < second)idxs1.push_back(i);
		else idxs2.push_back(i);
	}
	sort(idxs1.begin(), idxs1.end(), cmp1);
	sort(idxs2.begin(), idxs2.end(), cmp2);

	if(idxs1.size() > idxs2.size()){
		cout << idxs1.size() << endl;
		for(auto it: idxs1)cout << it + 1 << " "; cout << endl;
	} else{
		cout << idxs2.size() << endl;
		for(auto it: idxs2)cout << it + 1 << " "; cout << endl;
	}

}