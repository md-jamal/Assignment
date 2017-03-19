#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
void printb(void);
void printb( void )
{
 printk (KERN_ALERT "hello from module kmod2!");
}

EXPORT_SYMBOL(printb);

static int init(void){
 printk(KERN_ALERT "hello Global Edge!...........kmod2");
 return 0;
}

static void exit(void){
 printk(KERN_ALERT "goodbye Global Edge.....kmod2");
}

module_init(init);
module_exit(exit);
