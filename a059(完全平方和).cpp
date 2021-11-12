#include<stdio.h>
int main()
{
	int T,a,b,i,j,k,sum,n[1000],m[100];
	while(scanf("%d", &T)!=EOF)
	{
		for(i=1;i<=T;i++)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			for(j=a;j<=b;j++){
				n[j]=0; } 
			for(j=a;j<=b;j++)
			{
				for(k=1;k*k<=j;k++)
				{
					if(j==k*k)
					n[j]=j;
				}
			}
			m[i]=0;
			for(j=a;j<=b;j++){
			m[i]+=n[j]; }
		}
		for(i=1;i<=T;i++)
		    printf("Case %d: %d\n",i,m[i]);
	} 
	return 0;
}
