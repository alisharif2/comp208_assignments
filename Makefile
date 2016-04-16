default: mach.exe palindromes.exe frugal.exe

mach.exe: mach.c
	gcc $? -o $@

palindromes.exe: palindromes.c
	gcc $? -o $@

frugal.exe: frugal.c
	gcc $? -o $@

assignment2: palindromes.exe
	$?

assignment4: frugal.exe
	$?

assignment5: mach.exe
	$?

clean:
	-del mach.exe palindromes.exe frugal.exe
