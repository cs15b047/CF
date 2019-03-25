#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll n;scanf("%lld",&n);
	vector<ll>a(n); for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	map<ll,ll> ele_cnt;for(int i=0;i<n;i++)ele_cnt[a[i]]++;
	map<ll,set<ll>> cnt_ele;for(auto it:ele_cnt)cnt_ele[it.second].insert(it.first);

	ll ans = 0;
	vector<vector<ll>>answer;answer.clear();
	while(1){
		int flag=1;

		ll cnt1,ele1;ll cnt2,cnt3,ele2,ele3;
		if(cnt_ele.empty())flag=0;
		else{
			cnt1 = cnt_ele.rbegin()->first;ele1 =*(cnt_ele[cnt1].begin());
			cnt_ele[cnt1].erase(ele1);
			if(cnt_ele[cnt1].empty())cnt_ele.erase(cnt1);
		}

		if(cnt_ele.empty())flag =0;
		else{
			cnt2 = cnt_ele.rbegin()->first; ele2=-1;
			auto it = cnt_ele.rbegin();ele2 = *(it->second.begin());
			cnt_ele[cnt2].erase(ele2);
			if(cnt_ele[cnt2].empty())cnt_ele.erase(cnt2);
		}

		if(cnt_ele.empty())flag =0;
		else{
			cnt3 = cnt_ele.rbegin()->first; ele3=-1;
			auto it = cnt_ele.rbegin();ele3 = *(it->second.begin());
			cnt_ele[cnt3].erase(ele3);
			if(cnt_ele[cnt3].empty())cnt_ele.erase(cnt3);
		}

		if(flag != 0){
			if(cnt1 > 1)cnt_ele[cnt1-1].insert(ele1);
			if(cnt2 > 1)cnt_ele[cnt2-1].insert(ele2);
			if(cnt3 > 1)cnt_ele[cnt3-1].insert(ele3);
			ans++;
			vector<ll>nums(3);nums[0]=ele1;nums[1]=ele2;nums[2]=ele3;
			sort(nums.begin(),nums.end(),greater<ll>());
			answer.push_back(nums);
		}
		else break;
	}
	printf("%lld\n",ans );
	for(auto nums:answer){
		printf("%lld %lld %lld\n",nums[0],nums[1],nums[2] );
	}

}