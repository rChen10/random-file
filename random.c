#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

unsigned int generate(int filedes){
	int *randos = (int  *) malloc(sizeof(int));
	int output = read(filedes, randos, 4);
	if (output < 0){
		printf("Error: %s\n", strerror(errno));
	}
	else{
		return *randos;
	}
}

int main(){
	int fldis = open("/dev/random", O_RDONLY);
	printf("%d\n", generate(fldis));
	printf("Generating random numbers:\n");
	int n = 0;
	int ary[10]; 
	while(n < 10){
		ary[n] = generate(fldis);
		printf("	random %d: %d\n", n, ary[n]);
		n++;
	}

}
