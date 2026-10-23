

dsa: main.c Data.c Stack.c LinkedList.c
	gcc -g main.c Data.c Stack.c LinkedList.c -o dsa

run: dsa
	./dsa

clean:
	rm -f dsa

.PHONY: run clean
