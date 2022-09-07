#include "main.h"

/**
 * cdFunc - execute cd builtin
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int cdFunc(config *build)
{
	register uint count = 0;
	_Bool ableToChange = false;

	count = countArgs(build->args);
	if (count == 1)
		ableToChange = cdToHome(build);
	else if (count == 2 && _strcmp(build->args[1], "-") == 0)
		ableToChange = cdToPrevious(build);
	else
		ableToChange = cdToCustom(build);
	if (ableToChange)
		updateEnviron(build);
	return (1);
}

/**
 * cdToHome - change directory to home
 * @build: input build
 * Return: true on success, false on failure
 */

_Bool cdToHome(config *build)
{
	register int i;
	char *str, *ptr;

	i = searchNode(build->env, "HOME");
	if (i == -1)
	{
		return (true);
	}

