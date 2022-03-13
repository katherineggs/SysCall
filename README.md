# Proyecto: SysCall

Fabricio Juárez

Katherine García

Andrea Reyes

## Detalles del sistema:

Se está utilizando ubuntu 16.0.1 el cual trae el kernel 4.4.1 - generic

Para la implementación del System Call se utilizó la version 4.7.1 del kernel de Linux. 
se descargo de la siguiente direccion:

```
https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/commit/?h=v4.7.1&id=95f15f5ed6e68b479c73da842012108c567c6999
```

## Manejo del kernel

Primero se extrajo el source code del kernel que acabamos de obtener.
```
sudo tar ¡xvf linux-4.7.1.tar.xz -C/usr/src/
```

 Y se cambió el directorio en donde los archivos serán extraidos:
 ```
cd /usr/src/Linux-4.17.4
```

## Definición del System Call
Dentro del directorio anterior, se creó un directorio adicional llamado  ```myCalls```. 

Y se creó el archivo ```balanceo.c``` en donde se ecuentra el código para el System Call. 

Luego, se creó el archivo ```makeFile``` en la misma carpeta, el cuál asegura que el Syscall será compilado e incluido en el source code del kernel.


## Añadiendo la carpeta del System Call al archivo principal
Se regresa al directorio principal y se abre makeFile con el comando:
 ```
gedit Makefile
```

Dentro de éste es añadida la carpeta con el comando:
 ```
core-y += kernel/ mm/ fs/ ipc/ security/ crypto/ block/ mycalls/
```

Para que el compilador se informe sobre el nuevo System Call y en qué carpeta se encuentra.

## Añadiendo el System Call a la tabla de llamadas
Este proyecto se maneja con un sistema de 64 bits:
 ```
cd arch/x86/entry/syscalls/
gedit syscall_64.tbl
```

Al final del documento se añadió la siguiente línea:
 ```
333       common        chequeo_balanceo          sys_chequeo_balanceo
```

## Añadiendo el System Call al header del archivo
Dentro del directorio  ```/Linux-4.17.4``` se corrieron los siguiente comandos:
 ```
cd include/linux/
gedit syscalls.h
```
Y se agrega esta linea de código al archivo:

 ```
asmlinkage long sys_chequeo_balanceo(char *exp;)
```

Esto para definir el prototipo de la función del System Call


## Compilando el Kernel
Requerimientos:

- Librerias para poder compilar:
 ```
sudo apt-get install gcc
sudo apt-get install libncurses5-dev
sudo apt-get install bison
sudo apt-get install flex
sudo apt-get install libssl-dev
sudo apt-get install libelf-dev
sudo apt-get update
sudo apt-get upgrade
```

- Comando para configurar el kernel:
 ```
sudo make menuconfig
```

- Comando para compilar el kernel:
 ``` sudo make ``` 
 
 ## Instalando y actualizando el kernel
 Comandos necesarios para la instalación y actualización de los archivos de configuracion en el Kernel nuevo:
```
sudo make modules_install install

shutdown -r now
```
 
 
## Diagrama de ejecución de un SysCall para el usuario
![Image text](https://github.com/katherineggs/SysCall/blob/main/diagrama%20de%20ejecucion%20de%20syscall%20para%20usuario.jpg)
 
 
 
 
 


