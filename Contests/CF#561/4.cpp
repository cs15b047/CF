#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m;cin >> m >> n;
	vector<set<ll>> data(m), data2(m);
	for(int i=0;i<m;i++){
		ll sz ;cin >> sz;for(int j=0;j<sz;j++){ll x;cin >> x;data[i].insert(x);}
		for(int j=1;j<=n;j++){
			if(data[i].find(j) == data[i].end())data2[i].insert(j);
		}
	}
	int flag = 1;
	for(int i=0;i<m;i++){
		vector<ll> vec(n);
		for(int j = i +1;j < m;j++){

			auto it = set_difference(data[i].begin(), data[i].end(), data2[j].begin(), data2[j].end(), vec.begin());
			vec.resize(it-vec.begin());
			if(vec.size() == 0)flag = 0;
		}
	}
	if(flag == 0)cout << "impossible" << endl;
	else cout << "possible" << endl;
}