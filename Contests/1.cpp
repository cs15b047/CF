#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
double dist(ll x1,ll y1, ll x2, ll y2){
	
}
int main(){
	ll n,m;scanf("%lld",&n,&q);
	vector<ll>x(n),y(n),r(n);
	for(int j=0;j<n;j++)scanf("%lld%lld%lld",&r[j],&x[j],&y[j]);
	vector<pair<double, double>> answer;
	vector<ll>cnt(1000001);
	for(int j=0;j<n;j++){
		for(int k=j+1;k<n;k++){
			double d = dist(x[j],y[j],x[k],y[k]);
			double rbig = max(r[j],r[k]),rsmall = min(r[j],r[k]);
			if(d + rsmall < rbig){
				dist.push_back( make_pair( rbig - (d+rsmall), d+rbig+rsmall));
			}
			else{
				dist.push_back(make_pair(max(d-(rbig+rsmall), (double)0), d + rbig + rsmall)) ;
			}
		}
	}

	


}