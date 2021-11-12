#include <stdio.h>
int main(void)
{
	int i, n;
	while(scanf("%d", &n)!=EOF){
	  for(i=1; i<n; i++){
		if(i%7!=0)
		  printf("%d ", i); 
	  }
	  printf("\n");
    }
return 0;
}	
