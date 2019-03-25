#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n,k;cin>>n>>k ;

	if(n <= 2*k + 1){
		cout << "1\n" << (n/2 + (n %2 == 1)) <<endl ;
	}
	else{
		vector<int> answer ;
		int rem = n % (2*k+1);
		if(rem == 0){
			int curr = k ;
			while(curr + k < n){
				answer.push_back(curr);
				curr += (2*k + 1) ;	
			}			
		}
		else if(rem >= k + 1 && rem <= 2*k){
			int curr = rem-(k+1) ;
			answer.push_back(curr);
			curr = rem + k ;
			while(curr + k < n){
				answer.push_back(curr);
				curr += (2*k + 1) ;
			}
		}
		else{
			rem += 2*k + 1  ;
			int strt = rem - 2*(k+1) ;
			answer.push_back(strt);
			int curr = strt + 2*k + 1  ;
			while(curr< n){
				answer.push_back(curr);
				curr += (2*k+1) ;
			}
		}
		cout <<answer.size()<<endl;
		for(int i=0;i<answer.size();i++)cout << answer[i]+1 <<" ";
	}

	
	return 0;
}