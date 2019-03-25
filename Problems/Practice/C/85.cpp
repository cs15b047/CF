#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll n,k,x;scanf("%lld%lld%lld",&n,&k,&x);
	ll cnt0[1025]={},cnt1[1025]={};
	for(int i=0;i<n;i++){
		ll num;scanf("%lld",&num);
		cnt0[num]++;
	}
	
	for (int i = 0; i < k; ++i)
	{
		ll done_till_now = 0;
		if(i%2==0){
			for (int j = 0; j <= 1024; ++j)cnt1[j]=0;
			for (int j = 0; j <= 1024; ++j)
			{
				if(cnt0[j]==0)continue;
				if(done_till_now % 2 == 0){
					cnt1[j] += cnt0[j] - (cnt0[j]+1)/2;
					cnt1[j^x] += (cnt0[j]+1)/2;
				}
				else{
					cnt1[j^x] += cnt0[j]/2;	
					cnt1[j] += cnt0[j] - (cnt0[j]/2);	
				}
				done_till_now+= cnt0[j];
			}
		}
		else{
			for (int j = 0; j <= 1024; ++j)cnt0[j]=0;
			for (int j = 0; j <= 1024; ++j)
			{
				if(cnt1[j]==0)continue;
				if(done_till_now % 2 == 0){
					cnt0[j] += cnt1[j] -(cnt1[j]+1)/2;
					cnt0[j^x] += (cnt1[j]+1)/2;
				}
				else{
					cnt0[j^x] += cnt1[j]/2;	
					cnt0[j] += cnt1[j] - (cnt1[j]/2);	
				}
				done_till_now+= cnt1[j];
			}
		}
	}
	if(k%2==0){
		for(int i=1024;i>=0;i--){
			if(cnt0[i] != 0){
				printf("%d ",i );
				break;
			}
		}
		for(int i=0;i<=1024;i++){
			if(cnt0[i] != 0){
				printf("%d",i );
				break;
			}
		}
	}
	else{
		for(int i=1024;i>=0;i--){
			if(cnt1[i] != 0){
				printf("%d ",i );
				break;
			}
		}
		for(int i=0;i<=1024;i++){
			if(cnt1[i] != 0){
				printf("%d",i );
				break;
			}
		}
	}
}