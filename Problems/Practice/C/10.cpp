#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n,m;cin>>n>>m ;
	vector<ll> a(n),inc(n),dec(n);

	for(int i=0;i<n;i++)cin>>a[i] ;
	int j = 0;
	while(j < n){
		int strt = j ;
		while(j < n-1 && a[j] <= a[j+1])j++;
		int tmp = j ;
		while(tmp >= strt){
			inc[tmp] = j - tmp + 1 ;
			tmp--;
		}
		j++;
	}
	j=0;
	while(j < n){
		int strt = j ;
		while(j < n-1 && a[j] >= a[j+1])j++;
		int tmp = j ;
		while(tmp >= strt){
			dec[tmp] = j - tmp + 1 ;
			tmp--;
		}
		j++;
	}

	for (int i = 0; i < m; ++i)
	{
		ll l,r;cin>>l>>r;l--;r--;
		if(l + inc[l] - 1 >= r)cout << "Yes"<<endl ;
		else{
			int mid = l + inc[l] - 1;
			if(mid + dec[mid] - 1 >= r)cout << "Yes"<<endl ;
			else cout << "No"<<endl ;
		}
	}



	return 0;
}