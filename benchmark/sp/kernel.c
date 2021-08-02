
#include <math.h>

double* recv;
double* ext;

void kernel() {

  for(int x=0; x<24; ++x) {
    int i = x / 3;
    int j = x % 3;
    recv[i] = recv[i] / (double)(ext[j]-2);
    if(j == 2) {
      recv[i] = sqrt(recv[i]);
    }
  }
  
/*
  for(int i=0; i<8; i++){
    for(int j=0; j<3; j++){
      recv[i] = recv[i] / (double)(ext[j]-2);
    }
    recv[i] = sqrt(recv[i]);
  }
*/
}

