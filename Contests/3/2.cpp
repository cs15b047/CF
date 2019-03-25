#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	string s,t ;cin>>s>>t ;
	int ptr1 = s.length()-1, ptr2 = t.length()-1;

	while(ptr1 >= 0 && ptr2 >=0 && s[ptr1] == t[ptr2]){
		ptr1--;ptr2-- ;
	}
	int ans = 0 ;
	if (ptr1 >= 0)
	{
		ans += ptr1 + 1 ;
	}
	if (ptr2 >= 0)
	{
		ans += ptr2 + 1 ;
	}
	cout << ans << endl ;


	return 0;
}