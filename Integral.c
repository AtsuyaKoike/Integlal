#include <stdio.h>
#include <math.h>

#define denominator 4.0

double f(double);
double fi(double);
double fourth_power(double);
double cubed(double);

int main(void)
{
	double n, a, b, x0, y0, x1, y1, x2, y2, dx, R;
	double S=0, T=0, K=0;
	int i;
	FILE *fp;
    
	fp = fopen("cal.txt", "wt");
	printf("a="); scanf("%lf",&a);
	printf("b="); scanf("%lf",&b);
	
	R = fi(b) - fi(a);

	dx = 0.01;
	n = ( b - a ) / dx;
	for( i = 0; i < n; i++ )//�敪���ϖ@
	{
		x0 = a + ( i * dx );
		y0 = f( x0 );
		K = K + y0 * dx;
    	}
	for( i = 0; i < n; i++ )//��`�@
	{
		x0 = a + i * dx;
		y0 = f( x0 );
		x1 = a + ( i + 1 ) * dx;
		y1 = f( x1 );
		T = T + ( y0 + y1 ) / 2.0 * dx;
	}
	n = ( b - a ) / dx / 2.0;
	for(i=1; i<n+1; i++)//�V���v�\��
	{
		x0 = a+  ( 2 * i - 2 ) * dx;
		y0 = f(x0);
		y1 = f(x1);
		x2 = a + ( 2 * i ) * dx;
		y2 = f( x2 );
		S = S + dx/3.0 * ( y0 + 4.0 * y1 + y2 );
	}
	printf(" �^�l      =%14.10f\n",R);
	printf(" �敪���ϖ@=%14.10f\n",K);
	printf(" ��`�@    =%14.10f\n",T);
	printf(" �V���v�\��=%14.10f\n",S);
	
	fprintf(fp, "a= %f\n",a);
	fprintf(fp, "b= %f\n",b);
	fprintf(fp, "�^�l        =%14.10f\n",R);
	fprintf(fp, "�敪���ϖ@  =%14.10f\n",K);
	fprintf(fp, "��`�@      =%14.10f\n",T);
	fprintf(fp, "�V���v�\��  =%14.10f\n",S);
	fclose(fp);
	
	return 0;    
}

double fourth_power(double x)
{
	return x*x*x*x;
}

double cubed(double x)
{
	return x*x*x;
}

double f(double x)
{
	return cubed(x);
}

double fi(double x)
{
	return ( 1/denominator ) * fourth_power(x);
}