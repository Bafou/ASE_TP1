#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned int esp;
static unsigned int ebp;

void display_register(unsigned int ebp,unsigned int esp) {
  printf("EBP : %08x\tESP : %08x\n",ebp,esp);
}

int factorielle(int fac) {

  printf("\nAdresse de variable en entrée : %08x\n*******\n",(unsigned int) &fac);
  printf("calcul de la factorielle de %d\n",fac);
  asm("mov %%ebp, %0" "\n\t" "mov %%esp, %1":"=r"(ebp),"=r" (esp));
  display_register(ebp,esp);


  if(fac < 2)
    return fac;
  else
    return fac * factorielle(fac-1);

}


int main (void) {
  printf("main\n");
  asm("mov %%ebp, %0" "\n\t" "mov %%esp, %1":"=r"(ebp),"=r" (esp));
  display_register(ebp,esp);
  printf("\n*******\n\n"); 
  factorielle(6);
  printf("\n");
  return 0;
}  

