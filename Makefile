#obj-m indica el objeto módulo que se va a crear.
# := es asignación e invalida asignaciones anteriores.
# += incrementa la asignación para crear más módulos.

obj-m := ex01_simple_module.o
obj-m += ex02_simple_module_init.o
obj-m += ex03_simple_module_exit.o

# asignación que invalida lo anterior.
obj-m := ex0203_simple_module.o
#módulo compuesto de dos objetos, se indica así (los dos objetos se crean
#automáticamente al compilar de sus respectivos códigos fuente)
ex0203_simple_module-objs := ex02_simple_module_init.o ex03_simple_module_exit.o

#asignación que invalida lo anterior.
obj-m := ex01_simple_module.o
obj-m += ex04_simple_module.o
