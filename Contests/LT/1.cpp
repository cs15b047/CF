#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll t;scanf("%lld",&t);
	for(int i=0;i<t;i++){
		ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
		if((x+y==z) || (y+z==x) || (z+x == y))printf("yes\n");
		else printf("no\n");
	}
}