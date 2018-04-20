#include "tools_error.h"

#include <stdlib.h>
#include <ncurses.h>
#include "ncurses.h"

void ncurses_error_err(int return_code, const char *message)
{
	if (return_code == ERR)
	{
		ncurses_stop();
		fprintf(stderr, message);
		exit(EXIT_FAILURE);
	}
}

void ncurses_error_null(void *return_ptr, const char *message)
{
	if (return_ptr == NULL)
	{
		ncurses_stop();
		fprintf(stderr, message);
		exit(EXIT_FAILURE);
	}
}

void ncurses_error_errno(int return_code)
{
	if (return_code == -1)
	{
		ncurses_stop();
		perror("Erreur :");
		exit(EXIT_FAILURE);
	}
}

void error_null(void* return_ptr, const char* message)
{
	if (return_ptr == NULL)
	{
		fprintf(stderr, message);
		exit(EXIT_FAILURE);
	}
}

void error_errno(int return_code)
{
	if (return_code == -1)
	{
		perror("Erreur :");
		exit(EXIT_FAILURE);
	}
}
