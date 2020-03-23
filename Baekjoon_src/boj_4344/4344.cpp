#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

double scores[1002] = { 0 };
double avg = 0.0;

int main() {

	int C, N;
	scanf("%d", &C);

	while (C--) {
		int cnt = 0;
		double sum = 0.0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%lf", &scores[i]);
			sum += scores[i];
		}

		avg = (double)sum / N;

		for (int i = 0; i < N; i++) {
			if (scores[i] > avg)
				cnt++;
		}

		printf("%0.3lf%%\n", ((double)cnt*100 / N));
	}

	return 0;
}
