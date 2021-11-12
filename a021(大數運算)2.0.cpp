#include<stdio.h>
#include<string.h>
int A[100],B[100],LA,LB,ans1[1000],L1,ans2[100],L2,ans3[1000],L3,ans4[100],L4;
int compare(int a[100],int la,int b[100],int lb){
	int equal=0;
	if(la>lb)
		return 1;
	if(lb>la)
		return 2;
	else{
		for(int i=0;i<la;i++){
			if(a[i]>b[i])
				return 1;
			else if(b[i]>a[i])
				return 2;
			else
				equal++;
		}
		if(equal==la)
			return 0;
	}	
}

int add(int a[1000],int la,int b[1000],int lb){
	int carry=0,temp,c;
	int i=1;
	while(true){
		if(i<=la && i<=lb){
			temp=a[la-i]+b[lb-i]+carry;
			ans1[i-1]=temp%10;
			carry=0;
			carry=temp/10;
		}
		else if(i>la && i<=lb){
			temp=b[lb-i]+carry;
			ans1[i-1]=temp%10;
			carry=0;
			carry=temp/10;
		}
		else if(i<=la && i>lb){
			temp=a[la-i]+carry;
			ans1[i-1]=temp%10;
			carry=0;
			carry=temp/10;
		}
		else{
			if(carry>0)
				ans1[i-1]=carry;
			else
				i--;
			break;
		}
		i++;
	}
	L1=i;
	for(int i=0;i<L1/2;i++){
		c=ans1[i];
		ans1[i]=ans1[L1-1-i];
		ans1[L1-1-i]=c;
	}
}

int minus(int a[100],int la,int b[100],int lb){
	int i=1,c;
	if(compare(a,la,b,lb)==0){
		ans2[0]=0;
		L2=1;
		return 0;
	}
	while(true){
		if(i<=la&&i<=lb){
			if(a[la-i]>=b[lb-i])
				ans2[i-1]=a[la-i]-b[lb-i];
			else{
				a[la-i-1]--;
				ans2[i-1]=10+a[la-i]-b[lb-i];
			}
		}
		else if(i<=la&&i>lb){
			if(a[la-i]>=0)
				ans2[i-1]=a[la-i];
			else{
				a[la-i-1]--;
				ans2[i-1]=10+a[la-i];
			}
		}
		else{
			i--;
			while(true){
				if(ans2[i-1]==0)
					i--;
				else
					break;
			}
			break;
		}
		i++;
	} 
	L2=i;
	for(int i=0;i<L2/2;i++){
		c=ans2[i];
		ans2[i]=ans2[L2-1-i];
		ans2[L2-1-i]=c;
	}
}

int multi(int a[100],int la,int b[100],int lb){
	int t[100],lt=0,temp,digit=0,carry=0,c;
	ans3[0]=0;
	L3=1;
	for(int i=lb-1;i>=0;i--){
		memset(t,0,sizeof(t));
		lt=0;
		for(int j=0;j<digit;j++){
			t[j]=0;
			lt++;
		}
		digit++;
		for(int j=la-1;j>=0;j--){
			temp=b[i]*a[j]+carry;
			carry=0;
			t[lt]=temp%10;
			lt++;
			carry=temp/10;
		}
		if(carry>0){
			t[lt]=carry;
			lt++;
			carry=0;
		}
		for(int j=0;j<lt/2;j++){
			c=t[j];
			t[j]=t[lt-1-j];
			t[lt-1-j]=c;
		}
		add(ans3,L3,t,lt);
		for(int j=0;j<L1;j++)
			ans3[j]=ans1[j];
		L3=L1;
	}
}

int division(int a[100],int la,int b[100],int lb){
	if(compare(a,la,b,lb)==0){
		ans4[0]=1;
		L4=1;
		return 0;
	}
	else if(compare(a,la,b,lb)==2){
		ans4[0]=0;
		L4=1;
		return 0;
	}
	else{
		int temp[lb],lt,digit=0,next;
		L4=0;
		for(int i=0;i<lb;i++)
			temp[i]=a[i];
		lt=lb;
		next=lb;
		for(int i=0;i<=la-lb;i++){
			digit=0;
			while(compare(temp,lt,b,lb)==0 || compare(temp,lt,b,lb)==1){
				minus(temp,lt,b,lb);
				digit++;
				for(int j=0;j<L2;j++)
					temp[j]=ans2[j];
				lt=L2;
			}
			ans4[i]=digit;
			L4++;
			temp[lt]=a[next];
			lt++;
			next++;
		}
		if(ans4[0]==0){
			for(int i=0;i<L4-1;i++)
				ans4[i]=ans4[i+1];
			L4--;
		}
	}
}

int main(){
	char a[100],b[100],operate;
	while(scanf("%s %c %s",a,&operate,b)!=EOF){
		LA=strlen(a);
		LB=strlen(b);
		for(int i=0;i<LA;i++)
			A[i]=a[i]-'0';
		for(int i=0;i<LB;i++)
			B[i]=b[i]-'0';
		if(operate=='+'){
			add(A,LA,B,LB);
			for(int i=0;i<L1;i++)
				printf("%d",ans1[i]);
		}
		if(operate=='-'){
			if(compare(A,LA,B,LB)==0)
				printf("0");
			else if(compare(A,LA,B,LB)==1){
				minus(A,LA,B,LB);
				for(int i=0;i<L2;i++)
					printf("%d",ans2[i]);
			}
			else if(compare(A,LA,B,LB)==2){
				minus(B,LB,A,LA);
				printf("-");
				for(int i=0;i<L2;i++)
					printf("%d",ans2[i]);
			}
		}
		if(operate=='*'){
			multi(A,LA,B,LB);
			for(int i=0;i<L3;i++)
				printf("%d",ans3[i]);
		}
		if(operate=='/'){
			division(A,LA,B,LB);
			for(int i=0;i<L4;i++)
				printf("%d",ans4[i]);
		}
		printf("\n");
	}	
	return 0;
} 
