all:	build

build:	xlsoutput

xlsoutput:	xlsoutput.c
	$(CC) -lX11 -lXrandr -o xlsoutput xlsoutput.c

clean:
	rm -f *~
	rm -f xlsoutput
