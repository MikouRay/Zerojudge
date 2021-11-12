#include <stdio.h>

int main(void)
{
	int num, x, n, i;
	int sum = 0;
	int average;
	
	while(scanf("%d", &n)!=EOF)
	{
		for(i=1; i<=n; i++){
		scanf("%d", &num);
	    sum += num;	}
	    average = sum/n;
	    x = sum%n;
	    if(average > 59)
	      printf("no\n");
	    else if(average == 59 && x>0)
		  printf("no\n");  
	    else
		  printf("yes\n"); 
		sum = 0;       
	}
	return 0;
}
	
