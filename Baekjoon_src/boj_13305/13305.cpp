#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> road;
vector<ll> city;

int main(){
  int n;
  scanf("%d", &n);

  ll tmp;

  for(int i=0; i<n-1; i++){
    scanf("%lld", &tmp);
	road.push_back(tmp);
  }

  for(int i=0; i<n; i++){
    scanf("%lld", &tmp);
	city.push_back(tmp);
  }

  ll min_gas = city[0];
  ll ans = 0;

  for(int i=0; i<n-1; i++){
    ans += min_gas * road[i];

	if(city[i+1] <= min_gas){
	  min_gas = city[i+1];
	}
  }


