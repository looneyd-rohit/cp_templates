/*Curve-Fitting Method*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"q1.h"

int fact(int x);
void arr_cpy(float *a, float *b, int n);
float* li_po_cfit(float *x, float *y, int n, int deg);
void trig_curve_fit(float* x, float *y, int n, float w);
void error_li_po(float* x_temp, float* y_temp, int n, float* res, int deg);
void error_exp(float* x_temp, float* y_temp, int n, float* res, int deg);

void main()
{
    int i, n, ch, deg, c=0;
    float *res, w;
    char resp;
    
    float *x = (float*)calloc(1,sizeof(float));
    float *x_temp = (float*)calloc(1,sizeof(float));
    float *y = (float*)calloc(1,sizeof(float));
    float *y_temp = (float*)calloc(1,sizeof(float));

    do{
    if(c)
    {
        printf("Do you want to continue with previously entered values ? Type Y/y : ");
        scanf(" %c",&resp);
        if(resp=='y' || resp=='Y')
        goto nreq;
        else
        goto req;
    }
    else
    {
    req : ; 
    printf("\n\n\t\t\t\tCURVE_FITTING\n\n");
    printf("Enter the number of data points = ");
    scanf(" %d",&n);
    x = realloc(x,n);
    x_temp = realloc(x_temp,n);
    y = realloc(y,n);
    y_temp = realloc(y_temp,n);
    printf("\nEnter the value of x :\n");
    for(i=0 ; i<n ;i++)
    scanf(" %f",(x+i));
    printf("\nEnter the value of y :\n");
    fflush(stdin);
    for(i=0 ; i<n ;i++)
    scanf(" %f",(y+i));
    }
    nreq: ;
    printf("CHOOSE your option :\n1. Linear -or- Polynomial Regression\n2. Exponential\n3. Saturation-Growth Rate\n4. Trigonometric\n5. Power\n6.ALL AT ONCE\n\n");
    scanf(" %d",&ch);
    switch(ch)
    {
        case 1 : printf("\nLINEAR/POLYNOMIAL Curve Fitting\n");
                 printf("Enter the degree of the polynomial you want in your result = ");
                 scanf(" %d",&deg);
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 res=li_po_cfit(x_temp,y_temp,n,deg);
                 /*Printing Output*/
                 printf("\n\n");
                 printf("The function in degree = %d is :\n",deg);
                 printf("\t\tY = ");
                 for(i=0 ; i<deg+1 ; i++)
                 {
                    if(*(res+i)>=0)
                    printf("+ %.2f(x^%d)\t",*(res+i),i);
                    else
                    printf("- %.2f(x^%d)\t",(-1)**(res+i),i);
                 }
                 printf("\n\n");
                 break;
        case 2 : printf("\nEXPONENTIAL Curve Fitting\n");
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 for(i=0 ; i<n ; i++){
                     if(*(y_temp+i)!=0)
                 *(y_temp+i) = log(*(y_temp+i));
                 else {
                     printf("log(0) gives undefined behaviour\n\n");
                     goto xy;
                 }
                 }
                 res=li_po_cfit(x_temp,y_temp,n,1);
                 /*Printing Output*/
                 printf("\n\n");
                 printf("The function in exponential form is :\n");
                 printf("\t\tY = ");
                 if(*res>=0)
                 printf("e^((%.2f)x + (%.2f))",*(res+1),*(res));
                 else
                 printf("e^((%.2f)x - (%.2f))",*(res+1),(-1)**(res));
                 printf("\n\n");
                 xy : ;
                 break;
        case 3 : printf("\nSATURATION-GROWTH Curve Fitting\n");
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 for(i=0 ; i<n ; i++)
                 {
                    if(*(y_temp+i) != 0  &&  *(x_temp+i) != 0)
                    {
                        *(x_temp+i) = 1/(*(x_temp+i));
                        *(y_temp+i) = 1/(*(y_temp+i));
                    }
                    else
                    {
                        printf("\nCANNOT divide by zero!!!\n");
                        goto ret;
                    }
                 }
                 res=li_po_cfit(x_temp,y_temp,n,1);
                 /*Printing Output*/
                 printf("\n\n");
                 printf("The Saturation-Growth curve form is :\n");
                 printf("\t\tY = ");
                 printf("(%f) * ((x)  /  ((%f) + (x)))\n\n",1/res[0],res[1]/res[0]);
                 ret : ;
                 break;
        case 4 : printf("\nTRIGONOMETRIC Curve Fitting\n");
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 printf("Enter the know w(omega) = ");
                 scanf(" %f",&w);
                 printf("The trigonometric form of the curve is : \n");
                 trig_curve_fit(x_temp,y_temp,n,w);
                 printf("\n\n");
                 break;
        case 5 : printf("\nPOWER-Curve Fitting\n");
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 for(i=0 ; i<n ; i++)
                 {
                    if(*(x_temp+i)!=0 && *(y_temp+i)!=0)
                    {*(x_temp+i) = log(*(x_temp+i));
                    *(y_temp+i) = log(*(y_temp+i));}
                    else 
                    {
                        printf("log(0) is not defined\n\n");
                        goto ret ;
                    }
                 }
                 res=li_po_cfit(x_temp,y_temp,n,1);
                  /*Printing Output*/
                 printf("\n\n");
                 printf("The function in exponential form is :\n");
                 printf("\t\tY = ");
                 printf("e^(%f) * (x^(%f))",res[0]/res[1],res[1]);
                 printf("\n\n");
                 break;
        case 6 : printf("\nLINEAR/POLYNOMIAL Curve Fitting\n");
                 printf("Enter the degree of the polynomial you want in your result = ");
                 scanf(" %d",&deg);
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 res=li_po_cfit(x_temp,y_temp,n,deg);
                 /*Printing Output*/
                 printf("\n\n");
                 printf("The function in degree = %d is :\n",deg);
                 printf("\t\tY = ");
                 for(i=0 ; i<deg+1 ; i++)
                 {
                    if(*(res+i)>=0)
                    printf("+ %.2f(x^%d)\t",*(res+i),i);
                    else
                    printf("- %.2f(x^%d)\t",(-1)**(res+i),i);
                 }
                 error_li_po(x_temp,y_temp,n,res,deg);
                 printf("\n\n");
                 printf("\nEXPONENTIAL Curve Fitting\n");
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 for(i=0 ; i<n ; i++){
                     if(*(y_temp+i)!=0)
                 *(y_temp+i) = log(*(y_temp+i));
                 else {
                     printf("log(0) gives undefined behaviour\n\n");
                     goto xy_;
                 }
                 }
                 res=li_po_cfit(x_temp,y_temp,n,1);
                 /*Printing Output*/
                 printf("\n\n");
                 printf("The function in exponential form is :\n");
                 printf("\t\tY = ");
                 if(*res>=0)
                 printf("e^((%.2f)x + (%.2f))",*(res+1),*(res));
                 else
                 printf("e^((%.2f)x - (%.2f))",*(res+1),(-1)**(res));
                 error_exp(x_temp,y_temp,n,res,1);
                 printf("\n\n");
                 xy_ : ;
                 printf("\nSATURATION-GROWTH Curve Fitting\n");
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 for(i=0 ; i<n ; i++)
                 {
                    if(*(y_temp+i) != 0  &&  *(x_temp+i) != 0)
                    {
                        *(x_temp+i) = 1/(*(x_temp+i));
                        *(y_temp+i) = 1/(*(y_temp+i));
                    }
                    else
                    {
                        printf("\nCANNOT divide by zero!!!\n");
                        goto ret_;
                    }
                 }
                 res=li_po_cfit(x_temp,y_temp,n,1);
                 /*Printing Output*/
                 printf("\n\n");
                 printf("The Saturation-Growth curve form is :\n");
                 printf("\t\tY = ");
                 printf("(%f) * ((x)  /  ((%f) + (x)))\n\n",1/res[0],res[1]/res[0]);
                 ret_ : ;
                 printf("\nTRIGONOMETRIC Curve Fitting\n");
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 printf("Enter the know w(omega) = ");
                 scanf(" %f",&w);
                 printf("The trigonometric form of the curve is : \n");
                 trig_curve_fit(x_temp,y_temp,n,w);
                 printf("\n\n");
                 printf("\nPOWER-Curve Fitting\n");
                 arr_cpy(x,x_temp,n);
                 arr_cpy(y,y_temp,n);
                 for(i=0 ; i<n ; i++)
                 {
                    if(*(x_temp+i)!=0 && *(y_temp+i)!=0)
                    {*(x_temp+i) = log(*(x_temp+i));
                    *(y_temp+i) = log(*(y_temp+i));}
                    else 
                    {
                        printf("log(0) is not defined\n\n");
                        goto ret_2 ;
                    }
                 }
                 res=li_po_cfit(x_temp,y_temp,n,1);
                  /*Printing Output*/
                 printf("\n\n");
                 printf("The function in exponential form is :\n");
                 printf("\t\tY = ");
                 printf("e^(%f) * (x^(%f))",res[0]/res[1],res[1]);
                 printf("\n\n");
                 ret_2 : ;
                 break;
        default : printf("\nThhe entered option does not exist\n");
    }
    printf("To continue further Type Y/y and press enter : ");
    scanf(" %c",&resp);
    c++;
    }while(resp=='y'  || resp=='Y');

}

