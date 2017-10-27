#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

unsigned int generate(int fildes){
  
}

int main(){
  int fldis = open("/dev/random", O_RDONLY);
  int *randos = (int  *) malloc(sizeof(int) * 100);
  read(fldis, randos, 100);
  prinf("%d\n"
  
}
