#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
void print(char *a, int l);
int read(char *a);
int sum(char *a, char* b, char * c, int al, int bl); 
int main(void) {
	char a[1000], b[1000], c[1000]; //a and b hold the input numbers and c hold the output number. Each array entry is a digit 
	int al, bl; //for storing the number of digits of the two input numbers
	printf("Enter the first number ");
	al = read(a);
	printf("Enter the second number ");
	bl = read(b);
	int l = sum(a, b, c, al, bl);
	printf("sum = ");
	print(c, l);
	return 0;
}
 
int sum(char *a, char* b, char * c, int al, int bl)
{
	int l = al > bl? al:bl;//l stores the no.of digit of output which may become l+1 due to carry from MSB
        int i = l;
        char carry = 0;
        while(al > 0 && bl > 0)
        {
                char val = a[--al]  + b[--bl] + carry;
                c[i--] = val % 10;
                carry =   val / 10;
        }
        while(al > 0)//If a has more digits than b
        {
                char val = a[--al]  + carry;
                c[i--] = val % 10;
                carry =   val / 10;
        }
        while(bl > 0)//If b has more digits than a
        {
                char val =  b[--bl] + carry;
                c[i--] = val % 10;
                carry =   val / 10;
        }
        c[0] = carry;//Assigning the final carry
	return l+1;//Return the no. of digits of output
} 
 
int read(char *a)
{
	char c;
	int i = 0;
	do
	{
		c = getchar();
	}
	while(isspace(c)); //Reading and discarding any whitespace char typed
	while(isdigit(c))
	{
		a[i++] = c - 48; //getchar returns the ASCII. So, for 1 it returns 49. Subtracting 48, we get the actual int value entered via keyboard 
		c = getchar();
	}
	return i;//Return the no. of digits read
}
 
void print(char *a, int l)
{
	int i;
	if(a[0] != 0)
		printf("%d", a[0]);//If final carry is 0, ignore it
	for(i = 1; i < l; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
