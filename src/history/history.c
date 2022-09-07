#include "minishell.h"

t_key_val	*add_history_list(char *str, int *count_cmds)
{
	(void)str;
	(void)count_cmds;
	t_key_val	*history_list;

	history_list = NULL;
//	if (lstnew_add_back_intkey_value(history_list, count_cmds, str))
//	{
//		free(str);
//		return (NULL);
//	}
	return (history_list);
}

int	history(char *str, int *count_cmds)
{
	t_key_val	*history_list;

	history_list = NULL;
	if (*str)
	{
		add_history(str);
		history_list = add_history_list(str, count_cmds);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
