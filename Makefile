obj-m := ex01_simple_module.o
obj-m += ex02_simple_module_init.o
obj-m += ex03_simple_module_exit.o

obj-m := ex0203_simple_module.o
ex0203_simple_module-objs := ex02_simple_module_init.o ex03_simple_module_exit.o

obj-m := ex04_simple_module.o
ex04_simple_module.objs := ex02_simple_module_init-o ex03_simple_module_exit.o
