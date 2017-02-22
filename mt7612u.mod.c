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

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=cfg80211";

MODULE_ALIAS("usb:v0E8Dp7612d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0E8Dp7632d*dc*dsc*dp*icFFiscFFipFFin*");
MODULE_ALIAS("usb:v0E8Dp7662d*dc*dsc*dp*icFFiscFFipFFin*");
MODULE_ALIAS("usb:v0B05p17EBd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B05p180Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v7392pB711d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0846p9053d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v057Cp8503d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "63DF1607FE9D373FA71495B");
