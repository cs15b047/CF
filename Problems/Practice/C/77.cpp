#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll n,k,p;cin>>n>>k>>p;
	vector<ll>a(n);for(int i=0;i<n;i++)cin>>a[i] ;
	ll odds=0,evens=0;
	for(auto it:a){evens += (it %2==0) ;odds += (it %2==1) ;}
	set<ll>e,o;for(auto it:a){if(it%2==0)e.insert(it);else o.insert(it);}

	if(evens + odds/2 >= p){
		odds = odds - max((ll)0,p-evens)*2 ;

		if(odds >= k - p && (odds % 2)== ((k-p) % 2)){
			cout << "YES"<< endl ;

			if(evens >= p){
				for(int i =0;i<p;i++){
					ll top = (*e.begin());
					if(i!=p-1){cout << "1 " << top<<endl;e.erase(top);}
					else{
						if(p == k){
							cout << e.size() + o.size() << " ";
							for(auto it: e)cout << it << " ";
							for(auto it:o)cout << it << " ";
							cout << endl ;
						}
						else{
							cout << e.size() <<" ";
							for(auto it: e)cout << it << " ";
							cout << endl ;
						}
					}
				}
			}
			else{
				for(auto it:e)cout<<"1 "<<it<<endl;
				for(int i=0;i<(p-evens);i++){
					if((p != k) || (p==k && i != (p-evens-1))){
						ll t1 = (*o.begin());o.erase(t1);ll t2 = (*o.begin());o.erase(t2);
						cout << "2 "<<t1 <<" " << t2 << endl ;
					}
					else{
						cout << o.size() << " ";
						for(auto it: o)cout << it << " ";
						cout << endl ;
					}
				}
			}
			for(int i=0;i<k-p;i++){
				ll top = *o.begin();
				if(p == 0 && i == 0){
					if(i == k-p-1){
						cout << n << " ";
						for(auto it: e)cout << it << " ";
						for(auto it: o)cout << it << " ";
						cout << endl ;
					}
					else{
						cout << (e.size() + 1) << " ";
						for(auto it: e)cout << it << " ";
						cout << top << endl ;
						o.erase(top);
					}
				}
				else if(i != k-p-1){cout << "1 "<< top <<endl;o.erase(top);}
				else{
					cout << o.size() << " ";
					for(auto it: o)cout << it << " ";
					cout << endl ;				
				}
			}
		}
		else{
			cout << "NO"<< endl;
		}
	}
	else cout << "NO"<< endl;


}