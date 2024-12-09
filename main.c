#include <linux/module.h>
#include <linux/init.h>
#include <linux/unistd.h>
#include <linux/sched.h>
#include <linux/cred.h>

MODULE_DESCRIPTION("Kernel module that runs an encryption script");
MODULE_AUTHOR("Joaquin and Garrett");
MODULE_LICENSE("GPL");

static int __init simple_driver_init(void)
{
    printk(KERN_NOTICE "Simple-driver: Initialization started\n");

    // Path to user-space script
    const char *script_path = "/home/joaquin/Documents/final/SimpleLinuxDriver/script.sh";
    
    // Arguments to the script (running the script with bash)
    char *args[] = {"/bin/bash", (char *)script_path, NULL};
    
    // Environment variables
    char *envp[] = {
        "HOME=/home/joaquin",
        "PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin",
        NULL
    };
    
    // Call the user-space script and wait for it to finish
    int ret = call_usermodehelper(args[0], args, envp, UMH_WAIT_EXEC);

    if (ret == 0) {
        printk(KERN_NOTICE "User-space script executed successfully.\n");
    } else {
        printk(KERN_WARNING "Failed to execute user-space script. Error code: %d\n", ret);
    }

    return 0;
}

static void __exit simple_driver_exit(void)
{
    printk(KERN_NOTICE "Simple-driver: Exit\n");
}

module_init(simple_driver_init);
module_exit(simple_driver_exit);

