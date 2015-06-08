/**
 * A quick overview of the basic features of C.
 *
 * Programs
 * A program in C consists of only function definitions and structure definitions.
 * Therefore a source file is simply a list of functions and types.
 *
 * Variables
 * Functions in C consists of manipulating Variables. These are items of data which we give a name to.
 * Every variable in C has an explicit type.
 * Some built in types: void, char, int, short, long, byte, float, double
 *
 * Function Declarations
 * A Function is a computation that manipulates variables, and optionally changes the state of the program.
 * It takes as input some variables and returns some single variable as output.
 *
 * Structure Declarations
 * Structures are used to declare new types*.
 * Structures are several variables bundled together into a single package.
 *
 * Pointers
 * A pointer is a variation on a normal type where the type name is suffixed with an asterisk.
 *
 * Strings
 * In C strings are represented by the pointer type char*.
 * The final character is a special character called the null terminator.
 * Strings can also be declared literally by putting text between quotation marks.
 *
 * Conditionals
 * if else
 * logical operations: || &&
 *
 * Loops
 * while, for
 *
 */
#include <stdio.h>

/**
 * Use a for loop to print out Hello World! five times.
 */
void print_hello_with_for() {
	for (int i = 0; i < 5; i++) {
		puts("Hello World!");
	}
}

/**
 * Use a while loop to print out Hello World! five times.
 */
void print_hello_with_while() {
	int i = 0;
	while (i < 5) {
		puts("Hello World!");
		i++;
	}
}
/**
 * Declare a function that outputs Hello World! n number of times. Call this from main.
 */
void print_hello_n_times(int n) {
	for (int i = 0; i < n; i++) {
		puts("Hello World!");
	}
}

int main(int argc, char const *argv[])
{
	print_hello_n_times(5);
	return 0;
}