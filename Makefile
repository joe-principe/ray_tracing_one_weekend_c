# $@ - Target name
# $^ - Target dependencies

CC = gcc
CFLAGS = -Wall -g

first:
	echo "Joe Rules!"

ch1: src/ch1.c
	$(CC) $^ $(CFLAGS) -o bin/$@

run_ch1:
	bin/ch1

ch2: src/ch2.c src/vec3.c
	$(CC) $^ $(CFLAGS) -lm -o bin/$@

run_ch2:
	bin/ch2

ch3: src/ch3.c src/ray.c src/vec3.c
	$(CC) $^ $(CFLAGS) -lm -o bin/$@

run_ch3:
	bin/ch3

move_render:
	mv *.ppm renders/
