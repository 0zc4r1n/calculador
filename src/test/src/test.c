#include <stdio.h>
#include <string.h>

#define MAX_BUFF 2048

int main( int args, char **argv )
{
	FILE *fp = NULL;
	char line[MAX_BUFF];
	int status = 0;
	
	char resultado_esperado[] = "Operadores Ingesados [12.500000] [34.600000] Resultado [47.100000]";
	char resultado_obtenido[MAX_BUFF];
	int largo_resultado = 0;

	fp = popen( "./calculador", "r" );

	if( fgets( line, sizeof( line ), fp ) )
	{
		printf( "%s", line );
		
		largo_resultado = strlen( line ) - 1;
		
		sprintf( resultado_obtenido, "%*.*s", largo_resultado, largo_resultado, line );

		if( strncmp( resultado_obtenido, resultado_esperado, largo_resultado ) != 0 )
			status = 1;

		printf( "Esperado [%s]\n", resultado_esperado );
		printf( "Obtenido [%s]\n", resultado_obtenido );
	}
	else
	{
		status = 1;
	}

	printf( "Test 1 [%d] %s\n", status, status?"FAILURE":"SUCCESS" );
	
	pclose(fp);

	return status;
}
