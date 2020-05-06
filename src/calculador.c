#include <stdio.h>
#include <operaciones.h>

int main( int args, char **argv )
{
	double operador_1 = 12.50;
	double operador_2 = 34.60;

	double resultado = 0.0;

	resultado = sumar( operador_1, operador_2 );

	printf( "Operadores Ingesados [%lf] [%lf] Resultado [%lf]\n", operador_1, operador_2, resultado );

	return 1;
}
