//Usb device driver
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>

#define VENDOR_NAME "USBest Technology"
#define VENDOR_ID 0x4146
#define PRODUCT_ID 0x2251

static struct usb_device_id usb_device_table[] = {
    {USB_DEVICE(VENDOR_ID, PRODUCT_ID)},
    {}
};

MODULE_DEVICE_TABLE(usb, usb_device_table);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("fermaPrive");
MODULE_DESCRIPTION("Driver for usb device");


static int __init init_mod(void) {
    printk(KERN_INFO "USB Driver loaded\n");
    return 0;
}

static void __exit cleanup_mod(void) {
    printk(KERN_INFO "Remove USB Driver\n");
}

module_init(init_mod);
module_exit(cleanup_mod);