int fact(int x)
{
    if(x==0)
    return 1 ;
    else
    x = x * fact(x-1);
    return x;
}

void arr_cpy(float *a, float *b, int n)
{
    // float *b = (float*)calloc(n,sizeof(float));
    for(int i=0 ; i<n ; i++)
    *(b+i) = *(a+i);

    // return b;
}

float* li_po_cfit(float *x, float *y, int n, int deg)
{
    int i,j,k;
    
    /*Allocating memory space for coefficients*/
    float *s_x = (float*)calloc(2*deg+1,sizeof(float));
    float *s_y = (float*)calloc(deg+1,sizeof(float));
    float sum;
    
    /*Allocating memory space for matrix of order (deg) * (deg+1)*/
    float **a_m = (float**)calloc(deg+1,sizeof(float*));
    for(i=0 ; i<deg+1 ; i++)
    *(a_m+i) = (float*)calloc(deg+2,sizeof(float));

    /*Evaluating coefficients*/
    for(i=0 ; i<=2*deg ; i++)
    {
        sum=0;
        for(j=0 ; j<n ; j++)
        sum = sum + pow(*(x+j),i);
        *(s_x+i)=sum;
    }
    // for(i=0 ; i<2*deg +1 ; i++)
    // printf("%f\n",*(s_x+i));

    for(i=0 ; i<=deg ; i++)
    {
        sum=0;
        for(j=0 ; j<n ; j++)
        sum = sum + *(y+j) * pow(*(x+j),i);
        *(s_y+i)=sum;
    }
    // printf("\n\n");
    // for(i=0 ; i<deg +1 ; i++)
    // printf("%f\n",*(s_y+i));

    

    /*Configuring the matrix*/
    for(i=0 ; i<deg+1 ; i++)
    {
        for(j=i, k=0 ; j<deg+i+1, k<deg+1 ; j++, k++)
        *(*(a_m+i)+k) = *(s_x+j);
    }
    for(i=0 ; i<deg+1 ; i++)
    *(*(a_m+i)+deg+1) = *(s_y+i);

    // printf("\nThe Matrix Form :\n");
    // for(i=0 ;i<deg+1;i++){
    // for(j=0 ;j<deg+2;j++)
    // printf("%.2f\t\t",*(*(a_m+i)+j));
    // printf("\n");}

    // printf("\n\n");

    /*Generating results*/
    float *res = gauss_jordan(a_m,deg+1);

    return res;
}

