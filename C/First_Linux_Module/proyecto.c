#include <linux/module.h> //Libreria que deben llevar todos los modulos
#include <linux/kernel.h> //Libreria que permite el uso de KERN_ALERT

int proyecto_init(void){	//Funcion de inicio o carga del modulo
	printk(KERN_INFO "Cargando Modulo\n");
	return 0; //Regresa el valor 0 (estandard en la elaboracion de modulos) si el modulo se carga correctamente
}

void proyecto_exit(void){ //Funcion de finalizacion de modolu
	printk(KERN_ALERT "Removiendo Modulo\n");
}

module_init(proyecto_init); //Define la funcion de carga del modulo
module_exit(proyecto_exit); //Define la funcion de salida del modulo

MODULE_LICENSE("GPL"); //Define la licencia bajo la que se encuentra el modulo

