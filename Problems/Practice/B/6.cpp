#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	int n,d,h;cin >> n >> d >> h ;
	int curr = 2 ;

	if((d == 1 && n > 2) || (d > 2*h)){
		cout << -1 <<endl ;
	}
	else{
		for(int i=0;i<h;i++){
			cout << curr -1 << " " << curr <<endl ;
			curr++ ;
		}
		for(int i=0;i<d-h;i++){
			if(i==0){
				cout << 1 << " " << curr <<endl ;
			}
			else{
				cout << curr -1 << " " << curr <<endl ;
			}
			curr++;
		}
		for(int i=0;i<n-(d+1);i++){
			string str = "1 ";
			if(h == d)str = "2 ";
			cout << str <<curr <<endl ;
			curr++;
		}
	}
	return 0;
}