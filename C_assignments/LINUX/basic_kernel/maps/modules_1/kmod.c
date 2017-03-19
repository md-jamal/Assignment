#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 10
#define NR_DEVS 1		//Number of device numbers
#define VM_READ         0x00000001      /* currently active flags */
#define VM_WRITE        0x00000002
#define VM_EXEC         0x00000004

//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);


//Initialization routines
static int myInit(void);
static void myExit(void);
long myUnlocked_ioctl(struct file *, unsigned int, unsigned long);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myUnlocked_ioctl
};

char *devname;
int majNo;
static dev_t mydev;
struct cdev *my_cdev;

module_param(devname, charp, 0000);// to pass command line arguments devname=myChar

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
unsigned long pgoff(unsigned long poff)
{
	unsigned long mask = 0xffff0000;
	unsigned long rt = 0x00000000;
	if(poff & mask)
		return rt;
	else
		return (poff << 12);
}
void path(struct dentry *p_dentry)
{
	if(!strcmp(p_dentry->d_iname,"/")){
		path(p_dentry->d_parent);
		printk(KERN_INFO "%s",p_dentry->d_iname);
	}
}
long myUnlocked_ioctl(struct file *fp, unsigned int pid, unsigned long a)
{
	struct task_struct *ptr;
	struct mm_struct *m_ptr;
	struct vm_area_struct *vm_ptr;
	struct file *fptr = NULL;	
	struct file *fptr_nm = NULL;
	
	printk(KERN_INFO "Ioctl Function Invoked\n");
	printk(KERN_INFO "PID::%d\n",pid);
	ptr = find_task_by_vpid(pid);
	printk(KERN_INFO "COMM::%s\n",ptr->comm);

	m_ptr = ptr-> mm;
	vm_ptr = m_ptr-> mmap;

	fptr_nm = vm_ptr->vm_file;
	
//	printk("File Name::%s",fptr_nm->f_path.dentry->d_iname);

	while(vm_ptr != NULL)
	{
		printk(KERN_INFO "%x-%x %c%c%cp %.8x %ld %s", vm_ptr->vm_start, vm_ptr->vm_end, ((vm_ptr->vm_flags & VM_READ)==1) ? 'r' : '-',((vm_ptr->vm_flags & VM_WRITE)==2) ? 'w' : '-' ,((vm_ptr->vm_flags & VM_EXEC)==4) ? 'x' : '-' ,pgoff(vm_ptr->vm_pgoff), (fptr != NULL) ? fptr->f_inode->i_ino : 0);
		if(vm_ptr->vm_file != NULL){
			path(vm_ptr->vm_file->f_path.dentry);
		}
		vm_ptr = vm_ptr-> vm_next;
	
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

