#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n,c,b;cin>>n>>c>>b ;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i] ;
	int flag = 1;
	ll ans = 0 ;
	for(int i=0;i<n/2;i++){
		if((a[i] == 0 && a[n-1-i] ==1) || (a[i] == 1 && a[n-1-i] ==0)){
			flag = 0;break ;
		}
		else if((a[i] == a[n-1-i] && a[i] !=2)){}
		else if((a[i] == a[n-1-i] && a[i] ==2)){
			ans += 2*min(c,b);
		}
		else if(a[i] != 2){
			ans += (a[i] == 1) *b + (a[i] == 0) *c ;
		}
		else if(a[n-1-i] != 2){
			ans += (a[n-1-i] == 1) *b + (a[n-1-i] == 0) *c ;
		}
	}
	if(n % 2 == 1 && a[n/2] == 2){
		ans += min(c,b);
	}

	if(flag == 0)cout << "-1"<<endl;
	else cout << ans <<endl ;
	
	return 0;
}