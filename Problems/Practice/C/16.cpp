#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

vector<ll> a,b,idx;
bool comp(int i,int j){
	return (a[i] - b[i]) < (a[j]- b[j]) ;
}

int main(int argc, char const *argv[])
{
	int n,k;cin>>n>>k ;
	a.resize(n);b.resize(n);idx.resize(n);
	for(int i=0;i<n;i++)cin>>a[i] ;
	for(int i=0;i<n;i++)cin>>b[i] ;
	for(int i=0;i<n;i++)idx[i] = i ;
	
	sort(idx.begin(),idx.end(),comp) ;
	
	int cnt = 0 ;
	for(int i=0;i<n;i++){
		if(a[idx[i]] - b[idx[i]] <= 0)cnt++ ;
		else break;
	}
	int mxm = max(cnt, k) ;
	ll ans =0;
	for(int i=0;i<n;i++){
		if(i < mxm)ans += a[idx[i]] ;
		else ans += b[idx[i]] ;
	}
	cout << ans <<endl ;
	return 0;
}