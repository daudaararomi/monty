#include "monty.h"

argvg_t ar = {0, 0};
/**
 *check_comment - checks if line is a comment
 * @linecon: struct containing line contents and line number
 *
 * Return: true if comment, else false
 */
bool check_comment(linecon_t linecon)
{
	if (!linecon.artok[0])
	{
		free(linecon.artok);
		return (true);
	}

	if (linecon.artok[0][0] == '#')
	{
		free(linecon.artok);
		return (true);
	}

	return (false);
}

/**
 * valid_argument - verifies argument is valid
 * @tok: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool valid_argument(char *tok)
{
	unsigned int i;

	if (!tok)
		return (false);

	for (i = 0; tok[i]; i++)
	{
		if (tok[0] == '-')
			continue;
		if (tok[i] < '0' || tok[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * check_push - check if push opcode is being used and sets global
 * argument variable if true
 * @linecon: struct containing line contents and line number
 * @opcode: the opcode to compare
 * @stackfile: struct containing all allocated memory
 *
 * Return: Nothing.
 */
void check_push(linecon_t linecon, stackfile_t *stackfile, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !valid_argument(linecon.artok[1]))
	{
		free(linecon.artok);
		fprintf(stderr, "L%d: usage: push integer\n", linecon.n);
		free(stackfile->buffer);
		free_stack(&(stackfile->stack));
		fclose(stackfile->file);
		free(stackfile);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		ar.ar = atoi(linecon.artok[1]);
}
/**
 * main - opens a monty script file for parsing
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parse_file(file);
	return (EXIT_SUCCESS);
}
