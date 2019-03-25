#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9+7;
int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){
		ll n,k;cin>>n>>k;
		vector<ll>a(n);for(int j=0;j<n;j++)cin>>a[j];
		map<ll,ll>cnt;for(int j=0;j<n;j++)cnt[a[j]]++;
		if(cnt[0] + cnt[1] < n - k)cout << "NO"<<endl;
		else cout << "YES"<<endl;
	}
}