void trig_curve_fit(float* x, float *y, int n, float w)
{

    int i,j;

    float **a_m = (float**)calloc(2,sizeof(float*));
    for(i=0 ; i<2 ; i++)
    *(a_m+i) = (float*)calloc(3,sizeof(float));

    float *sum_x = (float*)calloc(1+2,sizeof(float));
    float *sum_y = (float*)calloc(1+1,sizeof(float));

    for(i=0 ; i<(1+2) ; i++)
    {
        *(sum_x+i)=0;
        for(j=0 ; j<n ; j++)
        *(sum_x+i) = *(sum_x+i) + pow(sin(*(x+j) * w),2-i) * pow(cos(*(x+j) * w),i);
    }

    for(i=0 ; i<2 ;i++)
    {
        *(sum_y+i)=0;
        for(j=0 ;j<n ; j++)
        *(sum_y+i) =  *(sum_y+i) +  ((*(y+j)) * sin( (i * M_PI/2) + ((pow(-1,i)) * (*(x+j)) * w)));
    
    }

    for(i=0 ; i<2 ;i++)
    {
        for(j=0 ; j<2 ; j++)
        *(*(a_m+i)+j)= *(sum_x+i+j);
    }

    for(i=0; i<2 ; i++)
    *(*(a_m+i)+2) = *(sum_y+i);

    /*Generating results*/
    float *res = gauss_jordan(a_m,2);

    /*Printing*/
    float A = sqrt (pow(*(res+0),2) + pow(*(res+1),2));
    float phi = atan(res[1]/res[0]);

    printf("\n\n\t\t\tY = ");
    if(phi>=0)
    printf("(%f) * sin ( (%f)(x) + (%f) )",A,w,phi);
    else
    printf("(%f) * sin ( (%f)(x) - (%f) )",A,w,-1 * phi);

}

void error_li_po(float* x_temp, float* y_temp, int n, float* res, int deg){
    float *temp = (float*)calloc(n,sizeof(float));
    int i,j;
    float sum, error=0;
    for(i=0 ; i<n; i++){
        sum=0;
        for(j=0 ; j<=deg ; j++){
            sum += *(res+j) * (pow(*(x_temp+i),j));
        }
        *(temp+i) = sum;
    }
    for(i=0 ; i<n ; i++)
    error += pow((*(temp+i)-*(y_temp+i)),2);
    printf("\n**********__\tSUMMED_ERROR = %f\t__**********\n",error);
}

void error_exp(float* x_temp, float* y_temp, int n, float* res, int deg){
    float *temp = (float*)calloc(n,sizeof(float));
    int i,j;
    float sum, error=0;
    for(i=0 ; i<n ; i++)
    *(y_temp+i) = exp(*(y_temp+i));
    for(i=0 ; i<n; i++){
        sum=0;
        for(j=0 ; j<=deg ; j++){
            sum += *(res+j) * (pow(*(x_temp+i),j));
        }
        sum = exp(sum);
        *(temp+i) = sum;
    }
    for(i=0 ; i<n ; i++)
    error += pow((*(temp+i)-*(y_temp+i)),2);
    printf("\n**********__\tSUMMED_ERROR = %f\t__**********\n",error);
}