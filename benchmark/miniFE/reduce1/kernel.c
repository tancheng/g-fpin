
int* external_index;
int* global_index_offsets;
int* external_processor;

void kernel() {

  for(int x=0; x<5257*128; ++x) {
    int i = x / 128;
    int j = 127 - x % 128;
    int cur_ind = external_index[i];
    if (global_index_offsets[j] <= cur_ind && global_index_offsets[j] >= 0) {
      external_processor[i] = j;
    }
  }

//  for(LocalOrdinal i=0; i<5257; ++i) {
//    GlobalOrdinal cur_ind = external_index[i];
//    for(int j=127; j>=0; --j) {
//      if (global_index_offsets[j] <= cur_ind && global_index_offsets[j] >= 0) {
//        external_processor[i] = j;
//      }
//    }
//  }

}
