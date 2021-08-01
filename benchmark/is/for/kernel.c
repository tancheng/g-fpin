

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
  int i, j;
  
  for( i=0, j=0; i<NUM_BUCKETS; i++ )  
  {
    bucket_sum_accumulator       += bucket_size_totals[i];
    local_bucket_sum_accumulator += bucket_size[i];
    if( bucket_sum_accumulator >= (j+1)*num_keys )  
    {
      send_count[j] = local_bucket_sum_accumulator;
      if( j != 0 )
      {
        send_displ[j] = send_displ[j-1] + send_count[j-1];
        process_bucket_distrib_ptr1[j] = process_bucket_distrib_ptr2[j-1]+1;
      }
      process_bucket_distrib_ptr2[j++] = i;
      local_bucket_sum_accumulator = 0;
    }
  }
}
