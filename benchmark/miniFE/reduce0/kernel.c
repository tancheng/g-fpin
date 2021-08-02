
int local_n = 0;
int global_n = 0;
int min_proc = 0;
int max_proc = 0;
int* all_n;

void kernel() {

  int min_n= 5*local_n;
  int max_n= 0;

  for(int i=0; i<128; ++i) {
    global_n += all_n[i];
    if (all_n[i] < min_n) {
      min_n = all_n[i];
      min_proc = i;
    }
    if (all_n[i] >= max_n) {
      max_n = all_n[i];
      max_proc = i;
    }
  }

}
