#include <stdio.h>

int main()
{
	int m, d;
	int s;
	scanf("%d", &m);
	scanf("%d", &d);
	s = (m*2+d)%3;
	
	if (s == 0)
	  printf("´¶³q\n");
	else if (s == 1)
	  printf("¦N\n");
	else if (s == 2)
	  printf("¤j¦N\n");
	      
return 0;
}

