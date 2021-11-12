#include<stdio.h>
#include<string.h>
int main(){
	char s[1000];
	while(scanf("%s",s)!=EOF){
		char c[26];
		int count=0;
		memset(c,0,sizeof(c));
		for(int i=0;i<strlen(s);i++){
			if(s[i]>='a' && s[i]<='z')
				c[s[i]-'a']++;
			else if(s[i]>='A' && s[i]<='Z')
				c[s[i]-'A']++;
		}
		for(int i=0;i<26;i++){
			if(c[i]%2==1)
				count++;
			if(count>1){
				printf("no...\n");
				break;
			}
		}
		if(count<=1)
			printf("yes !\n");
	}
	return 0;
}
