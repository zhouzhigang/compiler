/**
 * An Interactive Prompt: REPL(read-evaluate-print loop)
 *
 * Write a loop which repeatedly writes out a message, and then waits for some input.
 * To get user input we can use a function called fgets, which reads any input up until a newline.
 * We need somewhere to store this user input. For this we can declare a constantly sized input buffer.
 *
 * Defect: No such file or directory on Windows.
 * Solotion: use preprocessor
 *  #ifdef, #else, and #endif
 *
 *
 * Compile on Windows:
 *  gcc -std=c99 -Wall prompt3.c -o prompt3
 * Compile on Linux
 *  gcc -std=c99 -Wall prompt3.c -ledit -o prompt3
 *
 * Further more:
 *  1) Change the prompt from lispy> to something of your choice.
 *  2) Change what is echoed back to the user.
 *  3) Add an extra message to the Version and Exit Information.
 *  4) What other patterns can be used with printf.
 *  5) What happens when you pass printf a variable does not match the pattern?
 *  6) What does the preprocessor command #ifndef and #define do?
 *  7) If _WIN32 is defined on windows, what is defined for Linux or Mac?
 */
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#include <string.h>

#define MAX_BUF_SIZE 2048
/**
 * declare a static buffer for user input of maximum size.
 * static keyword make this variable local to this file.
 */
static char buffer[MAX_BUF_SIZE];

/**
 * Fake readline function
 * @param prompt message tip
 */
char* readline(char * prompt) {
	fputs(prompt, stdout);
	fgets(buffer, MAX_BUF_SIZE, stdin);
	char* cpy = malloc(strlen(buffer) + 1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

/**
 * Fake add_history function
 */
void add_history(char* unused) {}

#else

#include <editline/readline.h>
#include <editline/history.h>

#endif

int main(int argc, char const *argv[])
{
	// print version and exit information
	puts("Lispy version 0.0.0.0.1");
	puts("Press Ctrl+c to exit\n");

	// in a never ending loop(run forever until Ctrl+C)
	while (1) {

		// output our prompt, use redline instead of fputs
		char * input = readline("lispy> ");

		// add input to history
		add_history(input);

		// echo input back to user
		printf("Your input is %s\n", input);

		// free retrived input
		free(input);
	}
	return 0;
}
