/**
 * An Interactive Prompt: REPL(read-evaluate-print loop)
 *
 * Write a loop which repeatedly writes out a message, and then waits for some input.
 * To get user input we can use a function called fgets, which reads any input up until a newline.
 * We need somewhere to store this user input. For this we can declare a constantly sized input buffer.
 *
 * Defect: not able to edit input by array keys.
 *  Arrow key will become weired character ^[[D or ^[[C on Unix like systems.
 * Solution:
 *  include 'readline' and 'history' in editline' library on Unix like system.
 *  note: header file is history, but the method is add_history
 *
 * Compile:
 *  gcc -std=c99 -Wall prompt2.c -o prompt2
 *
 * Compile Error:
 *  fatal error: editline/readline.h: No such file or directory
 * Solution
 *  Linux: sudo apt-get install libedit-dev
 *  Fedora like: su -c "yum install libedit-dev"
 *
 * Compile Error again:
 *  undefined reference to 'readline'
 *  undefined reference to 'add_history'
 * Solution: compile and link your program with editline
 *  gcc -std=c99 -Wall -ledit prompt2.c -o promot2
 *
 * Further more:
 *  1) why include stdio.h?
 *    use the free function
 *  2) difference between readline and fgets?
 *    the readline function strips the trailing newline character from the input, so we need to add this to our printf function
 *    We also need to delete the input given to us by the readline function using free.
 *    This is because unlike fgets, which writes to some existing buffer, the readline function allocates new memory when it is called.
 *
 * Defect: No such file or directory on Windows.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

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
