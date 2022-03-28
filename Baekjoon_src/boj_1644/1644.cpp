#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
bool prime[4000004] = {0};
vector<int> prime_v;

void eratos(){
  prime[1] = 1;

  for(int i=2; i<=4000000; i++){
    if(prime[i] == 0){
	  prime_v.push_back(i);
	  for(int k=i+i; k<=4000001; k+=i){
	    prime[k] = 1;
	  }
	}
  }

  return;
}

int main(){
  int N;
  scanf("%d", &N);
  eratos();

  int answer = 0;

  for(int i=0; i<prime_v.size(); i++){ 
     int tmp = 0;

     for(int k=i; k<prime_v.size(); k++){
	   tmp += prime_v[k];

	   if(tmp > N)
	     break;
	   if(tmp == N){
	     answer++;
		 break;
	   }
	 }
  }

  printf("%d\n", answer);

  return 0;
}
