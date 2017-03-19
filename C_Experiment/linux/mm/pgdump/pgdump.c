#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/io.h>
#include <linux/highmem.h>
#include <linux/mmzone.h>

MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 0
#define NR_DEVS 1

int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl (struct file *, unsigned int, unsigned long);

static int myInit(void);
static void myExit(void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myIoctl
};

char *devname;
int majNo;
static dev_t mydev;
struct cdev *my_cdev;

module_param(devname, charp, 0000);

static struct class *mychar_class;
static struct device *mychar_device;

int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "Open successful\n");
	return 0;
}

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

long myIoctl (struct file * fd, unsigned int pid, unsigned long l)
{
	int i;
	int j;
	struct task_struct *task = current;
	struct mm_struct *mmry;
	mmry = task -> mm;
	unsigned long pg_addr, vaddr, *vaddr2, longvar;

	printk(KERN_INFO "IN myIoctl\n\n");

	printk("mm address : %p\n", mmry);
	for(i = 0; i < 1024; i++) {

		if((pg_addr = mmry -> pgd[i].pgd)) {

			pg_addr =  ((pg_addr >> 12)<<12);

			if(pg_addr <= 0x38000000) {
				vaddr = pg_addr + 0xc0000000;
				printk("\nindex : %x\tPGD PA : %p",i, pg_addr);
				printk("\t PGD VA : %p\n", vaddr);
				for(j = 0; j < 1024; j++) {
					if(*(((unsigned long *)(vaddr)) + j) != NULL) {
						longvar =  (unsigned long) (*(((unsigned long *) vaddr ) + j));
						printk("  %p\t", ((longvar>>12)<<12));
					}
				}
			} else {
				vaddr2 = (unsigned long *) kmap((mem_map + (pg_addr >> 12)));
				printk("\nindex : %x\t PGD Entry : %p", i, pg_addr);
				printk("\t user PGD VA : %p", i, vaddr2);
				for(j = 0; j < 1024; j++) {
					if(*(vaddr2 + j) != NULL) {
						longvar =  (unsigned long) (*(( vaddr2 + j)));
						printk("  %p\t", ((longvar >> 12)<<12));
					}
				}
			}
		}
	}

	return 0;
}
static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing character device\n");

	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0) {
		printk(KERN_INFO "Device number allocation failed: %d\n", status);
		goto err;
	}

	printk(KERN_INFO "Major number allocated = %d\n", MAJOR(mydev));
	my_cdev = cdev_alloc();
	if(my_cdev == NULL) {
		printk(KERN_INFO "cdev_alloc failed \n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);
	my_cdev -> owner = THIS_MODULE;

	status = cdev_add (my_cdev, mydev, NR_DEVS);
	if(status) {
		printk(KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}

	mychar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed \n");
		goto err_device_create;
	}

	return 0;

err_device_create:
	class_destroy(mychar_class);

err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree(my_cdev);

err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);

err:
	return ret;

}

static void myExit(void)
{
	printk(KERN_INFO "Exiting the character driver \n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

module_init(myInit);
module_exit(myExit);

