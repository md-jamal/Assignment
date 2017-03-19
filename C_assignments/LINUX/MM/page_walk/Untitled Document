#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
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

long myIoctl (struct file * fd, unsigned int pid, unsigned long gvar_addr)
{
	struct mm_struct *mmry;
	struct task_struct *task = current;
	unsigned long paddr, *vaddr, pt_paddr, *pt_vaddr, pf_paddr, *pf_vaddr;
	mmry = task -> mm;
	
	printk("gvar addr : %08x\n", gvar_addr);
	paddr = mmry -> pgd[(gvar_addr >> 22)].pgd;

	if (((paddr = ((paddr >> 12)<<12)) <= 0x38000000)) {
		vaddr = paddr + 0xc0000000;
	} else {
		vaddr = (unsigned long *) kmap((mem_map + (paddr >> 12)));
	}
	
	printk("PGD base addr : %lx\n PGD index addr %lx\n", paddr, paddr + ((gvar_addr >> 22)*4));
	printk("PGD vaddr : %lx\n", vaddr);

	pt_paddr = (unsigned long)(vaddr[((gvar_addr << 10)>>22)]);

	if ((pt_paddr = ((pt_paddr >> 12)<<12)) <= 0x38000000) {
		pt_vaddr = pt_paddr + 0xc0000000;
	} else {
		pt_vaddr = (unsigned long *) kmap((mem_map + (pt_paddr >> 12)));
	}
	printk("PT Physical address : %lx\n", pt_paddr);
	printk("PT virutal address : %lx\n", pt_vaddr);
	
	*((char *)pt_vaddr + ((gvar_addr << 20) >> 20)) = 20;

	printk("g_var : %d", *((int *)gvar_addr));

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

