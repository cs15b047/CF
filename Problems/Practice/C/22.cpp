#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	int n;cin>>n ;	
	vector<ll>a(n),b(n),ind(n),a_s;
	vector<pair<ll,ll>> data(n) ;
	map<ll,ll>posn_to_ind ;
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i] ;
		data[i] = make_pair(a[i],b[i]) ;
	}
	
	sort(data.begin(),data.end());
	for(int i=0;i<n;i++)posn_to_ind[data[i].first] = i ;
	for(int j=0;j<n;j++)a_s.push_back(data[j].first) ;

	vector<ll> dp(n);
	dp[0] = 1 ;
	ll ans = n-1 ;
	for(int i=1;i<n;i++){
		if(posn_to_ind.find(data[i].first - data[i].second) != posn_to_ind.end()){
			if(posn_to_ind[data[i].first - data[i].second] == 0){
				dp[i] = 1;
			}
			else{
				dp[i] = 1 + dp[posn_to_ind[data[i].first - data[i].second] - 1] ;
			}
		}
		else{			
			
			int pos = upper_bound(a_s.begin(),a_s.end(),data[i].first - data[i].second) - a_s.begin() ;
			if(pos == 0){
				dp[i] = 1;
			}
			else dp[i] = 1 + dp[pos - 1] ;
		}
		ans = min(ans,n - dp[i]) ;
	}
	cout << ans << endl ;
	
	return 0;
}