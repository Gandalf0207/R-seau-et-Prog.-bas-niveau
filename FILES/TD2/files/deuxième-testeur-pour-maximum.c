#include <stdlib.h>

int maximum(int[],int);
  
int main(){
  int T[]={-6,-3,-99,-2,-80};
  int max=maximum(T,5);
  if (max==-2) return EXIT_SUCCESS;
  else return EXIT_FAILURE;
}
