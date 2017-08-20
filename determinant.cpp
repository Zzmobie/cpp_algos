//Calculate determinant in F_p
#include <bits/stdc++.h>

const int MAXN = 305;
const long long int PRIME = 1000000007LL;

long long int mat[MAXN][MAXN];

//calculates a^x mod p
long long int exp(long long int a, long long int x, long long int p){
	if(x == 0) return 1;
	if(x == 1) return a;

	long long int k = exp(a,x/2,p);
	k = (k*k) % p;
	if(x % 2) return (a*k) % p;
	else return k;
}

//does Gaussian elimination on matrix mat, under modulo p
void gauss_elim(int n, long long int p){
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
			long long int inverse = exp(mat[r][r+d],p-2,p);
			printf("x: %lli, inv; %lli\n",mat[r][r+d],inverse);
			for(int i = r + 1; i < n; i++)
				for(int j = n - 1; j >= r + d; j--){
					mat[i][j] -= (((mat[r][j]*inverse) % p)*mat[i][r+d]) % p;
					mat[i][j] = (mat[i][j] + p) % p;
				}
		}
	}
}

long long int det(int n, long long int p){
	long long int ret = 1;
	for(int i = 0; i < n; i++){
		ret = (ret * mat[i][i]) % p;
	}
	return ret;
}

int main(){
	long long int n,i,j;
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
}