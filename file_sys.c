#include "monty.h"

/**
 * tokenline - tokenizes a line of text, storing it in line struct
 * @ln: struct containing line contents and line number
 * @buffer: string of text read from script file
 *
 * Return: Nothing
 */
void tokenline(linecon_t *ln, char *buffer)
{
	unsigned int i;
	char *tok = NULL;

	ln->artok = malloc(sizeof(char *) * 3);
	if (!ln->artok)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	tok = strtok(buffer, " '\n'");
	for (i = 0; tok && i < 2; i++)
	{
		ln->artok[i] = tok;
		tok = strtok(NULL, " \n");
	}

	ln->artok[i] = NULL;
}

/**
 * parse_file - reads and parses file one line at a time
 * @file: the script to be read
 *
 * Return: Nothing
 */
void parse_file(FILE *file)
{
       	stackfile_t *stackfile = NULL;
	linecon_t linecon;

	stackfile = malloc(sizeof(stackfile_t));
	if (!stackfile)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	linecon.n = 0;
	linecon.artok = NULL;

	stackfile->file = file;
	stackfile->stack = NULL;
	stackfile->buffer = NULL;

	while (fgetc(stackfile->file) != -1)
	{
		linecon.n++;
		tokenline(&linecon, stackfile->buffer);
		if (linecon.artok)
			get_op_func(linecon, stackfile)(&(stackfile->stack), linecon.n);
	}

	free(stackfile->buffer);
	free_stack(&(stackfile->stack));
	fclose(stackfile->file);
	free(stackfile);
}
