/*Write a menu-driven program for solving a system of linear equations using
Gauss-Elimination method, Jacobi’s method and Gauss Elimination with pivoting 
method*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float* naive_gauss(float **a, int n);
float* gauss_jordan(float **a, int n);
float* jacobi(float **a, int n, int max, float e);
float* gauss_seidel(float **a, int n, int max, float e);
// void arr_cpy(float **a, float **b, int n);

// void main()
// {
    
//     char resp;
//     int n, c=0, ch, max, i, j;
//     float e;
//     float *x1, *x2, *x3, *x4;
//     float **a, **b;

//     printf("\n\nCHOOSE your option : \n1. Naive-Gaussian Elimination\n2. Gauss-Jordan(Pivot) Elimination\n3. Jacobi's Method\n4. Gauss-Seidel Method\n5. ALL at once :)\n\n");
//     scanf("%d",&ch);
    
//     printf("Enter the number of unknowns = ");
//     scanf("%d",&n);

//     /*allocating memory for primary array*/
//     a = (float**)calloc(n,sizeof(float*));
//     for(i=0 ; i<n ; i++)
//     *(a+i)=(float*)calloc(n+1,sizeof(float));

//     /*allocating memory for secondary array*/
//     b = (float**)calloc(n,sizeof(float*));
//     for(i=0 ; i<n ; i++)
//     *(b+i)=(float*)calloc(n+1,sizeof(float));


//     do{

//     if(c)
//     {
        
//         printf("\n\nCHOOSE your option : \n1. Naive-Gaussian Elimination\n2. Gauss-Jordan(Pivot) Elimination\n3. Jacobi's Method\n4. Gauss-Seidel Method\n5. ALL at once :)\n\n");
//         scanf("%d",&ch);
//         printf("\n\nDo you want to continue with previuosly entered values ? Type Y/y for YES and N/n for NO\n\n");
//         scanf(" %c",&resp);
//         if(resp=='n' || resp=='N')
//         {
//             printf("Enter the number of unknowns = ");
//             scanf("%d",&n);

//             /*allocating memory for primary array*/
//             a = realloc(a,n);
//             for(i=0 ; i<n ; i++)
//             *(a+i)=realloc(*(a+i),n+1);

//             /*allocating memory for secondary array*/
//             b = realloc(b,n);
//             for(i=0 ; i<n ; i++)
//             *(b+i)=realloc(*(b+i),n+1);
//             goto req ;
//         }
//         else
//         goto nreq ;
//     }
//     else{
//         req : ;

//     printf("Start entering the coefficients (row-wise) : \n\n");
//     for(i=0 ; i<n ; i++)
//     {
//         for(j=0 ; j<n+1 ; j++)
//         scanf("%f",*(a+i)+j);
//     }
//     }

//     nreq : ;

//     switch(ch)
//     {
//         case 1 : arr_cpy(a,b,n);
//                  x1 = naive_gauss(b,n);
//                  printf("\n\nThe solutions to these linear equations is : \n\n");
//                  for(i=0 ; i<n ; i++)
//                  printf("%f  ",*(x1+i));
//                  printf("\n\n");
//                  break;

//         case 2 : arr_cpy(a,b,n);
//                  x2 = gauss_jordan(b,n);
//                  printf("\n\nThe solutions to these linear equations is : \n\n");
//                  for(i=0 ; i<n ; i++)
//                  printf("%f  ",*(x2+i));
//                  printf("\n\n");
//                  break;

//         case 3 : arr_cpy(a,b,n);
//                  printf("Enter the maximum no. of iterations = ");
//                  scanf("%d",&max);
//                  printf("Enter the error tolerance = ");
//                  scanf("%f",&e);
//                  x3 = jacobi(b,n,max,e);
//                  break;
//         case 4 : arr_cpy(a,b,n);
//                  printf("Enter the maximum no. of iterations = ");
//                  scanf("%d",&max);
//                  printf("Enter the error tolerance = ");
//                  scanf("%f",&e);
//                  x4 = gauss_seidel(b,n,max,e);
//                  break;
//         case 5 : printf("Enter the maximum no. of iterations(for jacobi & gauss_seidel) = ");
//                  scanf("%d",&max);
//                  printf("Enter the error tolerance(for jacobi & gauss_seidel) = ");
//                  scanf("%f",&e);

//                  arr_cpy(a,b,n);
//                  x1 = naive_gauss(b,n);
//                  printf("\n\nThe solutions by naive-gauss : \n\n");
//                  for(i=0 ; i<n ; i++)
//                  printf("%f  ",*(x1+i));
//                  printf("\n\n");
                 
//                  arr_cpy(a,b,n);
//                  x2 = gauss_jordan(b,n);
//                  printf("\n\nThe solutions by gauss-jordan : \n\n");
//                  for(i=0 ; i<n ; i++)
//                  printf("%f  ",*(x2+i));
//                  printf("\n\n");
                 
//                  arr_cpy(a,b,n);
//                  x3 = jacobi(b,n,max,e);
                 
//                  arr_cpy(a,b,n);
//                  x4 = gauss_seidel(b,n,max,e);
//                  break;
//         default : printf("You have entered a WRONG data !!!");
//     }


//     printf("Do you want to continue further ? Type Y/y for YES and N/n for No : \n\n");
//     scanf(" %c",&resp);
//     c++;
// }while(resp=='y' || resp=='Y');


