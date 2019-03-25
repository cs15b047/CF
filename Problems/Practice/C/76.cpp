#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	FILE* ip = fopen("input.txt","r");
	ll n;fscanf(ip,"%lld",&n);
	vector<ll>t(n),pref(n),suff(n);for(int i=0;i<n;i++)fscanf(ip,"%lld",&t[i]);
	
	pref[0] = (t[0] >= 0);
	for(int i=1;i<n-1;i++){
		pref[i] = pref[i-1] + (t[i] >= 0);
	}
	suff[n-1] = (t[n-1] <= 0) ;
	for(int i=n-2;i>=1;i--){
		suff[i] = suff[i+1] + (t[i] <= 0);
	}
	ll ans = 1000000000000000000;
	for(int i=0;i<n-1;i++){
		ans = min(ans, pref[i] + suff[i+1]);
	}
	FILE* op = fopen("output.txt","w");
	fprintf(op, "%lld\n",ans );
	fclose(ip);fclose(op);
}