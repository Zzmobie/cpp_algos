//Calculate determinant in F_p for larger primes, p < 2^62, O(n^3logp)
#include <bits/stdc++.h>

const int MAXN = 305;
const int PRIME = 1e9 + 7;

long long mat[MAXN][MAXN];

//returns a*b mod p in o(b) time p < 2^62
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

//calculates a^x mod p
long long exp(long long a, long long x, long long p){
	if(x == 0) return 1;
	if(x == 1) return a;

	long long k = exp(a,x/2,p);
	k = mul(k,k,p);
	if(x % 2) return mul(a,k,p);
	else return k;
}

//does Gaussian elimination on matrix mat, under modulo p
void gauss_elim(int n, long long p){
	int d = 0;//null space dimension
	for(int r = 0; r + d < n ; r++){
		while(r + d < n && mat[r][r+d] == 0){
			d++;
			for(int i = r+1; i < n; i++)
				if(mat[i][r+d-1] != 0){
					d--;
					for(int j = r+d; j < n; j++){
						mat[r][j] += mat[i][j];
					}
					break;
				}
		}
		if(r + d < n){
			long long inverse = exp(mat[r][r+d],p-2,p);
			printf("x: %lli, inv; %lli\n",mat[r][r+d],inverse);
			for(int i = r + 1; i < n; i++)
				for(int j = n - 1; j >= r + d; j--){
					mat[i][j] -= mul(mul(mat[r][j],inverse,p),mat[i][r+d],p);
					mat[i][j] = (mat[i][j] + p) % p;
				}
		}
	}
}

long long det1(int n, long long p){
	long long ret = 1;
	for(int i = 0; i < n; i++){
		ret = (ret * mat[i][i]) % p;
	}
	return ret;
}

long long det(int n, long long p){
	long long ret = 1;
	for(int i = 0; i < n; i++){
		ret = mul(ret,mat[i][i],p);
	}
	return ret;
}

int main(){
	long long n,i,j;
	scanf("%lli",&n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%lli",&mat[i][j]);
		}
	}
	gauss_elim(n,PRIME);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%lli ",mat[i][j]);
		}
		printf("\n");
	}
	printf("det: %lli\n",det(n,PRIME));
	printf("det: %lli\n",det1(n,PRIME));

}
