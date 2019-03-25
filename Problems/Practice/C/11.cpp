#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	string str;cin>> str;
	map<int,vector<int>>location;
	for(int i=0;i<str.length();i++)location[(int)(str[i]-'0')].push_back(i) ;
	if(location.find(0) != location.end()){
		cout << "YES\n"<<0<<endl;
	}
	else if(location.find(8) != location.end()){
		cout << "YES\n"<<8<<endl;
	}
	else{
		int flag = 0;
		for(int i=16;i<1000;i+=8)
		{
			string s = to_string(i);
			int loc ;
			int notfound = 0 ;
			// cout << s<<" ";
			for(int j=0;j<s.length();j++){
				int num = (int)(s[j]-'0') ;
				if(location.find(num) == location.end()){notfound=1;break;}
				if(j == 0){
					loc = location[num][0];
					// cout << loc<<" " ;
				}
				else{					
					// cout << loc <<" " ;
					vector<int> v = location[num];
					auto it = upper_bound(v.begin(),v.end(),loc) ;
					if(it == v.end()){notfound=1;break ;}
					else  loc = *it;
				}
			}
			// cout << endl;
			if(notfound == 0){
				flag = 1 ;
				cout << "YES\n"<<i<<endl ;
				break ;
			}
		}
		if(flag == 0)cout << "NO"<<endl; 
	}
	return 0;
}