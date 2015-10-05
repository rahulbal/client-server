/***************************************
 * File Name : global_packet.c
 *
 * ver 0.1
 *
 * This contains common packet structure
 * definitions for global communication 
 * shared by both client and server.
 *
 * Author : Praveen Kumar
 *
 * Date : 5-October-2015
 *
 *************************************/
#ifndef GLOBAL_PACKET
#define GLOBAL_PACKET

typedef struct Global_Packet{

    // typical packet structure
    char client_mutex;
    char req_read_data;
    int encrypt;
    int client_id;
    char memory_add[30];

}global_packet;

#endif
