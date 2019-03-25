#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	int n;scanf("%d",&n);
	char str[10];
	vector<bool>color(31);
	for(int i=1;i<=n;i++){
		printf("%d 0\n",i );
		fflush(stdout);
		scanf("%s",str);
		if(strcmp(str,"black")==0)color[i] =0;
		else color[i] = 1;
	}
	bool flag=0;
	for (int x = 1; x <= n-1; ++x)
	{
		if(color[x] != color[x+1]){
			printf("%d 1 %d 3\n",x+1, x+2 );
			flag= 1;break;
		}	
	}
	if(!flag){
		printf("31 0 31 1\n");
	}
	fflush(stdout);
}