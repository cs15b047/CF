#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n;cin >> n;
	vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
	map<ll,ll> ele_cnt;for(int i=0;i<n;i++)ele_cnt[a[i]]++;
	ll answer = 0;
	if(ele_cnt.size() == 1)answer = 0;
	else{
		answer = (++ele_cnt.rbegin())->first ;
	}
	cout << answer << endl;
}