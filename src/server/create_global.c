/********************************************************************
 * File Name: create_global.c
 * ver 0.1
 *
 * This function creates a global session for a client that pings
 * the network.
 *
 * Return values:
 * Returns ( void * ) on successful creation and NULL on failure
 *
 * Author : Rahul Balakrishnan
 *
 * Date : 5-October-2015
 *
 ********************************************************************/

#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include "../commons/global_packet.c"

global_packet * create_global( void ){

    int fd;
    global_packet * attrib;
    
    fd = shm_open( "global", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );

    if( -1 == fd ){

         return NULL;

    }

    if( ftruncate( fd, sizeof(global_packet) ) == -1 ){

         return NULL;

    }

    attrib = mmap( NULL, sizeof(global_packet), PROT_READ| PROT_WRITE, MAP_SHARED, fd, 0 );

    if( attrib ==  MAP_FAILED ){

         return NULL;

    }
    
    return attrib;
    
}
