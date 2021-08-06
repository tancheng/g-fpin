
int* jg;
int a = 1;
int is1 = 2;
int is2 = 3;
int is3 = 4;

int i1 = 128;
int j1 = 3;
int j2 = 4;
int j3 = 5;

void kernel() {

  for (int i=0; i<128; ++i) {
    if (a==1) {
       jg[i] = 1;
       jg[i+1] = is1 - 2 + j1;
       jg[i+2] = is2 - 2 + j2;
       jg[i+3] = is3 - 2 + j3;
       i1 = i1-1;
    } else {
       jg[i] = 0;
       jg[i+1] = 0;
       jg[i+2] = 0;
       jg[i+3] = 0;
    }
  }
}

/*
if(a==1)then 
   jg(i) = 1
   jg(i+1) = is1 - 2 + j1
   jg(i+2) = is2 - 2 + j2
   jg(i+3) = is3 - 2 + j3
   i1 = i1-1
else
   jg(i) = 0
   jg(i+1) = 0
   jg(i+2) = 0
   jg(i+3) = 0
endif
*/
