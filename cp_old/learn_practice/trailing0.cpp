#include <bits/stdc++.h>
using namespace std;


void trailingZeroes(int n){
	int a=0, b=0;
	cout<<"2's = "<<a<<"  5's = "<<b<<endl;
	cout<<"----------"<<endl;
	while(n>0){
		int temp = n;
		while(temp>0){
			if(temp%2 == 0){
				a++;
				temp/=2;
			}
			else if(temp%5 == 0){
				b++;
				temp/=5;
			}
			else
				break;
		}
		cout<<"2's = "<<a<<"  5's = "<<b<<endl;
		n--;
	}
	if(a>b)
		cout<<"No.of trailing zeroes = "<<b<<endl;
	else
		cout<<"No.of trailing zeroes = "<<a<<endl;

}


void trailingZeroesalt(int n){
	int i, j, a=0, b=0;
	for(i=2, j=5; i<=n , j<=n ; i*=2 , j*=5){
		a = a + n/i;
		b = b + n/j;
	}
	if(a>b)
		cout<<"No.of trailing zeroes = "<<b<<endl;
	else
		cout<<"No.of trailing zeroes = "<<a<<endl;

}




int main()
{
	int n;
	cout<<"Enter n = ";
	cin>>n;
    // trailingZeroes(n);
    trailingZeroesalt(n);
    return 0;
}