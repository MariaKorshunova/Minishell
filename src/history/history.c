#include "minishell.h"

//t_key_val	*add_history_list(char *str, int *count_cmds)
//{
//	t_key_val	*history_list;
//	int			count;
//
//	count = *count_cmds;
//	history_list = NULL;
////	printf("count: %d\n", count);
////	printf("str: %s\n", str);
//	if (lstnew_add_back_intkey_value(&history_list, count, str))
//	{
//		free(str);
//		return (NULL);
//	}
//	return (history_list);
//}
//
//int	history(char *str, int *count_cmds)
//{
//	t_key_val	*history_list;
//
//	history_list = NULL;
//	if (*str)
//	{
//		add_history(str);
//		history_list = add_history_list(str, count_cmds);
////		if (!ft_strcmp(cmd[0], "history"))
////		{
////			while (history_list)
////			{
//////				printf("lol\n");
//////				printf("key: %d\n", *(int *)history_list->key);
//////				printf("value: %s\n", (char *)history_list->value);
////				history_list = history_list->next;
////			}
////		}
////		printf("key: %d\n", *(int *)history_list->key);
////		printf("value: %s\n", (char *)history_list->value);
//		return (EXIT_SUCCESS);
//	}
//	else
//		return (EXIT_FAILURE);
//}
