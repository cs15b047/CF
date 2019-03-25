#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll grid[2001][2001]={};
int main(){
	ll n;cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&grid[i][j]);
	map<ll,ll> w1,b1,w2,b2;

	for(int i=0;i<n;i++){
		ll diag_sum=0,diag_sum2=0;
		for(int j=1;j<=n-i;j++){
			diag_sum += grid[i+j][j] ;
		}
		for(int j=1;j<=n-i;j++){
			diag_sum2 += grid[j][i+j];
		}
		if(i % 2 == 0){w1[i] = diag_sum;w1[-i] = diag_sum2;}
		else {b1[i] = diag_sum ;b1[-i] = diag_sum2;}
	}
	for(int i=2;i<=2*n;i++){
		ll diag_sum =0;
		for(int j=i-1;j>=1;j--){
			if(j<=n && j>=1 && i-j >= 1 && i-j<=n){
				diag_sum += grid[j][i-j];
			}
		}
		if(i%2==0)w2[i] = diag_sum ;
		else b2[i] = diag_sum ;
	}
	// for(auto it:w1)cout << it.first <<" " << it.second <<endl;
	// cout<<endl;
	// for(auto it:w2)cout << it.first <<" "<< it.second <<endl;
	// cout<<endl;
	// for(auto it:b1)cout << it.first <<" "<< it.second <<endl;
	// cout<<endl;
	// for(auto it:b2)cout << it.first <<" "<< it.second <<endl;
	// cout<<endl;
	ll p1 = -1,p2=-1,p3=-1,p4=-1,i1,i2,i3,i4;
	ll x1,y1,x2,y2;
	map<ll,ll> m1,m2;
	m1 = w1;m2=w2;
	for(int i=0;i<n;i+=2){		
		for(int j=1;j<=n-i;j++){
			if(m1[i] + m2[i+2*j]-grid[i+j][j] > p1){p1 = m1[i] + m2[i+2*j]-grid[i+j][j];x1 = i+j;y1=j;}
			if(m1[-i]+m2[i+2*j]-grid[j][i+j] > p1){p1 = m1[-i] + m2[i+2*j]-grid[j][i+j];x1 = j;y1=i+j;}
		}
	}
	m1 = b1;m2=b2;
	for(int i=1;i<n;i+=2){		
		for(int j=1;j<=n-i;j++){
			if(m1[i] + m2[i+2*j]-grid[i+j][j] > p2){p2 = m1[i] + m2[i+2*j]-grid[i+j][j];x2 = i+j;y2=j;}
			if(m1[-i]+m2[i+2*j]-grid[j][i+j] > p2){p2 = m1[-i] + m2[i+2*j]-grid[j][i+j];x2 = j;y2=i+j;}
		}
	}
	cout << p1 + p2 <<endl;
	cout<<x1<<" " <<y1<<" " <<x2<<" " <<y2;

}