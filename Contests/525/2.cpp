#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,k;cin >> n >> k;
	vector<ll> a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	ll subt = 0;
	ll ind = 0;
	for(int i=0;i<k;i++){
		while(ind < n && a[ind] == subt)ind++;
		if(ind == n){printf("0\n");continue;}
		else{
			printf("%lld\n",a[ind] - subt );
			subt += (a[ind] - subt);
		}
	}
}