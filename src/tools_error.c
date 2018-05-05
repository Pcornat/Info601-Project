#include "tools_error.h"

#include <stdlib.h>
#include "ncurse.h"
#include <ncurses.h>

/**
 * Wrap for checking ncurses errors.
 *
 * @param return_code the code to check, from the function put à this place.
 * @param message Message to display for the error.
 */
void ncurses_error_err(int return_code, const char* message)
{
	if (return_code == ERR)
	{
		ncurses_stop();
		fprintf(stderr, message);
		exit(EXIT_FAILURE);
	}
}

/**
 * Wrap for checking bad allocation with ncurses started.
 *
 * @param return_ptr Pointer returned from the function.
 * @param message Message to display if there is an error.
 */
void ncurses_error_null(void* return_ptr, const char* message)
{
	if (return_ptr == NULL)
	{
		ncurses_stop();
		fprintf(stderr, message);
		exit(EXIT_FAILURE);
	}
}

/**
 * Wrap to check errno integrated functions with ncurses started.
 *
 * @param return_code Code to check compared to the return from errno integrated functions.
 */
void ncurses_error_errno(int return_code)
{
	if (return_code == -1)
	{
		ncurses_stop();
		perror("Erreur :");
		exit(EXIT_FAILURE);
	}
}

/**
 * Same as above without ncurses.
 */
void error_null(void* return_ptr, const char* message)
{
	if (return_ptr == NULL)
	{
		fprintf(stderr, message);
		exit(EXIT_FAILURE);
	}
}

/**
 * Same as aboce without ncurses.
 */
void error_errno(int return_code)
{
	if (return_code == -1)
	{
		perror("Erreur :");
		exit(EXIT_FAILURE);
	}
}
