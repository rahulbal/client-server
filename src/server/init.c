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
#include "../commons/packet.c"

#define BUFF_SIZE 64

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

    while( *b != '*' ){

         usleep(1);

    }

    attrib = ( void * )( ++( char * )attrib );
    client_id = *( char * )attrib;

    attrib = ( void * )( ++( char * )attrib );
    client_encrypt = *( int * )attrib;

}
