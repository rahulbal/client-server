/********************************************************************
 * File Name: session.c
 * ver 0.1
 *
 * This function creates a private session for a client that pings
 * the network.
 *
 * Return values:
 * Returns 1 on successful creation, and 0 on failure
 *
 * Author : Rahul Balakrishnan
 *
 * Date : 3-October-2015
 *
 ********************************************************************/

#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "../commons/packet"

int s( void * attrib )
{

    b = ( char * )attrib;

    while( *b != '*' ){

         usleep(1);

    }

    attrib = ( void * )( ++( char * )attrib );
    client_id = *( char * )attrib;

    attrib = ( void * )( ++( char * )attrib );
    client_encrypt = *( int * )attrib;

}
