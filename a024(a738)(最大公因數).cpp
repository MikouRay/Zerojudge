#include <stdio.h>

int main()
{
	int a,b,r;
	while(scanf("%d %d", &a, &b)!=EOF)
	{
		while((r=a%b)!=0)
		{
			a=b;
			b=r;	
		}
		printf("%d\n", b);
	}
return 0;
}

