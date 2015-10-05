/****************************************
 * File Name: client.c
 *
 * ver 0.1
 * 
 * This program contains the initial
 * declarations and is a prototype
 * main for server.
 *
 * Author : Praveen Kumar
 *
 * Date : 5-October-2015
 *
 **************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>
#include<time.h>

#include<pthread.h>
#include "../commons/global_packet.c"
//this is to include the structure to this program.
#include "../commons/packet.c"
//this is to include the structure to this program.


void get_mutex(char *);
//function to check for shred memory or resource is free to use.
void write_to_memory( global_packet *, int, int );
//function to write to shared memory.
void wait_server_response(global_packet *,int );
//function is used to check for response from server.

int main( int argc, char * arg[] )
{

    /*
     * main function for client process.
     *
     */
    int fd;
    
    int client_id;

    int client_decrypt;

    int client_encrypt;

    int server_encrypt;
    
    global_packet  * ptr_gpkt;
    
    client_id = (int)getpid();
    //getpid() returns the process ID of the calling process and typecast in to integer.
   
    //generate_key(&client_encrypt,&client_decrypt); 
    //generate the encrypt and decrypt key
    
    fd = shm_open( "global",O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );
    //shm_open() creates and opens a new, or opens an existing, POSIX shared memory object.
    if( -1 == fd ){

         fprintf( stderr, "ERROR!! Error in accessing memory" );
         exit(0);

    }

    
    ptr_gpkt = (global_packet * )mmap( NULL, sizeof(global_packet), PROT_READ| PROT_WRITE, MAP_SHARED, fd, 0 );
   // mmap() creates a new mapping in the virtual address space of the calling process and typecast in to the structure pointer. 
    if( ptr_gpkt == MAP_FAILED )
    {
         //check for memory mapping fail
         fprintf( stderr, "ERROR!! Could not  map buffer to physical memory" );
         exit(0);
    }

    get_mutex(&ptr_gpkt->client_mutex);

    write_to_memory(ptr_gpkt, client_encrypt, client_id );

    wait_server_response(ptr_gpkt,client_id);
   
    server_encrypt = read_from_memory(ptr_gpkt);
    printf("server encrypt key is:%d\n",server_encrypt);
}

void get_mutex(char *client_mutex)
{
     while( *client_mutex != '&' )
     /*A Mutex is a lock that we set before using a shared resource and release after using it.
       check shared memory is free to use for client */  
     {

         usleep(5);
     }

     *client_mutex = '*';
     //lock the resource by setting lock to resource
}

void write_to_memory( global_packet * ptr_gpkt, int client_encrypt, int client_id )
{
      //write to shared memory
      ptr_gpkt->encrypt=client_encrypt;
      ptr_gpkt->client_id=client_id;
      ptr_gpkt->req_read_data='*';
 
}

void wait_server_response(global_packet * ptr,int pid)
{
   //waiting for server response
   while(ptr->client_mutex != '*' || ptr->req_read_data != '&' || ptr->client_id != pid)
   {
  
         usleep(5);

   }
}
int read_from_memory(global_packet *ptr)
{
    //read from shared memory
    int server_encrypt;
 
    server_encrypt=ptr->encrypt;
    return server_encrypt;         
}
