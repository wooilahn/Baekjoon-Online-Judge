#define _CRT_SECURE_NO_WARNINGS
#define MAX(A,B) A>B?A:B
#include <stdio.h>

using namespace std;

int main(){
 int A, B;
 scanf("%d %d", &A, &B);
 printf("%d\n", MAX(A,B));

 return 0;
}
