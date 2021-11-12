#include <stdio.h>
int main(void)
{
	long long n, a, b, c, sum, i;
	
	scanf("%ld", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%ld %ld %ld", &a, &b, &c);
		if (a == 1){
	      sum = b+c;
	      printf("%ld\n", sum);
	    }
	    else if (a == 2){
	    	sum = b-c;
	    	printf("%ld\n", sum);
		}
		else if (a == 3){
	    	sum = b*c;
	    	printf("%ld\n", sum);
	    }
	    else if (a == 4){
	    	sum = b/c;
	    	printf("%ld\n", sum);
	    }  
	}
	
return 0;
}

