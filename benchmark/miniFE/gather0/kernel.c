
int* global_offsets;
int offset = 0;

void kernel() {
  //int offset = 0;
  for(int i=0; i<128; ++i) {
    int tmp = global_offsets[i];
    offset += tmp;
  }
}
