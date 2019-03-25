#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll n;cin>>n;
	vector<ll>l(n),r(n),tot(n),pred(n);
	for(int i=0;i<n;i++)scanf("%lld",&l[i]);
	for(int i=0;i<n;i++)scanf("%lld",&r[i]);

	for(int i=0;i<n;i++)tot[i] = l[i] + r[i];
	for(int i=0;i<n;i++)pred[i] = n - tot[i] ;

	int flag =1;
	for(int i=0;i<n;i++){
		ll cl=0,cr=0;
		for(int j=0;j<i;j++){
			if(pred[j] > pred[i])cl++;
		}
		for(int j=i+1;j<n;j++){
			if(pred[j] > pred[i])cr++;
		}
		if(cl != l[i] || cr != r[i]){
			flag = 0;
			break;
		}
	}
	if(flag){
		cout << "YES"<<endl;
		for(auto it:pred)cout << it << " ";
		cout << endl;
	}
	else cout << "NO" << endl;
}