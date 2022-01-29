#include "iostream"
#include "time.h"
using namespace std;

void print(int *ar,int n){
	for(int i=0;i<n;++i)
		cout<<ar[i]<<" ";
	cout<<"\n";
}

int getMax(int *ar,int n){
	int max = ar[0];
	for(int i=1;i<n;++i){
		if(ar[i] > max)
			max = ar[i];
	}
	return max;
}

void digitSorting_one(int *ar,int exp,int n){
	int *output = new int[n];// to store the newly sorted array
	int count[10] = {0};// to store the count of each digit,
	// here we are using the counting sort logic for sorting
	// individial digits of the respective numbers
	// in counting sort sorting is not done based on sorting
	// but by using clever index arithemtic(like hashing )
	// to find the ri8 place fr each element

	// the counting the last digit of the current state of the number
	// current state = ar[i]/exp 
	// exp could 1,10,100 depending upon the iteration level
	for(int i=0;i<n;++i)
		count[(ar[i]/exp)%10]++;


	// summing up count so each element can hav a unique
	// location to settle in
	for(int i=1;i<10;++i)
		count[i] += count[i-1];

	// inserting the element in the output array
	// by traversing the ar array from n-1 --> 0
	// insertion is done by 
	// counter = (ar[i]/exp)%10 last digit of the current state
	// output[count[counter]-1] = ar[i] "-1" for indexisizing into the array as indexing start from "0" & not "1"
	// then, count[counter] -= 1 so that u can accomodate other values
	// which have the same value as the current one
	// like we do in linear probing
	for(int i=n-1;i>=0;--i){
		output[count[(ar[i]/exp)%10]-1] = ar[i];
		count[(ar[i]/exp)%10]--;
	}
	// reinserting the final array into the original array
	for(int i=0;i<n;++i)
		ar[i] = output[i];
}

void radixSort_one(int *ar,int n){
	int max = getMax(ar,n);
	//getting the max element so that u can fill the smaller values with zeros for further comparision
	// eg:- max = 100 so, 1 --> 001 

	// so exp goes from 1 --> 10 --> till the no of digits present in the max element
	for(int exp = 1;max/exp > 0;exp*=10)
		digitSorting_one(ar,exp,n);
}

void digitSorting_two(int *ar,int exp,int n){
	int *output = new int[n];// to store the newly sorted array
	int count[10] = {0};// to store the count of each digit,
	// here we are using the counting sort logic for sorting
	// individial digits of the respective numbers
	// in counting sort sorting is not done based on sorting
	// but by using clever index arithemtic(like hashing )
	// to find the ri8 place fr each element

	// the counting the last digit of the current state of the number
	// current state = ar[i]/exp 
	// exp could 1,10,100 depending upon the iteration level
	for(int i=0;i<n;++i)
		count[(ar[i]/exp)%10]++;


	// summing up count so each element can hav a unique
	// location to settle in
	int sum=0,temp;// convert counts to starting indices
	for(int i=0;i<10;++i){
		temp = count[i];
		count[i] = sum;
		sum += temp;
	}

	// inserting the element in the output array
	// by traversing the ar array from n-1 --> 0
	// insertion is done by 
	// counter = (ar[i]/exp)%10 last digit of the current state
	// output[count[counter]] = ar[i] no indexisizing need here
	// then, count[counter] += 1 so that u can accomodate other values
	// which have the same value as the current one
	// like we do in linear probing
	for(int i=0;i<n;++i){// traverse from beginning
		output[count[(ar[i]/exp)%10]] = ar[i];
		count[(ar[i]/exp)%10]++;
	}
	// reinserting the final array into the original array
	for(int i=0;i<n;++i)
		ar[i] = output[i];
}

void radixSort_two(int *ar,int n){
	int max = getMax(ar,n);
	//getting the max element so that u can fill the smaller values with zeros for further comparision
	// eg:- max = 100 so, 1 --> 001 

	// so exp goes from 1 --> 10 --> till the no of digits present in the max element
	for(int exp = 1;max/exp > 0;exp*=10)
		digitSorting_two(ar,exp,n);
}

int main(){
	srand(time(0));
	int n;
	cout<<"total elements : ";
	cin>>n;

	int *ar = new int[n];
	for(int i=0;i<n;++i)
		ar[i] = rand() %1000;
	print(ar,n);
	// radixSort_one(ar,n);// traversing output array from end to start
	radixSort_two(ar,n);// traversing output array from start to end
	print(ar,n);
}