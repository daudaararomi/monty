#include "monty.h"
/**
 * get_op_func - function searches for a match between opcode and text
 * and returns the corresponding function
 * @line: struct containing line contents and line number
 * @stackfile: struct containing all allocated memory
 * Return: pointer to the matching function
 */
void (*get_op_func(linecon_t line, stackfile_t *stackfile))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (check_comment(line))
		return (nop); 
	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.artok[0]) == 0)
		{
			check_push(line, stackfile, ops[i].opcode);
			if (ar.fl == 1 &&
			    strcmp(ops[i].opcode, "push") == 0)
			{
				if (line.artok)
					free(line.artok);
				/*	return (qpush);*/
			}
			free(line.artok);
			return (ops[i].f);
		}
		i++;
	}
       	fprintf(stderr, "L%d: unknown instruction %s\n", line.n,
		line.artok[0]);
	free(line.artok);
	free(stackfile->buffer);
	free_stack(&(stackfile->stack));
	fclose(stackfile->file);
	free(stackfile);
	exit(EXIT_FAILURE);
}
