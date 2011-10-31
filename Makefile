all:	build

build:	xlsoutput

xlsoutput:	xlsoutput.c
	$(CC) -o xlsoutput xlsoutput.c -lX11 -lXrandr

clean:
	rm -f *~
	rm -f xlsoutput
