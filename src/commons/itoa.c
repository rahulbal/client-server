/********************************************************
 * File Name : itoa.c
 * ver 0.1
 *
 * A program to convert a number in digits to characters 
 * (input range: 1 to 999)
 *
 * Return values:
 * No return modifies the passed input
 *
 * Author : Rahul Balakrishnan
 * 
 * Date : 5-October-2015
 *
 **********************************************************/

void itoa( int, char * );
void revstr( char * );

void itoa( int num, char * alphanum ){

    int temp, i;
    temp = num;
    
    if( num == 0 ){
    
         alphanum[i++] = '0';
         
    }
    
    for( i=0; temp>0 ; i+=1 ){

         alphanum[i] = temp % 10 + '0';
         temp /= 10;
    }

    alphanum[i] = '\0';

    revstr( alphanum );

}

void revstr( char * alphanum )
{

    int i, lim, temp, size;

    for( i=0 ; alphanum[i]!='\0' ; i+=1)    // find length of string
         ;     //Null statement

    size = i;
    lim = size / 2;

    for( i=0 ; i<lim; i+=1 ){
         temp = alphanum[i];
         alphanum[i] = alphanum[size-1-i];
         alphanum[size-1-i] = temp;
    }

}
