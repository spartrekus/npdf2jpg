
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>





char *fbasenoext(char* mystr)
{
    char *retstr;
    char *lastdot;
    if (mystr == NULL)
         return NULL;
    if ((retstr = malloc (strlen (mystr) + 1)) == NULL)
        return NULL;
    strcpy (retstr, mystr);
    lastdot = strrchr (retstr, '.');
    if (lastdot != NULL)
        *lastdot = '\0';
    return retstr;
}








//////////////////////////////
 void nrun_cmd( char *thefile , char *theout )
 {
       char targetfile[PATH_MAX];
       char cmdi[PATH_MAX];

         //strncpy( targetfile, fbasenoext( thefile ) , PATH_MAX );
         strncpy( targetfile,  thefile  , PATH_MAX );
         //strncat( targetfile , ".pdf" , PATH_MAX - strlen( targetfile ) -1 );
         // ~/tmp$   gs -dNOPAUSE -sDEVICE=jpeg -dFirstPage=1 -sOutputFile=output%d.jpg   -dJPEGQ=100 -r500 -q input.pdf -c quit

         strncpy( cmdi , "   gs -dNOPAUSE -sDEVICE=jpeg -dFirstPage=1 -sOutputFile=\"" , PATH_MAX );
         strncat( cmdi , theout , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "\"-" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "%" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "d.jpg   -dJPEGQ=100 -r350 -q   " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "  \"" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , thefile , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "\"  " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "  -c quit " , PATH_MAX - strlen( cmdi ) -1 );
         printf( "CMD:%s\n", cmdi );
         system( cmdi );
 }






int main( int argc, char *argv[])
{
    int i ; 
    if ( argc >= 2)
    {
          for( i = 1 ; i < argc ; i++) 
          {
	    printf( "%d/%d: %s\n", i, argc-1 ,  argv[ i ] );
            //nrun_cmd( argv[ i ] );
          }

          nrun_cmd( argv[ 1 ] , argv[ 2 ] );
    }
    return 0;
}


