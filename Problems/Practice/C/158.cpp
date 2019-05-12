// D. Longest k-Good Segment  CF #Edu 5
// Use 2 pointers--> for a given start location, calculate end of reqd segment
//Use a window of unique elements to update end ptr when start ptr advances by 1
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,k; scanf("%lld%lld",&n,&k);
	vector<ll> arr(n);for(int i=0;i<n;i++)scanf("%lld",&arr[i]);

	vector<ll> answer(n, 0);
	map<ll,ll> ele_cnt;ele_cnt.clear();

	ll strt = 0, curr = 0;

	while(strt < n){
		while(curr < n && ((ele_cnt.size() < k) || ((ele_cnt.size() == k) && (ele_cnt.find(arr[curr]) != ele_cnt.end())) ) ) ele_cnt[arr[curr++]]++;
		answer[strt] = curr - strt ;
		ele_cnt[arr[strt]]--;
		if(ele_cnt[arr[strt]] == 0)ele_cnt.erase(arr[strt]);
		strt++;
	}
	ll len=0,l;
	for(int i=0;i<n;i++){
		if(answer[i] > len){
			len = answer[i]; l = i;
		}
	}
	printf("%lld %lld\n",l + 1, l + 1 + len - 1 );
}