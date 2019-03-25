#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n ;cin >>n ;

	vector<bool> v(1000001) ;
//false --> prime
	for(int i=2;i<=1000000;i++)
	{
		if (!v[i])
		{
			for(int j=2*i;j<=1000000;j+=i)v[j] = true ;
		}
	}


	for (int i = 0; i < n; ++i)
	{
		ll x ;cin >> x ;
		ll s = (ll)sqrt(x) ;
		if(s*s == x && x != 1 && (!v[s]))cout << "YES"<<endl ;
		else cout << "NO"<<endl ;
	}

	return 0;
}