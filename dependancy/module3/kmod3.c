#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

extern void printa(void);
extern void printb(void);

static int init(void){
 printa();
 printb();
 return 0;
}

static void exit(void){
 printk(KERN_ALERT "goodbye Global Edge.....kmod3");
}

module_init(init);
module_exit(exit);
