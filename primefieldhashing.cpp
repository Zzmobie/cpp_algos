#include <bits/stdc++.h>

const long long int A = 305;
const long long int B = 305;
const long long int large_prime = (1LL << 62) - 57;

long long int prime_field_hash(){
	return 0;
}

//returns a*b mod p in o(logb) time p < 2^62
long long mul(long long a, long long b, long long p){
	a = (a + p) % p;
	b = (b + p) % p;
	long long int ret = 0;
	while(b != 0){
		if(b % 2) ret = (ret + a) % p;
		a = (a * 2) % p;
		b /= 2;
	}
	return ret;
}

int main(void){
	long long int c[A][B];
	printf("%lli\n",large_prime);
}
