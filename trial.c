#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
	char exp[100];
	double result;
	scanf("%s", exp);
	char *expresion = exp;
	// Function call
	if (syscall(329,expresion))
	{
	printf("parentesis y brackets estan balanceados \n");
	}
	else
	printf("parentesis y brackets no estan balanceados \n");
	return 0;
}
