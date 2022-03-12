#include <linux/kernel.h>
#include "funciones.h"
//SYSCALL_DEFINE2(chequeo_balanceo,char*, exp)
asmlinkage long sys_chequeo_balanceo(char *exp)
{
   

   
    struct sNode* stack = NULL;

   
    while (*exp)
    {
     
        if (*exp == '(' || *exp == '[')
            agregar(&stack, *exp);


       
        if (*exp == ')'
            || *exp == ']') {

           
            if (stack == NULL)
                return 0;

           
            else if (!pareja(sacar(&stack), *exp))
                return 0;
        }
        exp++;
    }

 
    if (stack == NULL)
        return 1;
    else
        return 0;
}
