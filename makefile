randommake: random.c rando.h
	gcc -o randommake random.c

run: randommake
	./randommake