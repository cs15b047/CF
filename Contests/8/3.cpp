#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int gcd(int x, int y){
	if(y==0)return x;
	return gcd(y, x % y);
}

int main()
{
	ll n;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int G=a[0];
	for(int i=1;i<n;i++)G = gcd(G,a[i]);
	int mxm =1;
	for(int i=0;i<n;i++){a[i] = a[i]/G ;mxm = max(mxm,a[i]);}
	bool arr[4001];
	int lim = (int)(sqrt(mxm));
	for(int i=2;i<=lim;i++){
		if(!arr[i]){
			for(int j=2*i;j<=lim;j+=i){
				arr[j] = 1;
			}
		}
	}

	vector<int>primes;
	for(int i=2;i<=lim;i++){
		if(!arr[i])primes.push_back(i);
	}
	map<int,int> mymap ;
	for(auto it: a){
		int x = it,j=0;
		while(x != 1 && j< primes.size()){
			if(x % primes[j] == 0){
				while(x%primes[j]==0){
					x = x/ primes[j] ;
				}
				mymap[primes[j]]++;
			}
			j++;
		}
		if(x != 1){
			mymap[x]++;
		}
	}
	int ans = INT_MAX ;
	for(auto it:mymap){
		ans = min((ll)ans, n - (ll)it.second);
	}
	if(ans == INT_MAX){
		cout << -1 << endl ;
	}
	else
		cout << ans << endl ;



	
	return 0;
}