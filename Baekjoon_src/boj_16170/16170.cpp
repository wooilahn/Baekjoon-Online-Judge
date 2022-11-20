#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

using namespace std;

int main(){
	time_t t;
	struct tm *gt;

	if ((t = time(NULL)) == -1) {
		return -1;
	}

	if ((gt = gmtime(&t)) == NULL) {
		return -1;
	}

	printf("%04d\n%02d\n%02d\n", (gt->tm_year) + 1900, (gt->tm_mon) + 1, gt->tm_mday);
	return 0;
}
