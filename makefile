var:=$(patsubst %.c, %.o, $(wildcard *.c))
main.exe:$(var)
	gcc -o $@ $^
clean:
	rm *.exe *.o