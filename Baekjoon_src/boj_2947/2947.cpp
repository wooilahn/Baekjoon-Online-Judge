#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int a, b, c, d, e;

void swap(int *n1, int*n2){
  int tmp = *n1;
  *n1 = *n2;
  *n2 = tmp;
}

void print_tree(){
  printf("%d %d %d %d %d\n", a, b, c, d, e);
}

bool check_tree(){
  if(a == 1 && b == 2 && c == 3 && d == 4 && e == 5)
    return true;
  else 
    return false;
}

int main(){
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

  while(true){
	  if (a > b) {
		  swap(&a, &b);
		  print_tree();
	  }
	  if (b > c) {
		  swap(&b, &c);
		  print_tree();
	  }
	  if (c > d) {
		  swap(&c, &d);
		  print_tree();
	  }
	  if (d > e) {
		  swap(&d, &e);
		  print_tree();
	  }
	  
	  if(check_tree() == true)
	    break;
  }

  return 0;
}
