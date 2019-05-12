// C. Fountains  CF# 413 - (combined)
// 3 cases --> all from one, all from other, 1 from each
// 1 from each --> highest beauty in affordable cost
// 2 from each --> Sort (cost, beauty) based on cost & take one by one and see possible options for the other using bin search on cost and calc prefix max of beauty on possible ones.
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll n,c,d;
vector<pair<ll,ll>> C,D, C_prefix_mx, D_prefix_mx;

ll bin_search(ll idx, ll choice){
	if(choice == 1){
		ll remn = c - C[idx].first ;
		ll idx2 = upper_bound(C.begin(), C.end(), make_pair(remn, (ll)1e18)) - C.begin();idx2--;
		// cout << remn << " " << idx2 << endl;
		if(idx2 >= 0){
			if(idx2 == 0 && idx != idx2)return 0;
			else if(idx2 == 0 && idx == 0)return -1;
			if(idx == C_prefix_mx[idx2].first)return C_prefix_mx[idx2].second;
			else return C_prefix_mx[idx2].first;
		}
		else return -1;
	}
	else if(choice == 2){
		ll remn = d - D[idx].first ;
		ll idx2 = upper_bound(D.begin(), D.end(), make_pair(remn, (ll)1e18)) - D.begin();idx2--;
		// cout << remn << " " << idx2 << endl;
		if(idx2 >= 0){
			if(idx2 == 0 && idx != idx2)return 0;
			else if(idx2 == 0 && idx == 0)return -1;
			if(idx == D_prefix_mx[idx2].first)return D_prefix_mx[idx2].second;
			else return D_prefix_mx[idx2].first;
		}
		else return -1;
	}
	return -1;
}

int main(){
	cin >> n >> c >> d ;
	for(int i=0;i<n;i++){
		ll b,p;string str;
		cin >> b >> p >> str;
		pair<ll,ll> pr = make_pair(p,b);
		if(str == "C")C.push_back(pr);
		else D.push_back(pr);
	}
	sort(C.begin(),C.end());sort(D.begin(),D.end());
	if(!C.empty())C_prefix_mx.resize(C.size());
	if(!D.empty())D_prefix_mx.resize(D.size());

	for(int i=1;i<C.size();i++){
		if(i == 1){
			if(C[0].second > C[1].second)C_prefix_mx[i] = make_pair(0,1);
			else C_prefix_mx[i] = make_pair(1,0);
		}
		else{
			pair<ll,ll> prev = C_prefix_mx[i-1],pr = prev;
			if(C[i].second > C[prev.first].second){pr.first = i;pr.second = prev.first;}
			else if(C[i].second > C[prev.second].second){pr.second = i;}
			C_prefix_mx[i] = pr;
		}
	}
	for(int i=1;i<D.size();i++){
		if(i == 1){
			if(D[0].second > D[1].second)D_prefix_mx[i] = make_pair(0,1);
			else D_prefix_mx[i] = make_pair(1,0);
		}
		else{
			pair<ll,ll> prev = D_prefix_mx[i-1],pr = prev;
			if(D[i].second > D[prev.first].second){pr.first = i;pr.second = prev.first;}
			else if(D[i].second > D[prev.second].second){pr.second = i;}
			D_prefix_mx[i] = pr;
		}
	}
	// for(auto it: C_prefix_mx)cout << it.first << " " << it.second << endl;
	// for(auto it: D_prefix_mx)cout << it.first << " " << it.second << endl;

	vector<ll> C_possible,D_possible;

	ll part1=0,part2=0;
	if(!C.empty()){
		for(int i=0;i<C.size();i++){
			if(C[i].first <= c){
				C_possible.push_back(i);
				part1 = max(C[i].second, part1);
			}
		}
	}
	if(!D.empty()){
		for(int i=0;i<D.size();i++){
			if(D[i].first <= d){
				D_possible.push_back(i);
				part2 = max(D[i].second, part2);
			}
		}
	}
	// for(auto it: C_possible)cout << it << " ";cout << endl;
	// cout << "demarcate"<<endl;
	// for(auto it: D_possible)cout << it << " ";cout << endl;

	ll answer = 0;
	if(!C_possible.empty() && !D_possible.empty())answer = part1 + part2;
	for(int i=0;i<C_possible.size();i++){
		ll i2 = bin_search(C_possible[i], 1);
		// cout << i2 << endl;
		if(i2 != -1)answer = max(answer, C[i2].second + C[C_possible[i]].second);
	}
	for(int i=0;i<D_possible.size();i++){
		ll i2 = bin_search(D_possible[i], 2);
		// cout << i2 << endl;
		if(i2 != -1)answer = max(answer, D[i2].second + D[D_possible[i]].second);
	}
	cout << answer << endl;

}