//Usb device driver
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>

#define DRV_NAME "custom-usb-driver"
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

static int usb_probe(struct usb_interface *inter, const struct usb_device_id *id) {
    printk(KERN_INFO "Usb drive (%04X:%04X) plugged in.\n", id->idVendor, id->idProduct);
    return 0;
}

static void usb_disconnect(struct usb_interface *inter) {
    printk(KERN_INFO "USB drive removed\n");
}

static struct usb_driver usb_drv = {
    .name = "usb-driver",
    .id-table = usb_device_table,
    .probe = usb_probe,
    .disconnect = usb_disconnect
};

static int __init init_mod(void) {
    printk(KERN_INFO "USB Driver loaded\n");
    
    return usb_register(&usb_drv);
}

static void __exit cleanup_mod(void) {
    printk(KERN_INFO "Remove USB Driver\n");
    usb_deregister(&usb_drv);
}

module_init(init_mod);
module_exit(cleanup_mod);
