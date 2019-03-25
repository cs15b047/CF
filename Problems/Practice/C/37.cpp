#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll k,a,b;scanf("%lld%lld%lld",&k,&a,&b);

	if(a/k + b/k == 0)cout << -1 << endl;
	else if((a/k == 0 && b % k != 0) || (b/k == 0 && a % k != 0) )cout << -1 << endl;
	else cout << (a/k + b/k) << endl ;
}