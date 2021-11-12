#include<stdio.h>
#include<string.h>
int I;
int transfer(char Str[100],char one,char five,char ten,int digit){
	char str[4];
	int count=0,i=0;
	while(Str[I]==one||Str[I]==five||Str[I]==ten){
		str[i]=Str[I];
		i++;
		I++;
	}
	switch(i){
		case 0:
							 return 0;
			//break;
		case 1:
			if(str[0]==one)  return 1*digit;
			if(str[0]==five) return 5*digit;
			//break;
		case 2:
			if(str[0]==five) return 6*digit;
			else{
			if(str[1]==one)  return 2*digit;
			if(str[1]==five) return 4*digit;
			if(str[1]==ten)  return 9*digit;
			}
			//break;
		case 3:
			if(str[0]==one)  return 3*digit;
			if(str[0]==five) return 7*digit;
			//break;
		case 4:
			                 return 8*digit;
			//break;			
	}
}

int roman2num(char STR[100]){
	int NUM=0;
	I=0;
	char str[4];
	while(STR[I]=='M'){
		NUM+=1000;
		I++;
	}
	NUM+=transfer(STR,'C','D','M',100);
	NUM+=transfer(STR,'X','L','C',10);
	NUM+=transfer(STR,'I','V','X',1);
	return NUM;
}

int transfer2(char one,char five,char ten,int num){
	switch(num){
		case 0:
			break;
		case 1:
			printf("%c",one);
			break;
		case 2:
			printf("%c%c",one,one);
			break;
		case 3:
			printf("%c%c%c",one,one,one);
			break;
		case 4:
			printf("%c%c",one,five);
			break;
		case 5:
			printf("%c",five);
			break;
		case 6:
			printf("%c%c",five,one);
			break;
		case 7:
			printf("%c%c%c",five,one,one);
			break;
		case 8:
			printf("%c%c%c%c",five,one,one,one);
			break;
		case 9:
			printf("%c%c",one,ten);
			break;
	}
}

int num2roman(int NUM){
	for(int i=0;i<NUM/1000;i++)
		printf("M");
	NUM%=1000;
	transfer2('C','D','M',NUM/100);
	NUM%=100;
	transfer2('X','L','C',NUM/10);
	NUM%=10;
	transfer2('I','V','X',NUM);
	printf("\n");
}

int main(){
	char a[100],b[100];
	while(scanf("%s",a)!=EOF){
		if(a[0]=='#')
			break;
		else
			scanf("%s",b);
		if(roman2num(a)>roman2num(b))
			num2roman(roman2num(a)-roman2num(b));
		else if(roman2num(a)<roman2num(b))
			num2roman(roman2num(b)-roman2num(a));
		else
			printf("ZERO\n");	
	}
	return 0;
} 