// free(a);

// }

// void arr_cpy(float **a, float **b, int n)
// {
//     int i, j;
//     /*equating primary and secondary array*/
//     for(i=0; i<n ; i++)
//     {
//         for(j=0 ; j<n+1 ; j++)
//         *(*(b+i)+j)=*(*(a+i)+j);
//     }
// }

float* naive_gauss(float** a, int n)
{
    int i, j, k;

    float u, sum;

    float *x = (float*)calloc(n,sizeof(float));

    printf("\n\nNAIVE-GAUSSIAN TECHNIQUE : \n\n");

    for(k=0 ; k<n-1 ; k++)
    {
        for(j=k+1 ; j<n ; j++)
        {
            u=a[j][k]/a[k][k];
            for(i=k ; i<n+1 ; i++)
            a[j][i] = a[j][i] - u*a[k][i];
        }
    }

    printf("\n\nThe augmented matrix is : \n\n");
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n+1 ; j++)
        printf("%6.4f\t\t",*(*(a+i)+j));
        printf("\n");
    }

    *(x+n-1)=*(*(a+n-1)+n)/a[n-1][n-1];
    for(i=n-2 ; i>=0 ; i--)
    {
        sum=0;
        for(j=i+1 ; j<n ; j++)
        sum += a[i][j]*x[j];
        x[i]=(a[i][n] - sum)/a[i][i];
    }

    return x;
}

float* gauss_jordan(float **a, int n)
{
    int i, j, k;

    float temp, u, sum;

    float *x = (float*)calloc(n,sizeof(float));

    // printf("GAUSSIAN-JORDAN TECHNIQUE : \n\n");

    for(i=0 ; i<n ; i++)
    {
        j=i+1;
        while((a[i][i]==0.0)&&j<n)
        {
            for(k=0 ; k<n+1 ; k++)
            {
                temp = a[i][k];
                a[i][k]=a[j][k];
                a[j][k]=temp;
            }
            j++;
        }
        temp = a[i][i];
        for(k=i ; k<n+1 ; k++)
        a[i][k] = a[i][k]/temp;

        for(j=0 ; j<n ; j++)
        {
            if(j!=i)
            {
                temp=a[j][i]/a[i][i];
                for(k=i ; k<n+1 ; k++)
                a[j][k] = a[j][k] - temp*a[i][k];
            }
        }
    }

    for(i=0 ; i<n ; i++)
    *(x+i) = *(*(a+i)+n);
    
    return x;
}

float* jacobi(float **a, int n, int max, float e)
{
    int i, j, k;

    float u, sum, err;

    float *x = (float*)calloc(n,sizeof(float));
    float *y = (float*)calloc(n,sizeof(float));

    

    printf("\n\nJACOBI'S TECHNIQUE : \n\n");

    for(i=0 ; i<max ; i++)
    {
        err=0;
        
        for(j=0 ; j<n ; j++)
        {
            sum=0;
            for(k=0 ; k<n ; k++)
            if(j!=k)
            sum += a[j][k]*x[k];

            sum = (a[j][n] - sum)/a[j][j];
            y[j]=sum;
            

            sum = (y[j] - x[j])/y[j];
            if(sum<0)
            sum *= -1;
            if(sum>err)
            err=sum;
        }
        for(j=0 ; j<n ; j++)
        x[j]=y[j];
        for(j=0 ; j<n ; j++)
        printf("%f  ",*(x+j));
        printf("\n\n");
        if(err <= e)
        {
            printf("CONVERGES TO A SOLUTION in %dth iteration !!!\n\n",i);
            for(j=0 ; j<n ; j++)
            printf("%.6lf  ",*(x+j));
            printf("\n\n");
            goto next ;
        }
    }

    printf("\n\nNOT CONVERGING !!! \n\n");
    printf("The solutions after (max =) %d iterations are : \n",max);
    for(j=0 ; j<n ; j++)
    printf("%f  ",*(x+j));
    printf("\n\n");

    next : ;

    free(y);

    return x;
}

float* gauss_seidel(float **a, int n, int max, float e)
{
    int i, j, k;

    float temp, sum, err;

    float *x = (float*)calloc(n,sizeof(float));

    printf("\n\nGAUSS SEIDEL'S TECHNIQUE : \n\n");

    for(i=0 ; i<max ; i++)
    {
        err=0;
        
        for(j=0 ; j<n ; j++)
        {
            sum=0;
            for(k=0 ; k<n ; k++)
            if(j!=k)
            sum += a[j][k]*x[k];

            temp = (a[j][n] - sum)/a[j][j];     

            sum = (temp - x[j])/temp;
            x[j]=temp;

            if(sum<0)
            sum *= -1;
            if(sum>err)
            err=sum;
        }
        for(j=0 ; j<n ; j++)
        printf("%f  ",*(x+j));
        printf("\n\n");
        if(err <= e)
        {
            printf("CONVERGES TO A SOLUTION in %dth iteration !!!\n\n",i);
            for(j=0 ; j<n ; j++)
            printf("%.6lf  ",*(x+j));
            printf("\n\n");
            goto next ;
        }
    }

    printf("\n\nNOT CONVERGING !!! \n\n");
    printf("The solutions after (max =) %d iterations are : \n",max);
    for(j=0 ; j<n ; j++)
    printf("%f  ",*(x+j));
    printf("\n\n");

    next : ;

    return x;
}