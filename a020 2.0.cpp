#include<stdio.h>
int main(){
	char array[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K','L','M', 'N','P','Q', 'R', 'S', 'T', 'U','V', 'X', 'Y', 'W', 'Z', 'I', 'O'};
	char ID[11];
	while(scanf("%s",ID)!=EOF){
		int a,sum=0;
		for(int i=0;i<26;i++){
			if(ID[0]==array[i]){
				a=i+10;
				break;
			}
		}
		a=(a/10)+(a%10*9);
		for(int i=1;i<=8;i++)
			sum+=(ID[i]-'0')*(9-i);
		//printf("%d\n",a+sum+(ID[9]-'0'));
		if((a+sum+(ID[9]-'0'))%10==0)
			printf("real\n");
		else
			printf("fake\n");
	}
	return 0;
}

