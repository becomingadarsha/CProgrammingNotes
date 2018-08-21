/*

     display_stat_structure.c

     Displays the structure from stat().
     Returns 0 for success and -1 for an error condition.
     Written by Matthew Campbell.  (12-15-17)

*/

#ifndef _DISPLAY_STAT_STRUCTURE_C
#define _DISPLAY_STAT_STRUCTURE_C

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/*

     I copied these two macros from an
     include file that came with my compiler.

*/

#define MAJOR( x ) \
	( ( unsigned long int )( ( ( ( x ) >> 31 >>1 ) & 0xfffff000 ) | \
 ( ( ( x ) >> 8 ) & 0x00000fff ) ) )

#define MINOR( x ) \
	( ( unsigned long int )( ( ( ( x ) >> 12 ) & 0xffffff00 ) | ( ( x ) & \
 0x000000ff ) ) )

int display_stat_structure( const struct stat *ptr )
{

     if ( ptr == NULL )
     {
          return ( -1 );  /* Error. */
     }

     /* ID of device containing file: */

     printf( "    st_dev: %llu, major: %lu, minor: %lu\n",
             ptr->st_dev, MAJOR( ptr->st_dev ), MINOR( ptr->st_dev ) );

     /* File inode number: */

     printf( "    st_ino: %llu\n", ptr->st_ino );

     /* Protection bits: */

     printf( "   st_mode: %lo\n", ptr->st_mode );

     /* Number of hard links to this file: */

     printf( "  st_nlink: %lu\n", ptr->st_nlink );

     /* UID of file owner: */

     printf( "    st_uid: %lu\n", ptr->st_uid );

     /* GID of file owner: */

     printf( "    st_gid: %lu\n", ptr->st_gid );

     /* Device id, if special file: */

     printf( "   st_rdev: %llu\n", ptr->st_rdev );

     /* File size in bytes: */

     printf( "   st_size: %lu\n", ptr->st_size );

     /* I/O block size: */

     printf( "st_blksize: %lu\n", ptr->st_blksize );

     /* Number of 512 byte blocks allocated: */

     printf( " st_blocks: %lld\n", ptr->st_blocks );

     /* Last access time: */

     printf( "  st_atime: %s", ctime( &( ptr->st_atime ) ) );

     /* Last modification time: */

     printf( "  st_mtime: %s", ctime( &( ptr->st_mtime ) ) );

     /* Time of last status change: */

     printf( "  st_ctime: %s", ctime( &( ptr->st_ctime ) ) );

     return 0;  /* Success. */
}

void init_stat_structure( struct stat *ptr )
{
     if ( ptr == NULL )
     {
          return;
     }
     ptr->st_dev = 0;
     ptr->st_ino =0;
     ptr->st_mode = 0;
     ptr->st_nlink = 0;
     ptr->st_uid = 0;
     ptr->st_gid = 0;
     ptr->st_rdev = 0;
     ptr->st_size = 0;
     ptr->st_blksize = 0;
     ptr->st_blocks = 0;
     ptr->st_atime = 0;
     ptr->st_mtime = 0;
     ptr->st_ctime = 0;
     return;
}

#endif

/* EOF display_stat_structure.c */