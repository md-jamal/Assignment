#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe489130d, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x9d27fc42, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xf2c8354e, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xf6b1454b, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xae823467, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xe1a7238, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x7bdfddde, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0xa3d5c837, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x9f05897c, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x32a2e1c, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xa9ef4d6a, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "A0E79945907E4845B58767E");
