#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,k; cin >> n >> k ;
	vector<ll> array(n);for(int i=0;i<n;i++)scanf("%lld",&array[i]);

	vector<ll> zeros,ones,prefix_z,prefix_o,locn_z,locn_o;
	int strt = 0;
	while(strt < n){
		int itr = strt;
		while(itr < n && array[itr] == array[strt])itr++;
		if(array[strt] == 1){ones.push_back(itr - strt);locn_o.push_back(strt);}
		if(array[strt] == 0){zeros.push_back(itr - strt);locn_z.push_back(strt);}
		strt = itr;
	}
	prefix_z.resize(zeros.size());prefix_z[0] = zeros[0];
	for(int i =1;i < zeros.size();i++){
		prefix_z[i] = prefix_z[i-1] + zeros[i];
	}
	prefix_o.resize(ones.size());prefix_o[0] = ones[0];
	for(int i =1;i < ones.size();i++){
		prefix_o[i] = prefix_o[i-1] + ones[i];
	}

	for(auto it:zeros)cout << it << " ";cout << endl;
	for(auto it:ones)cout << it << " ";cout << endl;
	for(auto it:prefix_z)cout << it << " ";cout << endl;
	for(auto it:prefix_o)cout << it << " ";cout << endl;

	if(prefix_z.back() >= k)cout << n << endl;
	else{
		for(int i = 0;i < prefix_z.size();i++){
			ll strt;
			if(i == 0)strt = 0;
			else{
				ll end = lower_bound(prefix_z.begin(),prefix_z.end(),strt + k);
			}


		}
	}



}