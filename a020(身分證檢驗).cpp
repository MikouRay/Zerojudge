#include<stdio.h>
#include<string>
int main()
{
	int o[26] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	char a,m[11];
	int sum,n[10],i;
	while(scanf("%s", m)!=EOF)
	{
		a=m[0];
		n[0]=o[a-'A'];
		for(i=1;i<=9;i++){ 
		n[i]=m[i]-'0';}
		sum=n[0]/10+n[0]%10*9+n[1]*8+n[2]*7+n[3]*6+n[4]*5+n[5]*4+n[6]*3+n[7]*2+n[8]*1+n[9];
		if(sum%10==0)
		printf("real\n");
		else
		printf("fake\n");  
	}
	return 0;
}
