#include <sys/fcntl.h>
#include "minishell.h"

t_exec	**ft_example(t_exec **exec)
{
	(*exec) = (t_exec *)malloc (8 * sizeof(t_exec *));
	(*exec)->cmd = (char **)malloc (4 * sizeof(char **));
	(*exec)->infile = (char **)malloc (2 * sizeof(char **));
	(*exec)->outfile = (char **)malloc (2 * sizeof(char **));
	(*exec)->cmd[0] = "echo";
	(*exec)->cmd[1] = "-n";
	(*exec)->cmd[2] = "hello";
	(*exec)->infile[0] = "infile";
	(*exec)->outfile[0] = "outfile";
//	printf("cmd: %s\n", (*exec)->cmd[0]);
	return (exec);
}


int	executor(t_exec *exec, t_data *envp)
{
	pid_t	pid;

	(void)envp;
//	printf("envp: %s\n", envp->env_arr[0]);
	ft_example(&exec);
//	printf("cmd: %s\n", exec->cmd[1]);
	printf("I am: %d\n", (int) getpid());
	pid = fork();
	printf("Fork returned: %d\n", (int) pid);
	if (pid < 0) // error occurred
		perror("Fork failed");
	if (pid == 0) // child process
	{
		printf("I am the child with pid %d\n", (int) getpid());
		printf("Child process is exiting\n");
		exit(0);
		// prepare
		// builtin
	}
	/* parent process */
	printf("Parent waiting for the child process to end\n");
	wait(NULL);
	printf("Parent process is exiting\n");
	return (EXIT_SUCCESS);
}

//int	executor(t_exec	*exec, )
//{
//	int	pid;
//
//
//	// save in/out
//	int	tmpin = dup(0);
//	int	tmpout = dup(1);
//
//	// set the initial input
//	int	fdin;
//	if (exec->infile)
//	{
//		fdin = open(exec->infile, O_READ);
//	}
//	else
//	{
//		// use default input
//		fdin = dup(tmpin);
//	}
//	int	ret;
//	int	fdout;
//	for (i = 0; i < numsimplecommands; i++)
//	{
//		// redirect input
//		dup2(fdin, 0);
//		close(fdin);
//		// setup output
//		if (i == numsimplecommands - 1)
//		{
//			// Last simple command
//			if (outfile)
//			{
//				fdout = open(outfile, x, y);
//			}
//			else
//			{
//				// Use default output
//				fdout = dup(tmpout);
//			}
//		}
//		else
//		{
//			// Not last
//			// simple command
//			// create pipe
//			int	fdpipe[2];
//			pipe(fdpipe);
//			fdout = fdpipe[1];
//			fdin = fdpipe[0];
//		} // if/else
//
//		// Redirect output
//		dup2(fdout, 1);
//		close(fdout);
//
//		// Create child process
//		ret = fork();
//		if (ret == 0)
//		{
//			execvp(scmd[i].args[0], scmd[i].args);
//			perror(execvp);
//			_exit(1);
//		}
//	} // for
//
//	// restore in/out defaults
//	dup2(tmpin, 0);
//	dup2(tmpout, 1);
//	close(tmpin);
//	close(tmpout);
//
//	if (!background)
//	{
//		// Wait for last command
//		waitpid(ret, NULL);
//	}
//	return (EXIT_SUCCESS);
//}