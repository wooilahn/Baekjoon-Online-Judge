#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  char c;
  int win = 0;
  
  for(int i=0; i<6; i++){
    scanf("%c", &c);
	getchar();

	if(c == 'W')
		win++;
  }

  if(win >= 5)
    printf("1\n");
  else if(win >= 3)
    printf("2\n");
  else if(win >= 1)
    printf("3\n");
  else
	printf("-1\n");

  return 0;
}
