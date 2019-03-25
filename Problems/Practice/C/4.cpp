#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin>>n;
	vector<ll> x(n);for(int i=0;i<n;i++)cin>>x[i] ;
	sort(x.begin(),x.end(),greater<ll>());
	int ans =0 ;
	ll curr_more;
	int j = 0;
	map<ll,int> cnt ;
	for (int i = 0; i < n; ++i)cnt[x[i]]++ ;	
	while(j < n)
	{
		auto it = cnt.rbegin();		
		curr_more = it->first ;
		it->second-- ;
		// cout << curr_more <<" "<<it->second<< endl ;
		it++ ;j++ ;
		while(j < n && curr_more > 0 && it != cnt.rend()){
			// cout << curr_more <<endl ;
			curr_more = min(curr_more - 1, it->first) ;
			it->second-- ;
			j++ ;
			it++ ;
		}
		if (j >= n)
		{
			// cout <<"Yahoo"<<endl ;
			ans++;break ;
		}
		else{
			
			map<ll,int> cnt2;
			for(auto it = cnt.begin(); it != cnt.end();it++){
				if (it->second != 0)cnt2[it->first] = it->second ;				
			}
			cnt = cnt2 ;
			ans++ ;
		}
	}
	cout << ans <<endl ;

	return 0;
}