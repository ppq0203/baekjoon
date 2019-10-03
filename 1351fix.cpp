#include <stdio.h>

long long int infinite_sequence (long long int, int, int);

int main(int argc, char const *argv[])
{
	long long int n;
	int p, q;
	scanf("%lld %d %d", &n, &p, &q);
	printf("%lld\n", infinite_sequence(n,p,q));
	return 0;
}

void clac_sequence(long long int [41][41], long long int, int, int, int, int);

long long int infinite_sequence (long long int number, int p, int q){
	long long int sequence[41][41] = {0};	// 2^40 > 10^12
	clac_sequence(sequence, number, 0, 0, p, q);
	return sequence[0][0];
}

void clac_sequence(long long int sequence[41][41], long long int number, int p_count, int q_count, int p, int q){
	if (sequence[p_count][q_count] != 0)
		return;
	if (number < 1)
	{	
		sequence[p_count][q_count] = 1;
		return ;
	}
	clac_sequence(sequence, number/p, p_count+1, q_count, p, q);
	clac_sequence(sequence, number/q, p_count, q_count+1, p, q);
	sequence[p_count][q_count] = sequence[p_count+1][q_count]+sequence[p_count][q_count+1];
}
