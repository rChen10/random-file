#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int generate(int fldis){
  //printf("opened\n");
  //printf("%d\n", fldis);
  //strerror(errno);
  int randos;
  read(fldis, &randos, sizeof(randos));
  //printf("read\n");
  printf("%d\n", randos);
  return randos;
}

void write_to(int fldis, int *randos, int num){
  if (! num) return;
  write(fldis, randos, sizeof(*randos));
  write(fldis, "\n", sizeof "\n");
  write_to(fldis, ++randos, --num);
}

void read_from(int fldis){
  
}

int main(){
  int nums[10];
  int *ran = nums;
  int i = 0;
  int fldis = open("/dev/random", O_RDONLY);
  if (fldis < 0){
    printf("%s\n", strerror(errno));
    return;
  }
  printf("Generating random numbers:\n");
  for (; i<10; i++){
    printf("random %d: ", i);
    nums[i] = generate(fldis);
  }
  close(fldis);

  
  printf("Writing numbers to random_output...\n");
  fldis = open("random_output", O_CREAT | O_WRONLY, 644);
  if (fldis < 0){
    printf("%s\n", strerror(errno));
    return;
  }
  write_to(fldis, ran, sizeof nums / sizeof(int));
  //printf("%s\n", strerror(errno));
  //printf("%d\n", fldis);
  close(fldis);

  
  printf("Reading numbers from random_output...\n");
  fldis = open("random_output", O_RDONLY);
  
  close(fldis);
}
