SRC = \
	absinthe.c

absinthe:
	gcc $(SRC) -o absinthe

clean:
	rm absinthe
