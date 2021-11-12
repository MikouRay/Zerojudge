 #include <stdio.h>

int main(){
	int i,j,k,p,q,a[4],c[4],x,n;
	while(scanf("%d%d%d%d%d",&c[0],&c[1],&c[2],&c[3],&n)!=EOF){
		int b[n][4],d[n][4];
		for(i=0;i<n;i++)
			scanf("%d%d%d%d",&d[i][0],&d[i][1],&d[i][2],&d[i][3]);
		for(i=0;i<n;i++){
			p=0;
			q=0;
			for(j=0;j<4;j++){
			    a[j]=c[j];
			    b[i][j]=d[i][j];
		    }
			for(j=0;j<4;j++){
				if(a[j] == b[i][j]){
				    p++;
				       a[j] = 15;
				    b[i][j] = 16;
			    }
			}
			for(j=0;j<4;j++){
				x=0;
				for(k=0;k<4;k++){
					if(b[i][j] == a[k])
					x=1;
				}
				if(x == 1)
				q++;
			}
			printf("%dA%dB\n",p,q);
		}
	}
return 0;	
} 
