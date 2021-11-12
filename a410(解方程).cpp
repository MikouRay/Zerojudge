#include<stdio.h>

int main(){
	double a1,b1,c1,a2,b2,c2,d,dx,dy;
	while(scanf("%lf%lf%lf%lf%lf%lf",&a1,&b1,&c1,&a2,&b2,&c2)!=EOF){
		d=a1*b2-a2*b1;
		dx=c1*b2-c2*b1;
		dy=a1*c2-a2*c1;
		if(d!=0)
		printf("x=%.2lf\ny=%.2lf\n",dx/d,dy/d);
		else if(dx*dx+dy*dy==0)
		    printf("Too many");
		else
		    printf("No answer");
	}
return 0;	
}
