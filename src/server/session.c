/********************************************************************
 * File Name: session.c
 * ver 0.1
 *
 * This function creates a private session for a client that pings
 * the network.
 *
 * Return values:
 * Returns packet * on success and NULL on failure
 *
 * Author : Rahul Balakrishnan
 *
 * Date : 3-October-2015
 *
 ********************************************************************/

#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include "../commons/packet.c"
#include "../commons/global_packet.c"

extern void itoa( int, char * );

packet * session( int * client_id, int * client_encrypt, int * server_encrypt, global_packet * attrib )
{

    int len;
    
    int fs;   // shared memory index
    
    packet * buff;
    
    itoa ( *client_id, attrib->memory_add );
    
    len = strlen( attrib->memory_add );
    
    while( attrib->client_mutex != '&' ){
    
         usleep(5);
         
    }
    
    attrib->client_mutex = '*';
    
    attrib->memory_add[len] = rand() % 10;
    ++len;
    attrib->memory_add[len] = rand() % 10;
    ++len;
    
    attrib->memory_add[len] = '\0';
    
    fs = shm_open( attrib->memory_add, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );

    if( -1 == fs ){

         fprintf( stderr, "ERROR!! Error creating memory" );
         return NULL;

    }

    if( ftruncate( fs, sizeof( packet ) ) == -1 ){

         fprintf( stderr, "ERROR!! Memory could not be allocated" );
         return NULL;

    }

    buff = ( packet * )mmap( NULL, sizeof( packet ), PROT_READ| PROT_WRITE, MAP_SHARED, fs, 0 );

    if( buff ==  MAP_FAILED ){

         fprintf( stderr, "ERROR!! Could not  map buffer to physical memory" );
         return NULL;

    }
    
    attrib->encrypt = *server_encrypt;
    attrib->req_read_data = '&';
    
    return buff; 

}
