/* Desarrollar un programa que gestione una base de datos de empleados utilizando archivos binarios. 

El sistema deberá permitir el almacenamiento, consulta, modificación y baja lógica de empleados sin eliminar físicamente los registros del
fichero.

Especificaciones

1. Estructura de datos
Define una estructura llamada Empleado con los siguientes campos:
- Id: entero
- Nombre: cadena de caracteres con 50 caracteres como máximo.
- Salario
- Activo: 1 activo, 2 dado de alta.

2. Nombre del archivo
El archivo binario se llamará empleados.dat y contendrá los registros de los
empleados.

3. Menú principal
El programa debe presentar un menú interactivo con las siguientes opciones:
	
	1. Agregar empleado
		Solicita los datos del empleado al usuario (ID, nombre, salario), marca el
		campo activo como 1, y guarda el registro en el archivo binario al final del
		mismo.

	2. Listar empleados activos
		Recorre el archivo y muestra únicamente aquellos registros con el campo activo == 1.
	
	3. Buscar empleado por ID
		Permite ingresar un ID y muestra la información del empleado si existe y está activo. 
		Si no se encuentra o está dado de baja, se debe notificar al usuario.
	
	4. Modificar salario
		Busca un empleado por su ID. Si está activo, permite modificar su salario. El
		cambio debe realizarse sobrescribiendo el registro en su misma posición en el
		archivo.

	5. Dar de baja por ID
		Cambia el campo activo del empleado a 0, sin eliminar físicamente el
		registro del archivo. Esta operación también debe hacerse sobrescribiendo
		el registro en su misma posición.
	
	6. Salir
	
	Restricciones y recomendaciones
• Utiliza las funciones estándar de manipulación de archivos binarios en C:
fopen, fread, fwrite, fseek, ftell, rewind, y fclose.
• El archivo debe abrirse en modo "r+b" (lectura y escritura binaria). Si no
existe, debe crearse en modo "w+b".
• Asegúrate de validar correctamente las entradas del usuario.
• No se permite el uso de bibliotecas externas excepto stdio, stdlib y string.
Todo el almacenamiento debe realizarse exclusivamente en el archivo
binario.*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
3. Menú principal
El programa debe presentar un menú interactivo con las siguientes opciones:
	
	1. Agregar empleado
		Solicita los datos del empleado al usuario (ID, nombre, salario), marca el
		campo activo como 1, y guarda el registro en el archivo binario al final del
		mismo.

	2. Listar empleados activos
		Recorre el archivo y muestra únicamente aquellos registros con el campo activo == 1.
	
	3. Buscar empleado por ID
		Permite ingresar un ID y muestra la información del empleado si existe y está activo. 
		Si no se encuentra o está dado de baja, se debe notificar al usuario.
	
	4. Modificar salario
		Busca un empleado por su ID. Si está activo, permite modificar su salario. El
		cambio debe realizarse sobrescribiendo el registro en su misma posición en el
		archivo.

	5. Dar de baja por ID
		Cambia el campo activo del empleado a 0, sin eliminar físicamente el
		registro del archivo. Esta operación también debe hacerse sobrescribiendo
		el registro en su misma posición.
	
	6. Salir


*/


typedef struct {
	int id;
	char nombre[50]; 
	int salario;
	int activo;
	
} Empleado;

int existe_archivo(Empleado empleado);
int agregar_emplado(Empleado empleado);
int leer_archivo();
int buscar_empleado_ID(int idEmpleado);

int existe_archivo(Empleado empleado){
    FILE* empleadosFile = fopen("empleados.dat", "rb");

    if(empleadosFile != NULL){
        fclose(empleadosFile);
        agregar_emplado(empleado);  
        return 1;
    } else {
        empleadosFile = fopen("empleados.dat", "wb");
		
        if (empleadosFile != NULL) {
            fclose(empleadosFile);
            printf("empleadosFile creado con exito \n");
            agregar_emplado(empleado); 
			
        } else {
            printf("Error creando empleados.dat\n");
            return 1;
        }
    }

    return 0;
}


int agregar_emplado(Empleado empleado){
	
	FILE* empleadosFile = fopen("empleados.dat", "r+b") ;
	fseek(empleadosFile, 0, SEEK_END);
	
	fwrite(&empleado, sizeof(Empleado), 1, empleadosFile); 
	fclose(empleadosFile);
	printf("Empleado anadido con exito\n");
	return 0;
}

int leer_archivo() {
    Empleado empleado;  
    FILE* empleadosFile = fopen("empleados.dat", "rb");

    if (empleadosFile == NULL) {
        printf("Error al abrir el archivo empleados.dat\n");
        return 1;
    }

    int encontrados = 0;

    while (fread(&empleado, sizeof(Empleado), 1, empleadosFile) == 1) {
        if (empleado.activo == 1) {
            printf("---------------------------------------\n");
            printf("Id del usuario: %d\n", empleado.id);
            printf("Nombre del usuario: %s\n", empleado.nombre);
            printf("Salario del usuario: %d\n", empleado.salario);
            printf("---------------------------------------\n");
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No hay empleados activos.\n");
    }

    fclose(empleadosFile);
    return 0;
}

int buscar_empleado_ID(int idEmpleado){
	
	Empleado empleado;
	FILE *empleadosFile = fopen("empleados.dat", "rb");
	
	if(empleadosFile == NULL){
		printf("Error al leer el archivo \n");
		return 1;
	}
	
	/*while(fread(){
		
	}*/
	
	
	return 0;
}


int main(int argc, char* argv[]){
	
	FILE* empleadosFile;
	Empleado empleado;
	int respuestaUsuario;
	int respuestaUsuarioInsercion;
	int idEmpleado;
	
	printf("Bienvenido a la BBDD de empleados, seleccione una de estas opciones: \n");
	
	while(1){
		
		printf("----------------------------------------------------------------------- \n");
		printf("1. Agregar empleado \n");
		printf("2. Listar empleados activos \n");
		printf("3. Buscar empleado por ID \n");
		printf("4. Modificar salario \n");
		printf("5. Dar de baja por ID \n");
		printf("6. Salir \n");
		printf("----------------------------------------------------------------------- \n");
		
		scanf("%d", &respuestaUsuario);
		
		switch(respuestaUsuario){
		
		case 1 :
			
			printf("Introduza por favor, los datos del usuario: (ID, nombre, salario) \n");
			scanf("%d %s %d", &empleado.id, &empleado.nombre, &empleado.salario);
			empleado.activo = 1;
			existe_archivo(empleado);
			break;
			
		case 2 :
		
			printf("Estos son los usuarios activos en la bbdd: \n");
			leer_archivo();
			break;
		
		case 3 :
				
			/*
			3. Buscar empleado por ID
				Permite ingresar un ID y muestra la información del empleado si existe y está activo. 
				Si no se encuentra o está dado de baja, se debe notificar al usuario.
			
			*/
			
			printf("Ingrese el ID numerico del empleado que quieres buscar: \n");
			scanf("%d", &idEmpleado); 
			buscar_empleado_ID(idEmpleado);

		
			printf("Opcion 3 seleccionada \n");
			break;
			
		case 4 :
		
			printf("Opcion 4 seleccionada \n");
			break;
			
		case 5 :
		
			printf("Opcion 5 seleccionada \n");
			break;
			
		case 6 :
		
			printf("Opcion 6 seleccionada \n");
			return 0;
			
		default:
		
			printf("Opcion no valida \n");
	}
		
	}
	
	

	return 0;
}