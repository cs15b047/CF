#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,l,r; scanf("%lld%lld%lld",&n,&l,&r);
	vector<ll> a(n),p(n),b(n),c(n),a_new(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);for(int i=0;i<n;i++)scanf("%lld",&p[i]);
	for(int i=0;i<n;i++)a_new[p[i] - 1] = a[i];
	vector<ll> pos_to_rank(n);for(int i=0;i<n;i++)pos_to_rank[i] = p[i] - 1;

	// for(int i=0;i<n;i++)cout << a_new[i] << " ";cout << endl;
	// for(int i=0;i<n;i++)cout << pos_to_rank[i] << " ";cout << endl;

	int flag = 1;
	for(int i=0;i<n;i++){
		ll least;
		if(i == 0)least = l;
		else least = a_new[i] + b[i-1] - a_new[i-1] + 1;

		if(least <= r)b[i] = max(l, least);
		else{
			flag = -1;
			break;
		}
	}
	if(flag == 1){
		vector<ll>b_new(n);
		for(int i=0;i<n;i++)b_new[i] = b[pos_to_rank[i]];
			for(auto it:b_new)cout << it << " " ;cout << endl;
	}
	else printf("-1\n");


}