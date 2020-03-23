#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
double scores[1002] = { 0 };

int main() {

	int N;
	double score, sum = 0.0, max_score = -1;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lf", &score);
		scores[i] = score;

		if (max_score < score)
			max_score = score;
	}

	for (int i = 0; i < N; i++) 
		sum += (scores[i] / max_score) * 100;
	
	printf("%lf\n", (double)sum / N);

	return 0;
}
