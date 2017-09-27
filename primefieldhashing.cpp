#include <bits/stdc++.h>

const long long int A = 305;
const long long int B = 305;
const long long int large_prime = 1000000007;

long long int arr[1000];

//hashes x to [0..M-1] with keys a, b
long long int prime_field_hash(long long int a, long long int b, long long int x, long long int M){
	return ((a*(x % large_prime) + b) % large_prime) % M;
}

//generates random keys a,b to hash x to [0..M-1]
long long int random_prime_field_hash(long long int x, long long int M){
	srand(time(NULL));
	long long int a = rand(),b = rand();
	while(a == (1LL << 31) - 1 || a == 0) a = rand();
	while(b == (1LL << 31) - 1) b = rand();
	return prime_field_hash(a,b,x,M);
}

int main(void){
	for(long long int i = 0; i < 1000000; i++){
		arr[random_prime_field_hash(i,1000)]++;
	}
	for(int i = 0; i < 1000; i++){
		printf("%lli ",arr[i]);
	}
}
