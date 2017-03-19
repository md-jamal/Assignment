#wget http://www.kernel.org/pub/linux/kernel/v2.4/linux-2.4.19.tar.gz
#tar -zxvf linux-2.4.19.tar.gz
#cd linux-2.4.19


#make menuconfig    //First step 

#make dep

#make bzImage

make && make modules && make modules_install && make install; update-grub

#make O=build bzImage && make  O=build modules && make O=bzImage modules_install && make O=bzImage install; update-grub




#To re-configure the kernel

#make mrproper
#make menuconfig
#make dep
#make clean
#make bzImage
#make modules
#make modules_install
#make install
#update grub
