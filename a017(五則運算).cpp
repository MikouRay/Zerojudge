#include<stdio.h>
#include<string.h>
int operate(char S[100]) {
	//printf("%s\n",S);
	bool no_bra=true;
	if(S[0]=='(' && S[strlen(S)-1]==')') {
		int left=0,right=0;
		for(int i=1; i<strlen(S)-1; i++) {
			if(S[i]=='(')
				left++;
			else if(S[i]==')')
				right++;
			if(left==0 && right==1) {
				no_bra=false;
				break;
			}
		}
	}
	if(S[0]=='(' && S[strlen(S)-1]==')' && no_bra==true) {
		char s[100];
		memset(s,'\0',sizeof(s));
		for(int i=0; i<strlen(S)-2; i++)
			s[i]=S[i+1];
		//printf("%s\n",s);
		return(operate(s));
	} else {
		bool skip=false,plus=true,multi=false,trans=false;
		int left=0;
		for(int i=0; i<=strlen(S); i++) {
			if (S[i]=='(') {
				left++;
				//skip=true;
			} else if (S[i]==')') {
				left--;
				//if(i==strlen(S)-1)
				//	i=0;
				//continue;
			}
			if(left>0)
				skip=true;
			else if(left==0)
				skip=false;
			if(skip==false && plus==true) {
				if(S[i]=='+' || S[i]=='-') {
					char s1[100],s2[100];
					memset(s1,'\0',sizeof(s1));
					memset(s2,'\0',sizeof(s2));
					for(int j=0; j<i; j++)
						s1[j]=S[j];
					//printf("%s\n",s1);
					for(int j=i+1; j<strlen(S); j++)
						s2[j-(i+1)]=S[j];
					//printf("%s\n",s2);
					if(S[i]=='+')
						return(operate(s1)+operate(s2));
					else
						return(operate(s1)-operate(s2));
				}
			}
			if(plus==true && i==strlen(S)-1) {
				plus=false;
				multi=true;
				i=-1;
				continue;
			}
			if(skip==false && multi==true) {
				if(S[i]=='*' || S[i]=='/' || S[i]=='%') {
					char s1[100],s2[100];
					memset(s1,'\0',sizeof(s1));
					memset(s2,'\0',sizeof(s2));
					for(int j=0; j<i; j++)
						s1[j]=S[j];
					//printf("%s\n",s1);
					for(int j=i+1; j<strlen(S); j++)
						s2[j-(i+1)]=S[j];
					//printf("%s\n",s2);
					if(S[i]=='*')
						return(operate(s1)*operate(s2));
					if(S[i]=='/')
						return(operate(s1)/operate(s2));
					else
						return(operate(s1)%operate(s2));
				}
			}
			if(multi==true && i==strlen(S)-1) {
				multi=false;
				trans=true;
				//i=-1;
				//continue;
			}
			if(trans==true) {
				int sum=0,num=1;
				for(int j=strlen(S)-1; j>=0; j--) {
					sum+=num*(S[j]-'0');
					num*=10;
				}
				//printf("%d\n",sum);
				return(sum);
			}
		}
	}
}

int main() {
	char get[100],operation[100],temp;
	while(scanf("%[^\n]",get)!=EOF) {
		temp=getchar();
		int count=0;
		for(int i=0; i<strlen(get); i++) {
			if(get[i]!=' ') {
				operation[count]=get[i];
				count++;
			}
		}
		printf("%d\n",operate(operation));
		memset(get,'\0',sizeof(get));
		memset(operation,'\0',sizeof(operation));
	}
	return 0;
}
