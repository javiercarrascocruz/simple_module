/*
  Dos temas importantes aquí:
  1.-licencia de módulo (evitar dudas sobre su posible origen malware)
  2.- __init/__initdata para indicar al kernel que las funciones y variables con
  dichos indicadores se pueden eliminar de RAM tras la inicialización.
  Nótese que function2 no lleva __init porque también se llama desde la función
  de salida y por tanto debe seguir presente en RAM tras la inicialización.
  Como function1 solo se llama desde la función de init, se puede usar __init.
*/
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

__init int ex04_simple_module_function1(void)
{
  printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

int ex04_simple_module_function2(void)
{
  printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

__initdata int count = 5;

__init int ex04_simple_module_init(void)
{
  int index;
  printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
  for(index = 0; index < count; index++)
  {
    printk(KERN_ALERT "Index = %d\n", index);
  }

  ex04_simple_module_function1();
  ex04_simple_module_function2();
  return 0;
}

void ex04_simple_module_exit(void)
{
  printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

  ex04_simple_module_function2();
}

module_init(ex04_simple_module_init);
module_exit(ex04_simple_module_exit);
