#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,L;cin>>n>>L;
	vector<ll>c(n),v(n);for(int i=0;i<n;i++)cin >> c[i] ;
	v[0]=1;for(int i=1;i<n;i++)v[i] = v[i-1] * (ll)2 ;

	if(n == 1)cout << c[0]*L<< endl ;

	else{
		ll ans = 0;
		ll curr = L ;		

		vector<ll> precomp(n);
		for(int i=0;i<n;i++)
		{
			precomp[i] = c[i] ;
			for(int j=0;j<=i;j++){
				precomp[i] = min(precomp[i], (v[i]/v[j]) * c[j]);
			}
		}
		// for(auto it: precomp)cout << it << " ";
		// cout << endl;

		vector<ll>decomp;
		decomp.push_back(L);
		while(curr != 0){
			int j = n-1;
			while(curr < (ll)pow(2,j) )j--;
			curr = curr % (ll)pow(2,j);
			decomp.push_back(curr) ;
		}
		// for(auto it: decomp)cout << it << " ";
		// cout << endl;

		map<ll,ll> dp ;dp[0] = 0 ;

		reverse(decomp.begin(),decomp.end());
		for(int i=1;i<decomp.size();i++){
			int j = n-1;
			curr = decomp[i] ;
			while(curr < (ll)pow(2,j) )j--;
			ll q = curr/(ll)pow(2,j), r = curr % (ll)pow(2,j) ;
			ll part1,part2;
			part2 = q*precomp[j] + dp[r] ;
			// cout << part2 << endl;
			ll mnm = 2e18;
			for(int j=0;j<n;j++)mnm = min(mnm, (ll)ceil((double)decomp[i]/(double)v[j]) * c[j]) ;
			part1 = mnm ;
			// cout << part1 << endl;
			dp[decomp[i]] = min(part1, part2);
		}
		cout << dp[L] << endl ;
	}

	return 0;
}