/****************************************
 * File Name: init.c
 *
 * ver 0.1
 * 
 * This program contains the initial
 * declarations and is a prototype
 * main for server.
 *
 * Author : Rahul Balakrishnan
 *
 * Date : 4-October-2015
 *
 **************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<time.h>

#define BUFF_SIZE 64

struct packet{

    // typical packet structure

    int ser_acc;             // saves the account number of user
    int ser_encrypt;         // saves the encryption key of the client
    char ser_usr_name[20];   // saves the user name of the user

};

int main( int argc, char * arg[] )
{

    /*
     * main function
     *
     */

    int fd;

    void * attrib;
    char * b;

    fd = shm_open( "global", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );

    if( -1 == fd ){

         fprintf( stderr, "ERROR!! Error creating memory" );
         exit(0);

    }

    if( ftruncate( fd, BUFF_SIZE ) == -1 ){

         fprintf( stderr, "ERROR!! Memory could not be allocated" );
         exit(0);

    }

    attrib = mmap( NULL, BUFF_SIZE, PROT_READ| PROT_WRITE, MAP_SHARED, fd, 0 );

    if( attrib ==  ( void * ) -1 ){

         fprintf( stderr, "ERROR!! Could not  map buffer to physical memory" );
         exit(0);

    }

    b = ( char * )attrib;

    while(1){

         while( *b == '*' ){

              usleep(1);

         }

         printf("%c\n", *b);

         *b = '*';

    }

}
