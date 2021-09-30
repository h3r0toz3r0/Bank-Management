CC = gcc
CFLAGS = -c -Wall -I include
OBJ = BankSystem

all $(OBJ): main.o edit.o erase.o new-acc.o see.o transact.o view-list.o
	$(CC) main.o edit.o erase.o new-acc.o see.o transact.o view-list.o -o $(OBJ)

main.o:
	$(CC) $(CFLAGS) apps/main.c

edit.o:
	$(CC) $(CFLAGS) src/edit.c

erase.o:
	$(CC) $(CFLAGS) src/erase.c

new-acc.o:
	$(CC) $(CFLAGS) src/new-acc.c

see.o:
	$(CC) $(CFLAGS) src/see.c

transact.o:
	$(CC) $(CFLAGS) src/transact.c

view-list.o:
	$(CC) $(CFLAGS) src/view-list.c

exec: all
	./$(OBJ)

clean:
	rm $(OBJ)
	rm *.o
