 #include <stdio.h>
 #include <string.h>
 
 struct FILE *archivo;

int main()
{
	char cadena[80],valorx[4],valory[4];
	int x, y;
	
	archivo = fopen("mapa.txt", "r");
	if(archivo == NULL) 
	{
		printf("El archivo no pudo abrirse.");
		return 1;
	}
	
	while( !feof(archivo) ) 
	{
		fgets(cadena, 80, archivo);
		strcpy(valorx, strtok(cadena, ","));
		strcpy(valory, strtok(NULL, ","));
		x = atoi(valorx);
		y = atoi(valory);
		printf("x = %d, y = %d \f", x, y);
	}
	
	fclose(archivo);
    return 0 ;
}
