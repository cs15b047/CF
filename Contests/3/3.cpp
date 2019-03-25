#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	int n;cin>>n;
	vector<long long int> a(n) ;
	for(int i=0;i<n;i++)cin>>a[i] ;
	map<long long int,int>m;
	
	for (int i = 0; i < n; ++i)	
	{
		if (m.find(a[i]) == m.end())
		{
			m[a[i]] = 1 ;
		}else m[a[i]]++ ;
		
	}
	int ans = 0 ;
	for (auto i = m.begin(); i != m.end(); ++i)
	{
		// cout << ans << " "<< i->first <<" "<<i->second << endl ;
		long long int ele = i->first ;
		float pf = log2(ele) ; 
		if((int)pf == pf && i->second > 1)continue ;
		// else if((int)pf == pf && i->second == 1 && ele != 1) {ans += 1 ;continue;}
		
		int pi = (int)pf + 1 ;
		long long int maxm = m.rbegin()->first ;

		long long int reqd = (long long int)pow(2,pi) - ele ;
		while(reqd <= maxm && (m.find(reqd) == m.end() || (reqd == ele && m[reqd] == 1 )) ){
			pi++ ;
			reqd = (long long int)pow(2,pi) - ele ;
		}
		
		if (reqd > maxm)
		{
			ans += i->second ;	
		}
	}	
	cout << ans ;

	return 0;
}