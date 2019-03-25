#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	double n,m,ans; cin>>m>>n;
	ans = m ;

	for(int i=1;i<=m-1;i++){
		ans = ans - pow(((m-(double)i)/m), n);
	}
	cout << ans <<endl ;


	return 0;
}