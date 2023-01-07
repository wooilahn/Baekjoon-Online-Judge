#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
 int N;
 scanf("%d", &N);

 int ans = 0;

 for(int i=3; i<=N-6; i+=3){
   for(int j=3; j<=N-i-3; j+=3){
     int k = N-i-j;

	 if(i+j+k == N)
	   ans++;
   }
 }

 printf("%d\n", ans);

 return 0;
}
