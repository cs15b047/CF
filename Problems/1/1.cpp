#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,h,a,b,k;cin>>n>>h>>a>>b>>k ;
	for(int i=0;i<k;i++){
		int q,w,e,r ;
		cin >> q>>w>>e>>r ;
		int ans ;

		if(q==e)ans = abs(w-r) ;
		else if(w <= b && w >= a)
			ans = abs(e-q) + abs(r - w) ;
		else if(w >= b)
			ans = abs(e-q) + w - b + abs(r -b) ;
		else if(w<=a)
			ans = abs(e-q) + a-w + abs(r-a) ;
		cout << ans <<endl ;		
	}

	

	return 0;
}