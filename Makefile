CC = gcc
CFLAGS = -c -Wall -I include
OBJ = BankSystem

all $(OBJ): main.o func-edit.o func-erase.o func-create.o func-see.o func-transact.o func-view.o struct-cust.o func-files.o
	$(CC) main.o func-edit.o func-erase.o func-create.o func-see.o func-transact.o func-view.o struct-cust.o func-files.o -o $(OBJ)

main.o:
	$(CC) $(CFLAGS) apps/main.c

func-edit.o:
	$(CC) $(CFLAGS) src/func-edit.c

func-erase.o:
	$(CC) $(CFLAGS) src/func-erase.c

func-create.o:
	$(CC) $(CFLAGS) src/func-create.c

func-see.o:
	$(CC) $(CFLAGS) src/func-see.c

func-transact.o:
	$(CC) $(CFLAGS) src/func-transact.c

func-view.o:
	$(CC) $(CFLAGS) src/func-view.c

struct-cust.o:
	$(CC) $(CFLAGS) src/struct-cust.c

func-files.o:
	$(CC) $(CFLAGS) src/func-files.c

exec: all
	./$(OBJ)

clean:
	rm *.o
	rm $(OBJ)
