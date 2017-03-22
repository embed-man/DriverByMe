#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>
#include<linux/gpio.h>
#define LEDMAJOR 0
#define LEDMIN 0
#define LEDNAME "LED1"
#define LED 'K'
#define LED_ON _IO(LED,1)
#define Led_OFF _IO(LED,2)
struct file_operation fop{
open:Led_Open,
read:Led_Read,
write:Led_Write,
ioctl:Led_Ioctl,

}
void Led_Open(strct inode *node,struct file *flag)
{  s3c2410_gpio_cfgpin();
return ;

}

void Led_Off(){
s3c2410_gpio_setpin();

}

void Led_On(){
 s3c2410_gpio_setpin();  
}
void Led_Read(){}
void Led_Write(){}
void Led_Inctl(struct inode *node,struct file *flag,unsigned long cmd,int argv){
 switch(cmd){
 case:LED_ON
  {
     Led_On();
     prink("Led is on!");
     break;
     
     }
 case:LED_OFF
  {
      Led_Off();
      prink("Led is off");
      break;
      }
 
 default{
     printf("your cmd is illegal***********usage:LED_ON or LED_OFF");
 }
 
 
 }

}
struct cdev Led_Dev;
void Led_Device_Register(struct cdev *dev,struct file_operation fops,int min)
{int DvNumber;
DvNumber=MKDEV(major,LEDMIN);
 dev->own=THIS_MODULE;
 dev->fops=&fops;
 cdev_init(dev,&fops);
 cdev_add(DvNumber,1);
}
void __init Led_init(){
   int result;
	struct dev_t dev;
   dev=MKDEV(LEDMAJOR,LEDMIN);
   if(LEDMAJOR){
      result=register_chrdev_region(dev,1,LED1);
   
   }
   else{
     result=alloc_chrdev_region(&dev,0,1,LED1);
     major=MAJOR(&dev);

   }
   if(resutl){
   prink("device number have been successed to registed!");
   
   }
  if(Led_Device_Register(&Lcd_Dev,&fop,LEDMIN)){
  printk("failed to register!");
  
  
  }




}
void __exit Led_exit(){}



module_init(Led_init());
module_exit(Led_exit());
