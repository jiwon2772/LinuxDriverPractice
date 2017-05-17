 #define DEV_NAME "echo"
 11 
  12 // file_operations
   13 // If not, structure initialization may fail
    14 static int __open(struct inode *, struct file *);
	 15 static ssize_t __read(struct file *, char *, size_t, loff_t *);
	  16 static ssize_t __write(struct file *, const char *, size_t, loff_t *);
	   17 static int __release_(struct inode *, struct file *);
	    18 
		 19 static int _major = 0;
		  20 static char _buf[1024];
		   21 static int _open  = 0;
		    22 static int _pos = 0;
			 23 
			  24 //structure containing callbacks
			   25 static struct file_operations fops =
			    26 {
					 27     .open = __open,
					  28     .read = __read,
					   29     .write = __write,
					    30     .release = __release_,
						 31 };
 32 
   // called when module is loaded, similar to main()
    int init_module(void)
	  {
		       _major = register_chrdev(0, DEV_NAME, &fops); // register driver
		        
			         if (_major < 0 )
				      {   
					           printk(KERN_ALERT "%s device registration failed. \n");
					            return _major;
					         }
		         
				      printk(KERN_INFO DEV_NAME " device registered.\n");
			      printk(KERN_INFO "Major: %d\n", _major);
			       
				        return 0;
			    }
			     
				  // called when module is unloaded, similar to destructor in OOP
				   // If cleanup_module does not exist, the module is inserted permanently.
				    void cleanup_module(void)
	  {   
		       unregister_chrdev(_major, DEV_NAME);
		    }

