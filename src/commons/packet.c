/***************************************
 * File Name : packet.c
 *
 * ver 0.1
 *
 * This contains common structure
 * definitions shared by both client
 * and server.
 *
 * Author : Rahul Balakrishnan
 *
 * Date : 4-October-2015
 *
 *************************************/

#ifndef PACKET
#define PACKET

typedef struct Packet{

    // typical packet structure
    char client_mutex;
    char req_read_data;
    char pkt_id;
    int acc;
    int amount;

}packet;

#endif
