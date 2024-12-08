#include <linux/module.h>    
#include <linux/init.h>        
#include <linux/unistd.h>      
#include <linux/sched.h>       
#include <linux/cred.h>        

MODULE_DESCRIPTION("Kernel module that runs an encryption script");
MODULE_AUTHOR("Joaquin and Garrett");

/*===============================================================================================*/
static int __init simple_driver_init(void)
{
    printk(KERN_NOTICE "Simple-driver: Initialization started\n");

    // Path to your user-space script
    const char *script_path = "/home/joaquin/Documents/final/SimpleLinuxDriver/script";
    
    // Arguments to the script (e.g., running the script with bash)
    char *const args[] = {"/bin/bash", (char *)script_path, NULL};

    // Call the user-space script
    int ret = call_usermodehelper(args[0], args, NULL, UMH_WAIT_PROC);
    if (ret == 0) {
        printk(KERN_NOTICE "User-space script executed successfully.\n");
    } else {
        printk(KERN_WARNING "Failed to execute user-space script. Error code: %d\n", ret);
    }

    return 0;
}

/*===============================================================================================*/
static void __exit simple_driver_exit(void)
{
    printk(KERN_NOTICE "Simple-driver: Exiting\n");
}

module_init(simple_driver_init);
module_exit(simple_driver_exit);
