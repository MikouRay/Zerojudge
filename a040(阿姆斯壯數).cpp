#include <stdio.h>

int main()
{
	int n,m,x,y,q[8],r[8],N;
	int i,a,b;
	int sum,c;
	int j,k,l,s;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		N=0;//�P�_�n���n���none 
		for(i=n;i<=m;i++)
		{
			a = i;
			c = 0;
			while(a!=0)
			{//�P�_�X���(c) 
				a/=10;
				c++;
			}
			b = i;
			for(j=1;j<=c;j++)
			{//�N�C��Ʃ�}�s�i�}�Cq[] 
				x=b/10;
				y=b%10;
				b=x;
				q[j]=y;
			}
			for(k=1;k<=c;k++)
			{//�N�}�Cq[]�̪��C�Ӽ�c���� 
				r[k]=1;
				for(l=1;l<=c;l++)
				r[k]=r[k]*q[k];
			}
			sum=0;
			for(s=1;s<=c;s++){//�[�` 
			    sum += r[s]; }
			if(sum==i) 
			{
			    printf("%d ",sum);
			    N++;//n����0 
		    }	   
		}
		if(N==0){
		    printf("none"); }
		printf("\n");
	}
return 0;
}

