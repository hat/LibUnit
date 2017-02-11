#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdio.h>
# include <string.h>

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>

// pid_t	fork(void); creates new process returns process id

 // void (*signal(int sig, void (*func)(int)))(int);
 // or in the equivalent but easier to read typedef'd version:

 // typedef void (*sig_t) (int);
 // sig_t signal(int sig, sig_t func); //sig is the int to what happened during the process
 // 10 bus error 11 seg fault

//MALLOC, FREE, EXIT, FORK, WAIT, WRITE, WAIT.H, SIGNAL.H

# define NUM_TESTS 60

typedef struct	s_test
{
	const char	*name;
	int			(*func)(void);
	int			set;
}				t_test;

void	load_test(t_test *test, const char *name, int (*func)(void));

int		strlen_launcher(t_test *test);

#endif