/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 03:11:50 by refrain           #+#    #+#             */
/*   Updated: 2022/09/19 14:10:01 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static  void   swap(char ***lhs, char ***rhs)
{
   char   **tmp;

   tmp = *lhs;
   *lhs = *rhs;
   *rhs = tmp;
}

void   bubble_sort(char **arr)
{
   int    i;
   int    j;
   int size;

   size = 0;
   while (*(arr + size) != NULL)
      size++;
   i = 0;
   while (i < size)
   {
      j = 0;
      while (j < size - i - 1)
      {
         if (strcmp(arr[j], arr[j + 1]) > 0)
            swap(&arr[j], &arr[j + 1]);
         j++;
      }
      i++;
   }
}

// int	ft__export(char **cmd, t_data *data)
// {
// 	int		i;
// 	char	**array;

// 	if (!cmd[1])
// 	{
	
// }
// 	while (com->arg[++i])
// 	{
// 		if (check_arg_of_export(com->arg[i]))
// 		{
// 			array = split_for_export(com->arg[i]);
// 			if (!array)
// 				return (1);
// 		
// 			free_array(array);
// 		}
// 		else
// 		{
// 			print_export_error
// 			return (1);
// 		}
// 	}
// 	return (0);
// }
