#include <stdio.h>
#include <string>
int main()
{
	char n[8];
	int m[6],i;
	while(scanf("%s",n)!=EOF)
	{
	for(i=0;i<6;i++)
	{
		m[i]=n[i+1]-n[i];
		if(m[i]<0)
		m[i]=m[i]*(-1);
		printf("%d", m[i]);
	} 
	printf("\n");
    }
	return 0;
}

