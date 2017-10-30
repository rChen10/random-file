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
  //printf("%d\n", randos);
  return randos;
}


int main(){
  int nums[10];
  int *ran = nums;
  int i = 0;
  int fledis = open("/dev/random", O_RDONLY);
  if (fledis < 0){
    printf("%s\n", strerror(errno));
    return;
  }
  printf("Generating random numbers:\n");
  for (; i<10; i++){
    nums[i] = generate(fledis);
    printf("random %d: %d\n", i, nums[i]);
  }
  close(fledis);
  i = 0;
  

  printf("Writing numbers to random_output...\n");
  int fldis = open("random_output", O_CREAT | O_WRONLY, 0777);
  if (fldis < 0){
    printf("%s\n", strerror(errno));
    return;
  }
  write(fldis, nums, sizeof(nums));
  //printf("%s\n", strerror(errno));
  //printf("%d\n", fldis);
  close(fldis);

  printf("Reading numbers from random_output...\n");
  fldis = open("random_output", O_RDONLY);
  if (fldis < 0){
    printf("%s\n", strerror(errno));
    return;
  }
  int nums_2[10];
  read(fldis, nums_2, sizeof(nums_2));
  //printf("%lu\n", sizeof nums_2 / sizeof(int));
  //close(fldis);

  //read_from(fldis, nums_2);
  i = 0;
  printf("Verification that written values are the same:\n");
  for (; i<10; i++){
    printf("random %d: %d\n", i, nums_2[i]);
  }

 
}
