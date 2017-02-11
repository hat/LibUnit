//#include "101_basic_tests.h"
#include "libunit.h"

int		basic_test(void)
{
	if (strlen("Hello") == strlen("Hello"))
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int		null_test(void)
{
	char	*str;

	str = 0;
	if (strlen(str) == strlen(str))
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int		strlen_launcher(t_test *test)
{
	puts("STRLEN:");
	load_test(test, "Basic test", &basic_test);
	//load_test(test, "NULL Test", &null_test);
	//load_test(&testlist, "Bigger string test", &bigger_str_test); // won't be loaded
	return(0/*launch_tests(&test)*/);
}