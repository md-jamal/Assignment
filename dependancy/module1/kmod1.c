#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
void printa( void );
void printa( void )
{
 printk (KERN_ALERT "hello from module Kmod1!");
}

EXPORT_SYMBOL(printa);

static int init(void){
 printk(KERN_ALERT "hello Global Edge!......Kmod1");
 return 0;
}

static void exit(void){
 printk(KERN_ALERT "goodbye global edge......kmod1");
}

module_init(init);
module_exit(exit);
