all:	build

build:	xlsoutput xlsxinerama

xlsoutput:	xlsoutput.c
	$(CC) -o xlsoutput xlsoutput.c -lX11 -lXrandr

xlsxinerama:	xlsxinerama.c
	$(CC) -o xlsxinerama xlsxinerama.c -lX11 -lXinerama

clean:
	rm -f *~
	rm -f xlsoutput
	rm -f xlsxinerama
