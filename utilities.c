#include "monty.h"

FILE *file_open(char *argv, char **commands)
{
	FILE *check = NULL;
	check = fopen(argv, "r");

	if (check == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		free(commands);
		exit(EXIT_FAILURE);
	}
	return (check);
}

int isdigit_str(char *token)
{
	int i = 0;

	if (token == NULL)
		return (0);

	if (token[i] == '-')
		i++;

	while (token[i])
	{
		if (isdigit(token[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void frees_struct(stack_t **stack)
{
	free(command_t.instructions);
        free(command_t.line);
        free_stack_t(stack);
        fclose(command_t.store_check);
	exit(EXIT_FAILURE);
}

void free_all(char *line, stack_t *head, char **commands, FILE *check)
{
	free(line);
	free_stack_t(&head);
	free(commands);
	fclose(check);
}