CC=gcc
FLAGS=-lm

default: mach palindromes frugal

mach: mach.c
	$(CC) $? -o $@ $(FLAGS)

palindromes: palindromes.c
	$(CC) $? -o $@ $(FLAGS)

frugal: frugal.c
	$(CC) $? -o $@ $(FLAGS)

assignment2: palindromes
	$?

assignment4: frugal
	$?

assignment5: mach
	$?

clean:
	-rm mach palindromes frugal
