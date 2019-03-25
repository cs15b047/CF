#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int sum_dig(ll x)
{
	int ans = 0;
	while(x != 0){
		ans += (x%10);x = x /10;
	}
	return ans ;
}

int main(int argc, char const *argv[])
{
	int n ;cin>>n;
	vector<int>sol;
	if(n > 81){
		for(int k=n-81;k<=n;k++){
			if(k + sum_dig(k) == n)sol.push_back(k);
		}
	}
	else{
		for(int k=1;k<=n;k++){
			if(k + sum_dig(k) == n)sol.push_back(k);
		}
	}
	cout << sol.size() <<endl ;
	for(int i=0;i<sol.size();i++)cout << sol[i] <<" ";
	
	return 0;
}