#include <stdio.h>

int hn(int k,char a,char b,char c)
{
	if(k==1)
	    printf("Move ring %d from %c to %c\n",k,a,c);
	else
	{
		hn(k-1,a,c,b);
		printf("Move ring %d from %c to %c\n",k,a,c);
		hn(k-1,b,a,c);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	hn(n,'A','B','C');
	return 0;
}
