#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void load_data(double *x, double *y);
void first_iteration(double *u_future, double *u_initial, int n_puntos, double r);
void iteration(double *u_future, double *u_present, double *u_past, int n_puntos, double r);
int N=129;
float c=250;
float L=0.64;
char *name;
double *x_data, *y_data;





int main(void)
{
	x_data=malloc(N*sizeof(double));
	y_data=malloc(N*sizeof(double));

        load_data(x_data,y_data);

	int i;
	for(i=0;i<N;i++)
	{
		printf("%lf",x_data[i]);
                
	}
        printf("hasta aqui funciona\n");
        for(i=0;i<N;i++)
	{
                
                printf("%lf",y_data[i]);
	}

    return 0;
}



void load_data(double *x, double *y)
{
    int i = 0;
    double number;
    FILE *file = fopen("cond_ini_cuerda.dat", "r");

    while(fscanf(file, "%lf\n", &number)==1)
    {
        if(i%2==0)
        {
            x[i/2] = number;
        }
        else
        {
            y[i/2] = number;
        }
        i += 1;
    }
}



void first_iteration(double *u_future, double *u_initial, int n_puntos, double r)
{
	int i;  
	
	for(i=1;i<(n_puntos-1);i++)
	{
		u_future[i] = u_initial[i] + (r*r/2.0)*(u_initial[i+1] - 2.0*u_initial[i] + u_initial[i-1]);
	}

	u_future[0] =0;

}
           
void iteration(double *u_future, double *u_present, double *u_past, int n_puntos, double r)
{
	int i;
        u_future[0] = 0;
        u_future[n_puntos-1] = 0;

	for(i=1;i<(n_puntos-1);i++)
	{
		u_future[i] = (2.0*(1.0-r*r))*u_present[i] - u_past[i] + (r*r)*(u_present[i+1] +  u_present[i-1]);
	}

}
