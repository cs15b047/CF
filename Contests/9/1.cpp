#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
int main()
{
	ll n;cin>>n;
	ll ax,ay,bx,by,cx,cy;cin>>ax>>ay>>bx>>by>>cx>>cy;

	if(((bx-ax)*(cx-ax) > 0) && ((by-ay)*(cy-ay) > 0)){
		// if(((abs(by-ay)>abs(bx-ax)) && (abs(cy-ay)>abs(cx-ax))) || ((abs(by-ay)<abs(bx-ax)) && (abs(cy-ay)<abs(cx-ax))) ){
		// 	
		// }
		cout << "YES"<<endl;
	}
	else cout << "NO"<<endl;
}