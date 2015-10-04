/****************************************
 * File Name: client.c
 *
 * ver 0.1
 * 
 * This program contains the initial
 * declarations and is a prototype
 * main for client
 *
 * Author : Rahul Balakrishnan
 *
 * Date : 4-October-2015
 *
 **************************************/

#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>

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

    char ch;

    void * attrib;
    char * b;

    fd = shm_open( "global", O_RDWR , 0666 );

    if( -1 == fd ){

         fprintf( stderr, "ERROR!! Cannot allocate memory" );

    }

    attrib = mmap( NULL, BUFF_SIZE, PROT_READ| PROT_WRITE, MAP_SHARED, fd, 0 );

    if( attrib ==  ( void * ) -1 ){

         fprintf( stderr, "ERROR!! Could not  map buffer to physical memory" );

    }

    ch ='a';
    b = ( char * )attrib;

    while(1){

         *b = ch;

         while( *b != '*' ){

              usleep(1);

         }

         if( ch == 'z' ){

              ch = 'a';

         }

         else{

              ch++;

         }

    }

}
