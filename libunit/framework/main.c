#include "libunit.h"

void	load_test(t_test *test, const char *name, int (*func)(void))
{
	static int	i;

	i = 0;
	test[i].name = name;
	test[i].func = func;
	test[i].set = 1;
	test[i + 1].set = 0;
	i = i + 1;
}

void	libunit_header(void)
{
	printf("*****************************\n");
	printf("**     42 - Unit Tests     **\n");
	printf("*****************************\n");
}

int		main(void)
{
	int		i;
	t_test	test[NUM_TESTS];
	int		pid;

	i = 0;
	memset(test, 0, NUM_TESTS);
	pid = 0;
	libunit_header();
	strlen_launcher(test);
	while(test[i].set)
	{
		printf("Name: %s\n", test[i].name);
		if ((pid = fork()) == 0)
		{
			if (test[i].func() == 0)
			{
				printf("\033[32mPASS\033[0m\n");
			}
			else
			{
				printf("\033[31mFAIL\033[0m\n");
			}
			printf("Forking is 0 PID: %d\n", pid);
		}
		else
		{
			printf("Failed PID: %d\n", pid);
			if (pid == -1)
				printf("Error: unable to fork!\n");
			else
			{
				printf("Fork failed PID: %d\n", pid);
			}
		}
		i++;
	}
	return (0);
}