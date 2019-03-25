#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n,m,k; cin >> n >> m >> k ;
	vector<ll>a(n);for(ll i=0;i<n;i++)cin >> a[i];
	map<ll,ll> M;
	for (int i = 0; i < n; ++i)M[a[i]]++;
	ll answer = 0;
	if(M.rbegin()->second > 1)answer = m * M.rbegin()->first;
	else{
		ll mxm = M.rbegin()->first, mxm2;
		M.erase(mxm);
		mxm2 = M.rbegin()->first;
		answer = (m/(k + 1))*(k*mxm + mxm2) + (m % (k + 1))* mxm ; 
	}
	cout << answer << endl;

}