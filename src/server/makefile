#build an executable server

CC = gcc
CFLAGS = -g -Wall

server : init.o create_global.o monitor.o session.o itoa.o
	$(CC) $(CFLAGS) -o server init.o create_global.o monitor.o itoa.o session.o -lrt
         
init.o : init.c
	$(CC) $(CFLAGS) -c init.c 
         
create_global.o : create_global.c
	$(CC) $(CFLAGS) -c create_global.c
                  
monitor.o : monitor.c
	$(CC) $(CFLAGS) -c monitor.c
      	
session.o : session.c
	$(CC) $(CFLAGS) -c session.c
	
itoa.o : ../commons/itoa.c
	$(CC) $(CFLAGS) -c ../commons/itoa.c
            
clean: 
	$(RM) server *.o
