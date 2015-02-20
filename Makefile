all:
	clang -o vtfconvert vtfconvert.c -lIL
clean:
	rm vtfconvert
