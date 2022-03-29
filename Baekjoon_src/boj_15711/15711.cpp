
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long A, B, C;
bool prime[2000005] = {0};
vector<int> prime_v;

void eratos(){
  prime[1] = 1;
           
  for(int i=2; i*i<2000000; i++){
      if(!prime[i]){
		  for (int k=i*i; k<2000000; k+=i)
			  prime[k] = 1;
	  }
  }

  for(int i=2; i<=2000000; i++){
    if(!prime[i])
	  prime_v.push_back(i);
  }

  return;
}

int main(){
  int T;
  scanf("%d", &T);
  eratos();

  while(T--){
    scanf("%lld %lld", &A, &B);
    C = A+B;

	if(C == 2 || C == 3)
	  printf("NO\n");
	else if (C%2 == 0)
	  printf("YES\n");
	else if (C%2 == 1){
	  bool check_flag = false;
	  C -= 2;

	  for(int i=0; i<prime_v.size() && (long long)prime_v[i]*prime_v[i]<=C; i++){
	    if(C % prime_v[i] == 0){
		  check_flag = true;
		  printf("NO\n");
		  break;
		}
	  }

	  if(!check_flag)
	    printf("YES\n");
	}
  }

  return 0;
}

