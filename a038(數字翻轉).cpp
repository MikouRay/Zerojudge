 #include <stdio.h>

int main(){
	char s[300];
	int n,i,a;
	while(scanf("%s", s)!=EOF){
		for(n=0; s[n]!='\0'; n++);
		for(i=0;i<n/2;i++){
			s[269]=s[i];
			s[i]=s[n-1-i];
			s[n-1-i]=s[269];
		}
		a = 0;
		for(i=0;i<n;i++){
			if(s[i]!='0' && a == 0){
				printf("%c",s[i]);
				a = 1;	
			}
			else if(a == 1)
			    printf("%c",s[i]);
		}
		if(a == 0)
		    printf("0");
		printf("\n");    
	}
return 0;	
}
