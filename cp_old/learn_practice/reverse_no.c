#include<stdio.h>

void getandRevnum(char *s){
	int n1=0, n2=0, i, rem;
		printf("The digits are : ");
	for(i=0 ; s[i]!='.' ; i++){
		printf("%d ",(int)( s[i] - '0'));
		n1 = (n1*10) + (s[i] - '0');
	}
	i++;

	for( ; s[i]!='\0' ; i++){
		printf("%d ",(int)( s[i] - '0'));
		n2 = (n2*10) + (s[i] - '0');
	}
	printf("\n");

	printf("The number in reverse order is : ");

	while(n2!=0){
		rem = n2%10;
		printf("%d",rem);
		n2/=10;
	}
	printf(".");
	while(n1!=0){
		rem = n1%10;
		printf("%d",rem);
		n1/=10;
	}


}

int main(int argc, char *argv[]){
	char s[100];
	printf("Enter the number = ");
	scanf(" %s",s);
	getandRevnum(s);
	return 0;
}

