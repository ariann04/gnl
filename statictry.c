#include <stdio.h>
int funcion() 
{
	    static int número = 5; /* Variable estática */
		    número++;               /* Mantiene el valor de la ejecución anterior */
			    return número;
}
int main() 
{
	    /* Imprime el resultado de dos invocaciones a la función */
	    printf("%d\n", funcion()); /* Imprime el número 11 */
		    printf("%d\n", funcion()); /* ¡Imprime el número 12! */
			    return 0;
}

