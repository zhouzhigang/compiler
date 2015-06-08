/**
 * An Interactive Prompt: REPL(read-evaluate-print loop)
 *
 * Write a loop which repeatedly writes out a message, and then waits for some input.
 * To get user input we can use a function called fgets, which reads any input up until a newline.
 * We need somewhere to store this user input. For this we can declare a constantly sized input buffer.
 *
 * Further more:
 * 1) different between fputs and puts?
 *  fputs: int fputs( const char *str, FILE *stream );
 *    Writes given null-terminated character string to the given output stream.
 *    It's a slight variation on puts which does not append a newline character.
 *    http://en.cppreference.com/w/c/io/fputs
 *  puts: int puts( const char *str );
 *    Writes character string str and a newline to stdout
 * 2) what is stdin and stdout
 *  The special file variables are declared in <stdio.h>,
 *  stdin representing input to, stdout representing output from, the command line.
 * 3) difference between getchar, getc, fgetc and fgets?
 *  fgets: char *fgets( char *str, int count, FILE *stream );
 *    Reads at most count - 1 characters from the given file stream and stores them in str.
 *    http://en.cppreference.com/w/c/io/fgets
 *  getchar: int getchar();
 *    Reads the next character from stdin. getc(stdin)
 *  fgetc: int fgetc( FILE *stream );
 *  getc: int getc( FILE *stream );
 *    Reads the next character from the given input stream. getc() may be implemented as a macro.
 * 4) other common io operation?
 *  getchar, getc, fgetc
 *  putchar, putc, fputc
 *  gets(C11), fgets
 *  puts, fputs
 *  scanf, fscanf
 *  printf, fprintf
 * http://en.cppreference.com/w/c/io
 *
 * Compile:
 *  gcc -std=c99 -Wall prompt.c -o prompt
 *
 * Defect: not able to edit input by array keys.
 *  Arrow key will become weired character ^[[D or ^[[C on Unix like systems.
 */
#include <stdio.h>

#define MAX_BUF_SIZE 2048

/**
 * declare a static buffer for user input of maximum size.
 * static keyword make this variable local to this file.
 */
static char input[MAX_BUF_SIZE];

int main(int argc, char const *argv[])
{
	// print version and exit information
	puts("Lispy version 0.0.0.0.1");
	puts("Press Ctrl+c to exit\n");

	// in a never ending loop(run forever until Ctrl+C)
	while (1) {

		// output our prompt, note we use fputs, not puts
		fputs("lispy> ", stdout);

		// Read a line of user input of maxninum size
		fgets(input, MAX_BUF_SIZE, stdin);

		// echo input back to user
		printf("Your input is %s", input);
	}
	return 0;
}
