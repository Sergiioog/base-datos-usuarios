# 📂 Gestión de Empleados con Archivos Binarios (C)

Este proyecto consiste en un programa en lenguaje C que permite gestionar una base de datos de empleados utilizando archivos binarios. El sistema incluye un menú interactivo desde el cual se pueden realizar operaciones como agregar, consultar, modificar y dar de baja empleados sin eliminar físicamente los registros del fichero.

Toda la información se almacena en un archivo binario llamado `empleados.dat`.

---

## 🧱 Estructura del Programa

El programa trabaja con una estructura llamada `Empleado`, que contiene los siguientes campos:

- `id` (entero): identificador único del empleado
- `nombre` (cadena de hasta 50 caracteres)
- `salario` (entero)
- `activo` (entero):
  - `1`: empleado activo
  - `0`: empleado dado de baja (baja lógica)

---

## 📋 Funcionalidades del Menú

Al ejecutar el programa, se muestra un menú con las siguientes opciones:

1. **Agregar empleado**  
   Solicita ID, nombre y salario. Marca el campo `activo` como `1` y guarda el registro al final del archivo.

2. **Listar empleados activos**  
   Muestra solo los empleados cuyo campo `activo` sea igual a `1`.

3. **Buscar empleado por ID**  
   Permite buscar un empleado específico por su ID. Si está activo, se muestra su información.

4. **Modificar salario**  
   Permite modificar el salario de un empleado activo. El registro se sobrescribe en su misma posición dentro del archivo.

5. **Dar de baja por ID**  
   Cambia el campo `activo` a `0`, sin eliminar físicamente el registro.

6. **Salir**  
   Finaliza el programa.

---

## ⚙️ Compilación

Para compilar el programa, abre una terminal y usa el siguiente comando:

```bash
gcc -o empleados empleados.c

