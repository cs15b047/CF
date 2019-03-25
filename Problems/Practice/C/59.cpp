#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

vector<ll>a;
bool comp(ll i1,ll i2){
	return a[i1] < a[i2];
}

int main(){
	ll n;cin>>n;
	vector<ll>ind1(n),ind2;
	a.resize(n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)ind1[i] = i;
	ind2 = ind1;
	
	sort(ind2.begin(),ind2.end(),comp);

	int curr = 0;
	map<ll,bool> vis;
	vector<set<ll>> ans;
	while(vis.size() < n){
		while(vis.find(curr) != vis.end())curr++;
		
		set<ll> tmp;
		int ptr = curr;
		while(tmp.find(ptr) == tmp.end()){
			if(vis.find(ptr) != vis.end()){cout << "Gadbad"<< endl;exit(0);}
			tmp.insert(ptr);
			vis[ptr] = true;
			ptr = ind2[ptr];
		}
		ans.push_back(tmp);
	}
	cout << ans.size() << endl;
	for(auto it_vec: ans){
		cout << it_vec.size() << " ";
		for(auto it_set: it_vec){
			cout << it_set + 1 << " ";
		}
		cout << endl ;
	}


}