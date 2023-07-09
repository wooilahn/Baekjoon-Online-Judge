#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	int M, n;
	char type, c;

	while (T--) {
		scanf("%d %c", &M, &type);
		getchar();

		if (type == 'C') { // char -> number
			vector<int> iv;

			for (int i = 0; i < M; i++) {
				scanf("%c", &c);
				iv.push_back(c - 'A' + 1);
				getchar();
			}
			
			for (int i = 0; i < iv.size(); i++)
				printf("%d ", iv[i]);
			printf("\n");
		}
		else if (type == 'N') { // number -> char
			vector<char> cv;

			for (int i = 0; i < M; i++) {
				scanf("%d", &n);
				cv.push_back('A' + n - 1);
			}

			for (int i = 0; i < cv.size(); i++)
				printf("%c ", cv[i]);
			printf("\n");
		}

	}

	return 0;
}
