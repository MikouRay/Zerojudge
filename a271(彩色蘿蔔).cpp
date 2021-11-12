#include<stdio.h>
#include<string.h>
int main(){
	int time;
	while(scanf("%d",&time)!=EOF){
		for(int i=0;i<time;i++){
			int x=0,y=0,z=0,w=0,n=0,m=0,poison=0,num=0;
			char in[1000],radish[1000],temp;
			in[0]='\0';
			memset(radish,'\0',sizeof(radish));
			scanf("%d%d%d%d%d%d",&x,&y,&z,&w,&n,&m);
			temp = getchar();
			//gets(in);
			scanf("%[^\n]",in);
			temp = getchar();
			if(in[0]=='\0'){
				printf("%dg\n",m);
				continue;			
			}
			for(int j=0;j<strlen(in);j++){
				if(in[j]!=' '){
					radish[num]=in[j];
					num++;
				}
			}
			for(int j=0;j<num;j++){
				m-=poison;
				if(m<=0){
					printf("bye~Rabbit\n");
					break;
				}	
				if(radish[j]=='0')
					continue;
				else if(radish[j]=='1')
					m+=x;
				else if(radish[j]=='2')
					m+=y;
				else if(radish[j]=='3')
					m-=z;
				else{
					m-=w;
					poison+=n;
				}
				if(m<=0){
					printf("bye~Rabbit\n");
					break;
				}
			}
			if(m>0)
				printf("%dg\n",m);
		}
	}
	return 0;
} 
