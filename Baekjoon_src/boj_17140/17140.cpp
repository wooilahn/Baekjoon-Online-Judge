#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[105][105] = {0};

int main(){
  int r, c, k;
  scanf("%d %d %d", &r, &c, &k);

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
	  scanf("%d", &arr[i][j]);
	}
  }

  int cur_r = 3;
  int cur_c = 3;
  int cur_time = 0;

  while(true){
  	if(arr[r-1][c-1] == k)
	  break;
	else if(cur_time > 100)
	  break;

	vector<int> v;
	vector<pair<int,int>> rank_v;
	int tmp_arr[105][105] = {0};

	int tmp_r = cur_r;
	int tmp_c = cur_c;

	if(cur_r >= cur_c){ // R operation
	  for(int i=0; i< cur_r; i++){
	    v.clear();
	    rank_v.clear();
		int min_v = 101;
		int max_v = -1;

	    for(int k=0; k<cur_c; k++){
		  if(arr[i][k] != 0){
		    v.push_back(arr[i][k]);
			min_v = min(arr[i][k], min_v);
			max_v = max(arr[i][k], max_v);
		  }
		}

	    for(int q=min_v; q<=max_v; q++){
		  if (count(v.begin(), v.end(), q) != 0)
		    rank_v.push_back(make_pair(count(v.begin(), v.end(), q), q));
		}
	      
		sort(rank_v.begin(), rank_v.end());
		tmp_c = max(tmp_c, (int)rank_v.size()*2);
		tmp_c = min(tmp_c, 100);
		  
		for(int q=0; q<rank_v.size(); q++){
		  if (q*2 > 99)
		    break;
		  tmp_arr[i][q*2] = rank_v[q].second;
		  tmp_arr[i][q*2+1] = rank_v[q].first;
		}
	  }
	}
	else if(cur_r < cur_c){ // C operation
	  for(int i=0; i<cur_c; i++){
	    v.clear();
		rank_v.clear();
		int min_v = 101;
		int max_v = -1;

		for(int k=0; k<cur_r; k++){
		  if(arr[k][i] != 0){
		    v.push_back(arr[k][i]);
			min_v = min(arr[k][i], min_v);
			max_v = max(arr[k][i], max_v);
		  }
		}

		for(int q=min_v; q<=max_v; q++){
		    if(count(v.begin(), v.end(), q) != 0)
			  rank_v.push_back(make_pair(count(v.begin(), v.end(), q), q));
		}

		sort(rank_v.begin(), rank_v.end());
		tmp_r = max(tmp_r, (int)rank_v.size()*2);
		tmp_r = min(tmp_r, 100);

		for(int q=0; q<rank_v.size(); q++){
		  if(q*2 > 99)
			break;
		  tmp_arr[q*2][i] = rank_v[q].second;
		  tmp_arr[q*2+1][i] = rank_v[q].first;
		}
	  }
	}

    cur_time++;
	cur_r = tmp_r;
	cur_c = tmp_c;
	memset(arr, 0, sizeof(arr));

	for(int r=0; r<cur_r; r++){
	  for(int c=0; c<cur_c; c++){
	    arr[r][c] = tmp_arr[r][c];
	  }
	}

  }

  if(cur_time <= 100)
    printf("%d\n", cur_time);
  else
    printf("-1\n");

  return 0;
}
