#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n,k;cin >>n>>k ;
	if (k == n - 1)
	{
		for(int i=n;i>=1;i--)cout << i<<" ";
	}
	else if (k == 0)
	{
		for(int i=1;i<=n;i++)cout << i<<" ";
	}
	else{
		for (int i = k+1; i <= n; ++i)		
			cout << i << " " ;		
		for (int i = k; i >= 1; --i)
			cout << i << " " ;
	}
	return 0;
}