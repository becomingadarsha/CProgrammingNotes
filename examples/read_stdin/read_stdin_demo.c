/*

     read_stdin_demo.c
     This file offers a simple example of how to use read_stdin().
     Written by Matthew Campbell.

*/

/* Make sure read_stdin.c is in the same directory. */

#include <stdlib.h>
#include "read_stdin.c"

int main( void )
{
     char buffer[ 1025 ];
     int length, ret, size;

     ret = read_stdin( buffer, 1024, "prompt >> " );
     if ( ret != 0 )
     {
          printf( "Something went wrong.  Error: %s.\n",
                  strerror( errno ) );
          return 1;
     }
     printf( "Received: \"%s\"\n", buffer );
     return 0;
}

/* EOF read_stdin_demo.c */