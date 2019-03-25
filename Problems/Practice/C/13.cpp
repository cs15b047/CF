#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n,m;cin>>n>>m;
	int ans = 0;
	if(min(m,n) <= max(m,n)/2)ans = min(m,n);

	else{
		int x1 = (2*n-m)/3, y1 = (2*m-n)/3 ;
		ans = x1 + y1 ;
		if((2*(x1+1) + y1 <= n) && ((x1+1) + 2*y1 <= m))ans = max(ans,x1+1+y1) ;
		if((2*x1 + y1+1 <= n) && (x1 + 2*(y1+1) <= m))ans = max(ans,x1+1+y1) ;
		ans = max(max(n/2,ans),m/2) ;
	}
	cout << ans <<endl ;

	return 0;
}