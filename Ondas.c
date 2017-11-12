#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* declaracion constantes */

int N=129;
float c=250;
float L=0.64;
char *name;
double *x_data, *y_data;
float delta_t =1/129;
float delta_x =0.005;
double rc;

/* declaracion funciones */

void load_data(double *x, double *y);
void first_iteration(double *u_future, double *u_initial, int n_puntos, double r);
void iteration(double *u_future, double *u_present, double *u_past, int n_puntos, double r);


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
        
        for(i=0;i<N;i++)
	{
                
                printf("%lf",y_data[i]);
	}
	printf("hasta aqui funciona\n");
	

        double *x0, *y0, *u_in, *u_fut, *u_past, *u_present;
        rc = 0.0049;
        x0=malloc(N*sizeof(double));
	y0=malloc(N*sizeof(double));

        load_data(x0,y0);

        u_in=y0;
        u_fut=malloc(N*sizeof(double));

	first_iteration(u_fut, u_in, N, rc);
        
        	u_past=u_in;
        	u_present=u_fut;

        int j;

        for(i=1;i<N-1;i++)
	{
                u_fut[0]=0;
		iteration(u_fut, u_present, u_past, N, rc);
        	u_present=u_fut;
 		for(j=0;i<N;i++)
		{
			printf("%lf",u_present[j]);
		}       
	}
	return 0;
}


void condInic(void)
{
	double *x0, *y0, *u_in, *u_fut, *u_past, *u_present;
        rc = c*(delta_x/delta_t);
        x0=malloc(N*sizeof(double));
	y0=malloc(N*sizeof(double));

        load_data(x0,y0);

        u_in=y0;
        u_fut=malloc(N*sizeof(double));
        
        first_iteration(u_fut, u_in, N, rc);
        
        u_past=u_in;
        u_present=u_fut;
        
        iteration(u_fut, u_present, u_past, N, rc);
        u_present=u_fut;
        
        int i;
	for(i=0;i<N;i++)
	{
		printf("%lf",u_present[i]);
	}

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
