#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll N,c; cin >> N >> c ;
	ll offset = 1000, curr = 0;
	printf("1 %lld\n", min(N, curr + offset - c));fflush(stdout);
	int status = -1;
	scanf("%d",&status);

	while(status == 0 && curr + offset - c < N){
		curr = curr + offset - c;
		offset--;
		printf("1 %lld\n",min(N, curr + offset - c));fflush(stdout);
		scanf("%d",&status);
	}

	printf("2\n");fflush(stdout);
	if(status == 1){
		for(ll i=curr + 1;i<=min(curr + offset - c, N);i++){
			printf("1 %lld\n",i );fflush(stdout);
			scanf("%d",&status);
			if(status == 1){
				printf("3 %lld\n",i );fflush(stdout);
				break;
			}
		}
	}
}