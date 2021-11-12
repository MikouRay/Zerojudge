#include <stdio.h>
int main(void)
{
	int n,d[1000],i;
	int a = 0;
	int b,c = 0;
	
	while(scanf("%d", &n)!=EOF)
	{
	for(i=0; i<n; i++){
	    scanf("%d", &d[i]);
    }
    for(i=0; i<n; i++){
    	if(d[i]%3==0)
    	  a++;
    	else if(d[i]%3==1)
		  b++;
		else if(d[i]%3==2)
		  c++;    
	}
    printf("%d %d %d\n", a, b, c);
    }
		
	return 0;
}
