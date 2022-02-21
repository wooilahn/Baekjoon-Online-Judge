#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;
int road[105][105] = {0};
bool row_install[105] = {0};
bool col_install[105] = {0};

int main(){
  int N, L;
  scanf("%d %d", &N, &L);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	  scanf("%d", &road[i][j]);
	}
  }

  int ans = 0;
  int cur_pos = 0;

  for(int i=0; i<N; i++){
    memset(row_install, 0, sizeof(row_install));
	memset(col_install, 0, sizeof(col_install));

    //row check
	cur_pos = road[i][0];
	bool row_chk = false;
	int seq_row = 1;

	for(int k=1; k<N; k++){	
	  if(cur_pos > road[i][k]){
	    int suc_row = 1;

	    for(int t=k+1; t<N; t++){
		  if(road[i][k] == road[i][t] && suc_row < L)
		    suc_row++;
		  else
		    break;
		}

		if(suc_row >= L && cur_pos - road[i][k] == 1){
		  bool suc_chk = false;

		  for(int a=k; a<k+L; a++){
		    if(row_install[a] == true){
			  suc_chk = true;
			  break;
			}
			else
			  row_install[a] = true;
		  }

		  if(suc_chk == true){
		    row_chk = false;
			break;
		  }

		  cur_pos = road[i][k];
		  seq_row = 1;
		}
		else{
		  row_chk = false;
		  break;
		}
	  }
	  else if(cur_pos == road[i][k]){
	    cur_pos = road[i][k];
	    seq_row++;
	  }
	  else if(cur_pos < road[i][k]){
	    if(seq_row >= L && road[i][k]-cur_pos == 1){
		  bool suc_chk2 = false;

		  for(int a=k-1; a>k-L-1; a--){
		    if(row_install[a] == true){
		      suc_chk2 = true;
			  break;
		    }
		    else
		      row_install[a] = true;
		  }

		  if(suc_chk2 == true){
		    row_chk = false;
			break;
		  }

		  cur_pos = road[i][k];
		  seq_row = 1;
		  row_install[k-1] = true;
		}
		else{
		  row_chk = false;
		  break;
		}
	  }

	  if(k==N-1){
	    row_chk = true;
		break;
	  }
	}

	if(row_chk == true){
	  //printf("row: %d\n", i);
	  ans++;
	}

	//column check
	cur_pos = road[0][i];
	bool col_chk = false;
	int seq_col = 1;

	for(int k=1; k<N; k++){
	  if(cur_pos > road[k][i]){
		  int suc_col = 1;

		  for (int t = k+1; t < N; t++) {
			  if (road[k][i] == road[t][i] && suc_col < L)
				  suc_col++;
			  else
				  break;
		  }

		  if (suc_col >= L && cur_pos - road[k][i] == 1) {
		      bool suc_chk3 = false;

			  for(int a=k; a<k+L; a++){
			    if(col_install[a] == true){
				  suc_chk3 = true;
				  break;
				}
				else
				  col_install[a] = true;
			  }

			  if(suc_chk3 == true){
			    col_chk = false;
				break;
			  }
		    
			  cur_pos = road[k][i];
			  seq_col = 1;
			  col_install[k] = true;
		  }
		  else {
			  col_chk = false;
			  break;
		  }
	  }
	  else if(cur_pos == road[k][i]){
	    cur_pos = road[k][i];
		seq_col++;
	  }
	  else if(cur_pos < road[k][i]){
	    if(seq_col >= L && road[k][i] - cur_pos == 1 && !col_install[k-1]){
		  bool suc_chk4 = false;

		  for(int a = k-1; a > k-L-1; a--){
		    if(col_install[a] == true){
			  suc_chk4 = true;
			  break;
			}
			else
			  col_install[a] = true;
		  }

		  if(suc_chk4 == true){
		    col_chk = false;
			break;
		  }

		  cur_pos = road[k][i];
		  seq_col = 1;
		  col_install[k-1] = true;
		}
		else{
		  col_chk = false;
		  break;
		}
	  }

	  if(k == N-1){
	    col_chk = true;
		break;
	  }
	}

	if(col_chk == true){
	  //printf("col: %d\n", i);
	  ans++;
	}
  }

  printf("%d\n", ans);

  return 0;
}
