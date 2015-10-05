/********************************************************************
 * File Name: monitor.c
 * ver 0.1
 *
 * This function creates threads for a client that pings
 * the network.
 *
 * Return values:
 * No return
 *
 * Author : Rahul Balakrishnan
 *
 * Date : 5-October-2015
 *
 ********************************************************************/

#include<stdio.h>
#include<time.h>
#include "../commons/packet.c"
#include "../commons/global_packet.c"
#include<unistd.h>


extern packet * session( int *, int *, int *, global_packet * );

void monitor( global_packet * attrib, int server_encrypt, int server_decrypt ){

    int client_id;
    int client_encrypt;
    
    int pid;

    while(1){

         while( attrib->req_read_data != '*' ){

              usleep(1);

         }

         fork();
         
         pid = (int)getpid();
         
         if( pid == 0 ){
         
              packet * buff;
         
              client_encrypt = attrib->encrypt;
         
              client_id = attrib->client_id;
              
              attrib->client_mutex = '&';

              if( ( buff = session( &client_id, &client_encrypt, &server_encrypt , attrib ) ) == NULL ){

                   fprintf( stderr, "Unable to allocate memory!" );

              }
              
         }

         // end of thread part

    }
    
}
