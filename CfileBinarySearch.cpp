#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define blockSize 35


struct filePointer {
       FILE *fp ;
};



bool binary_search( filePointer fp1,int first ,int last, unsigned char value[blockSize] ) {
    int mid = ( first + last ) / 2 ; 
    unsigned char block[blockSize] ;
    
    fseek ( fp1.fp , mid*blockSize , SEEK_SET );
    fread (&block,blockSize-1,1,fp1.fp);
    printf( "ORI==%s==\n", block);
    printf( "CMP==%s==\n", value);
    
    
    if ( memcmp(block,value,blockSize-2)==0 ) return true ;
    else if( first == last ) return false ;
    else if( memcmp(block,value,blockSize)>0 ) 
      return binary_search( fp1, first, mid, value ) ;
    else if( memcmp(block,value,blockSize)<0 )  
      return binary_search( fp1, mid+1, last , value ) ;
    
    
}////////////////////end/////////////////////////////////////
/////////////////////////////////////////////////////////////
 

/* 第一個 C 程式  (hello.c) */
main() {
   printf("hello, This is 3-DES homework \n");
   
   
   
   
   unsigned char  block[ blockSize ] ;
   
   memset (block,0x00,blockSize);
   FILE *fp = fopen( "123.txt", "r" );
   
   fseek(fp, 0, SEEK_END);
   int fileSize = ftell(fp);
   
   fseek ( fp , 0 , SEEK_SET );
   
   fread (&block,blockSize,1,fp);
   unsigned char  showBlock[ blockSize + 1] ;
   memcpy( showBlock,block,blockSize) ;
   showBlock[blockSize] = '\0';
   printf( "first >>%s<<\n", showBlock);
   if ( block[34] == '\r' ) printf( "is  " );
   
   
   
   filePointer fp1 ;
   fp1.fp = fp ;
   
   int blockLength = fileSize/blockSize;
   
   
   unsigned char cmpStr[blockSize] ;
   memcpy( cmpStr,"asdgffdghdlkflkhlfsasddssssdfssss\n\r",blockSize) ;
   cmpStr[33] = 0x0D ;
   cmpStr[34] = 0x0A ;
   
   
   if (binary_search(fp1,0,blockLength-1,cmpStr) )
     printf( "find!" );
   
   
   printf( "fp = %d\n", fp );

   

   fclose( fp );
   

  
   system("pause");
   
   return( 0 );
}




