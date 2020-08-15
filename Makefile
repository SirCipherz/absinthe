SRC = \
	absinthe.c \
	db.c \
	utils.c \
	pkg.c

absinthe:
	gcc $(SRC) -o absinthe

clean:
	rm absinthe
