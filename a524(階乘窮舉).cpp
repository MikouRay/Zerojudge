#include<stdio.h>

void reverse_exhaust(int a1[],int now,int a2[],int goal){
	if(now == goal){
		for(int i=0;i<goal;i++)
			printf("%d",a1[i]);
		printf("\n");
		return;
	}
	int s[goal],used[goal+1];
	for(int i=0;i<=goal;i++){
		s[i]=a1[i];
		used[i]=a2[i];
	}
	for(int i=goal;i>=1;i--){
		if(used[i]==false){
			s[now]=i;
			used[i]=true;
			reverse_exhaust(s,now+1,used,goal);
			used[i]=false;
		}
	}
}

int main(void){
	int n=0;
	while(scanf("%d",&n)!=EOF){
		int null[n+1]={0};
		reverse_exhaust(null,0,null,n);
	}
} 
