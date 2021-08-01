

int NUM_BUCKETS = 1024;
int TEST_ARRAY_SIZE = 5;
int comm_size = 128;
int num_keys = 4;
int  bucket_sum_accumulator = 0;
int  local_bucket_sum_accumulator = 0;


int* process_bucket_distrib_ptr1;
int* process_bucket_distrib_ptr2;
int* send_displ;
int* bucket_size_totals;
int* bucket_size;
int* send_count;

void kernel() {
  send_displ[0] = 0;
  process_bucket_distrib_ptr1[0] = 0;
  int i = 0, j = 0;
  while( j < comm_size )
  {
      send_count[j] = 0;
      process_bucket_distrib_ptr1[j] = 1;
      j++;
  }  
}
