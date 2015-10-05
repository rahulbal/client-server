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
#include "../commons/global_packet.c"

//extern void generate_key( int *, int * );
void generate_key( int * server_encrypt, int * server_decrypt ){

    *server_encrypt = 1;
    *server_decrypt = 1;
    
}
     
extern void * create_global( void );
extern void monitor( global_packet *, int, int );

int main( int argc, char * arg[] )
{

    /*
     * main function
     *
     */

    
    global_packet * attrib;

    int server_encrypt;
    int server_decrypt;
    
    generate_key( &server_encrypt, &server_decrypt );
    // generate the encryption-decryption keys
   
    attrib = create_global();
    
    monitor( attrib, server_encrypt, server_decrypt );
    
    return 0;

}
