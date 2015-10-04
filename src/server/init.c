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
#include<pthread.h>
#include "../commons/packet.c"

#define BUFF_SIZE 64

extern int session( char *, int * ); 

int main( int argc, char * arg[] )
{

    /*
     * main function
     *
     */

    int fd;

    void * attrib;

    char * client_mutex;
    char * req_read_data;

    char client_id;
    client_id = 0;

    int client_encrypt;

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

    req_read_data = ( char * )attrib + 1;

    while(1){

         while( *req_read_data != '*' ){

              usleep(1);

         }

         attrib = ( void * )( ( char * )attrib + 2 );
         client_encrypt = *( int * )attrib;

         if( client_id == 255 ){

              fprintf( stderr, "unable to service" );

         }

         else( session( &client_id, &client_encrypt ) == 0 ){

              fprintf( stderr, "Unable to allocate memory!" );

         }

         

    }

}
