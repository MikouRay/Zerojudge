#include<stdio.h>
#include<string>
int main()
{
	int o[26] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	char m[10],c;
	int n[9],sum1,sum2,i;
	while(scanf("%s",m)!=EOF)
	{
		for(i=0;i<9;i++){
		n[i]=m[i]-'0'; }
		sum1=n[0]*8+n[1]*7+n[2]*6+n[3]*5+n[4]*4+n[5]*3+n[6]*2+n[7]*1+n[8];
		for(i=0;i<26;i++)
		{
			sum2=o[i]/10+o[i]%10*9+sum1;
			if(sum2%10==0)
			printf("%c", i+'A');
		}
		printf("\n");	
	}
	return 0;
}
