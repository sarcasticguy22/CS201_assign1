#include<stdio.h>
#include<string.h>
#include<math.h>
int Pow ( int a , int b ) {  
    int power = 1 , i ;  
    for ( i = 1 ; i <= b ; + + i ) {  
        power = power * a ;  
    }  
    return power ;  
}  
int main ( ) {  
    long long int base , exponent ;  
  
    printf ( " enter Base : " ) ;  
    scanf ( " % d " , & base ) ;  
  
    printf ( " enter Power : " ) ;  
    scanf ( " % d " , & exponent ) ;  
  
    printf ( "  % d ^ % d = % d " , base , exponent , Pow ( base , exponent ) ) ;  
}
