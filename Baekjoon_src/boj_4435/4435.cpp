#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<long long> gal_v;
vector<long long> sha_v;

int main(){  
  int T;
  scanf("%d", &T);

  gal_v.resize(10);
  sha_v.resize(10);

  for(int idx=1; idx<=T; idx++){
	  long long num;

	  for (int i = 0; i < 6; i++) {
		  scanf("%lld", &num);
		  gal_v[i] = num;
	  }

	  for (int i = 0; i < 7; i++) {
		  scanf("%lld", &num);
		  sha_v[i] = num;
	  }

	  long long sum_gal = gal_v[0]*1 + gal_v[1]*2 + gal_v[2]*3 + gal_v[3]*3 + gal_v[4]*4 + gal_v[5]*10;
	  long long sum_sha = sha_v[0]*1 + sha_v[1]*2 + sha_v[2]*2 + sha_v[3]*2 + sha_v[4]*3 + sha_v[5]*5 + sha_v[6]*10;

	  printf("Battle %d: ", idx);

	  if (sum_gal > sum_sha)
	      printf("Good triumphs over Evil\n");
	  else if (sum_gal < sum_sha)
		  printf("Evil eradicates all trace of Good\n");
	  else if(sum_gal == sum_sha)
	      printf("No victor on this battle field\n");
  }

  return 0;
}
