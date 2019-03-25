#include<bits/stdc++.h>
using namespace std ;

long long int fn(long long int y){
	return y/2 + (((y/2) * 2) != y) ;
}

int main(int argc, char const *argv[])
{	
	long long int n,q;cin>>n>>q; 
	for (int i = 0; i < q; ++i)
	{
		long long int x,y;cin>>x >> y ;x--;y--;
		long long int ans;
		if (x == 0 && y ==0)
		{
			cout << 1 <<endl ;continue ;
		}
		else if (n % 2 == 0)
		{			
			
			if ((x+y )%2 == 0)
			{
				ans =  x * (n/2) ;
				ans += fn(y) + (x %2 == 0) ;
			}
			else{
				ans = (n*n)/2 ;
				ans += x * (n/2) ;
				ans += fn(y) + (x %2 == 1) ;
			}
		}
		else if(n % 2  == 1){
			if ((x+y)%2 == 0)
			{
				ans = (x/2)*n + (x%2 == 1)*(n/2+1) ;
				ans += fn(y)+ (x%2==0) ;
			}
			else{
				ans = fn((n*n)) + (x/2)*n + (x%2)*(n/2) ;
				ans += fn(y) + (x %2==1) ;
			}
		}
		cout << ans << endl ;
	}
	
	return 0;
}