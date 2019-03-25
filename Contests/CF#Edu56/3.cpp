#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n ;
	vector<ll> b(n/2);for(int i=0;i<n/2;i++)scanf("%lld",&b[i]);
	vector<ll>a(n);
	for(int i=0;i<n/2;i++){
		if(i == 0){a[0] = 0;a.back() = b[0];}
		else{
			if(b[i] - a[n-i] >= a[i-1]){
				a[n - 1 - i] = a[n - i];
				a[i] = b[i] - a[n-i];
			}
			else{
				a[i] = a[i-1];
				a[n - 1 - i] = b[i] - a[i - 1];
			}
		}
	}
	for(auto it:a)cout << it << " "; cout << endl;
}