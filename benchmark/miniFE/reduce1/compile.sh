#clang -emit-llvm -O3 -o kernel.bc -c kernel.c
clang -emit-llvm -fno-unroll-loops -O3 -o kernel.bc -c kernel.c
#llvm-dis kernel.bc -o kernel.ll
