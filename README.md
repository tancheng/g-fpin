
Build
--------------------------------------------------------

The mapper requires the following additional prerequisites:

 - LLVM 11.0
 - CMAKE 3.1



Execution
--------------------------------------------------------
Generate DFG for a target kernel:
```
 % opt -load ~/this repo/build/mapper/libmapperPass.so -mapperPass ~/target benchmark/target_kernel.bc
``` 
