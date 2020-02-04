#include <iostream>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;


int bruteforce(double* p_waga, double* p_wart,double* p_numer, int n, double U) {
	
	int i,j,isSelected=1,maxWaga,maxWart;
	int iter=pow(2.0,n);
	int result=0;
	int temp[n];
	int temp2[n];
	
	
	for(i =0;i<n;i++){
		temp[i]=0;
		temp2[i]=0;
	}
	
	
	for(i=0;i<iter;i++) {
		
		isSelected=1;
		maxWart=0;
		maxWaga=0;
		
		for(j=0;j<n;j++){
			if(temp[j]==1){
				maxWaga+=p_waga[j];
				maxWart+= p_wart[j];
			}
		}
		if(maxWaga <= U && maxWart>result){
			for(j=0;j<n;j++)
				temp2[j]=temp[j];
			result=maxWart;
		}
		
		for(j=0;j<n;j++){
			temp[j]=temp[j]+isSelected;
			isSelected = temp[j]/2;
			temp[j]=temp[j]%2;	
		}
		
	}
	
	for(i=0;i<n;i++) {
		if(temp2[i]==1) {
			U-=p_waga[i];
			cout<< "dodano do plecaka "<<p_numer[i]<<" "<<p_waga[i]<<" "<<p_wart[i]<<"\n";
		}
	}
	cout<<"Pojemnosc: "<<U<<"\nWartosc: ";
    
	return result;
}




void sortuj(double* p_waga, double* p_wart,double* p_numer, int n){
	double t;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(p_wart[j]/p_waga[j] < p_wart[j+1]/p_waga[j+1]){
				t = p_waga[j];
				p_waga[j] = p_waga[j + 1];
				p_waga[j + 1] = t;
				t = p_wart[j];
				p_wart[j] = p_wart[j + 1];
				p_wart[j + 1] = t;
				t=p_numer[j];
				p_numer[j]=p_numer[j+1];
				p_numer[j+1]=t;
				
			}
		}
	}
}

double zapakujZachlannie(double* p_waga, double* p_wart,double* p_numer, int n, double U) {
	sortuj(p_waga, p_wart, p_numer, n);
	double W = 0;	
	for(int i = 0; i < n; i++){
		if(U>=p_waga[i]){
		    U -= p_waga[i];		
		    W += p_wart[i];
		    cout<< "dodano do plecaka "<<p_numer[i]<<" "<<p_waga[i]<<" "<<p_wart[i]<<"\n";
		}
	}
	cout<<"Pojemnosc: "<<U<<"\nWartosc: ";
	return W;
}

int main () {
	int n=26;
	double U=40;
	double* p_numer = new double[n];
    for(int i=0;i<27;i++){
        p_numer[i]=i+1;
    }
	double* p_wart = new double[n];
    p_wart[0]=3;
    p_wart[1]=9;
    p_wart[2]=9;
    p_wart[3]=19;
    p_wart[4]=10;
    p_wart[5]=11;
    p_wart[6]=7;
    p_wart[7]=14;
    p_wart[8]=18;
    p_wart[9]=1;
    p_wart[10]=20;
    p_wart[11]=9;
    p_wart[12]=18;
    p_wart[13]=20;
    p_wart[14]=10;
    p_wart[15]=13;
    p_wart[16]=18;
    p_wart[17]=16;
    p_wart[18]=2;
    p_wart[19]=18;
    p_wart[20]=10;
    p_wart[21]=12;
    p_wart[22]=6;
    p_wart[23]=4;
    p_wart[24]=16;
    p_wart[25]=5;
	double* p_waga = new double[n];
    p_waga[0]=3;
    p_waga[1]=3;
    p_waga[2]=9;
    p_waga[3]=5;
    p_waga[4]=10;
    p_waga[5]=5;
    p_waga[6]=5;
    p_waga[7]=2;
    p_waga[8]=4;
    p_waga[9]=2;
    p_waga[10]=5;
    p_waga[11]=1;
    p_waga[12]=4;
    p_waga[13]=6;
    p_waga[14]=6;
    p_waga[15]=9;
    p_waga[16]=8;
    p_waga[17]=10;
    p_waga[18]=4;
    p_waga[19]=7;
    p_waga[20]=8;
    p_waga[21]=8;
    p_waga[22]=1;
    p_waga[23]=1;
    p_waga[24]=9;
    p_waga[25]=8;
    cout<<"plecak 1: \n";
    clock_t start = clock();
    cout<< bruteforce(p_waga, p_wart,p_numer, n, U);
	cout << endl;
	printf( "\nCzas wykonywania: %lu s\n", (double)(clock() - start)/ CLOCKS_PER_SEC );
	cout<<"plecak 2: \n";
	clock_t start1 = clock();
	cout << zapakujZachlannie(p_waga, p_wart,p_numer, n, U);
	delete[] p_waga, p_wart;
	printf( "\nCzas wykonywania: %lu ms\n", clock() - start1 );
	
	return 0;
}