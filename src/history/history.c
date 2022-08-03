#include "minishell.h"

int	history(char *str)
{
//	t_list	*list;

	if (*str)
	{
		add_history(str);
//		add_list_history(str);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
