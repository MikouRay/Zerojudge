#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,root1,root2;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		if((b*b-4*a*c)<0)
		printf("No real root");
		if((b*b-4*a*c)==0)
		{
			root1=-b/(2*a);
			printf("Two same roots x=%d", root1);
		}
		if((b*b-4*a*c)>0)
		{
		    root1=(-b+sqrt(b*b-4*a*c))/(2*a);
		    root2=(-b-sqrt(b*b-4*a*c))/(2*a);
		    if(root1>root2)
		    printf("Two different roots x1=%d , x2=%d",root1,root2);
		    else
		    printf("Two different roots x1=%d , x2=%d",root2,root1);
	    }
		printf("\n");
	}
return 0;
}

