/**
 * The first c program: print "Hello World" to the screen.
 *
 * Explaian:
 * if not include the header stdio.h, error: 'puts' was not declared in this scope.
 * main function is declared to output an int, and take as input an int called argc and a char** called argv
 * puts function is short for put string
 *
 * Complie:
 * gcc -std=c99 -Wall hello_world.c -o hello_world
 * Note:
 * -std=c99 flag to tell the compiler which version or standard of C
 *
 * Debug:
 * gdb
 *
 * Further More:
 * What happens when no main function is given?
 * Use the online documentation to lookup the puts function.
 * Look up how to use gdb and run it with your program.
 *
 * C online Reference: http://en.cppreference.com/w/c
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	puts("Hello World!");
	return 0;
}