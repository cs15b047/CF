#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll t;scanf("%lld",&t);
	for(int i=0;i<t;i++){
		ll n,m;scanf("%lld%lld",&n,&m);
		vector<string>grid;grid.clear();grid.resize(n);
		for(int j=0;j<n;j++)cin >> grid[j];
		bool flag = true;
		if((n<=1) || (m<=1))flag=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(grid[j][k] == '.'){
					if(j==0){
						bool c1=0;
						if(k!=m-1)c1 = c1 || (grid[j+1][k] != "#") && (grid[j+1][k+1] != "#") && (grid[j][k+1] != "#") ;
						if(k!=0)c1 = c1 || (grid[j+1][k] != "#") && (grid[j+1][k-1] != "#") && (grid[j][k-1]!="#") ;
					}
				}
				if(!flag)break;
			}
			if(!flag)break;
		}
		if(!flag)cout << "NO"<< endl;
		else cout << "YES" << endl;
	}
}