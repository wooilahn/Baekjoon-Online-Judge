#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int cur = 0, num = 0;
  char c;
  scanf("%d\n", &cur);

  while(true){
    scanf("%c\n", &c);

	if (c == '=') {
		printf("%d\n", cur);
		break;
	}

	scanf("%d\n", &num);

	if(c == '+')
	  cur += num;
	else if(c == '-')
	  cur -= num;
	else if(c == '*')
	  cur *= num;
	else if(c == '/')
	  cur /= num;
  }

  return 0;
}
