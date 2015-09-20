#include <stdio.h>
#include <stdlib.h>
#include "try.h"

int try (struct ctx_s *pctx, func_t *f, int arg) {
asm ("movl %%esp, %0"
     : "=r" (pctx->esp) 
     : 
     :);
asm ("movl %%ebp, %0"
     : "=r" (pctx->ebp)
     :
     :);
return f(arg); 
}

int throw (struct ctx_s *pctx, int r) {
res=r;
asm ("movl %0, %%ebp"
     :
     : "r" (pctx->ebp)
     :);
asm ("movl %0, %%esp"
     :
     : "r" (pctx->esp)
     :);
return res;}

