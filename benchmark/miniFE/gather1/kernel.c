
int* all_nrows;
int avg_nrows = 0;
int sum_sqr_dev = 0;

void kernel() {
  for(int i=0; i<128; ++i) {
    all_nrows[i] -= avg_nrows;
    all_nrows[i] *= all_nrows[i];
    sum_sqr_dev += all_nrows[i];
  }
}
