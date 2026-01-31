#ifndef EX_CONCURRENCY_H
#define EX_CONCURRENCY_H
#include "c_basic_thread.c"
#include "c_multi_thread_atomic.c"
#include "c_multi_thread_nonsequential.c"
#include "c_multi_thread_sequential.c"

extern void c_basic_thread(void);
extern void c_multi_thread_atomic(void);
extern void c_multi_thread_nonsequential(void);
extern void c_multi_thread_sequential(void);


#endif
