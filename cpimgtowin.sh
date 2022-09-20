#!/bin/sh

echo "copy build images out by ldx"
cp -v LINUX/android/out/target/product/sdm660_64/abl.elf ./out
#cp -v LINUX/android/out/target/product/sdm660_64/boot-debug.img ./out
cp -v LINUX/android/out/target/product/sdm660_64/boot.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/dtb.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/dtbo.img ./out
cp -v LINUX/android/out/target/product/sdm660_64/mdtp.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/metadata.img ./out
cp -v LINUX/android/out/target/product/sdm660_64/persist.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/prebuilt_dtbo.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/product.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/ramdisk-debug.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/ramdisk.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/ramdisk-recovery.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/recovery.img ./out
#cp -v LINUX/android/out/dist/super.img ./out
#cp -v LINUX/android/out/dist/super_empty.img ./out
cp -v LINUX/android/out/target/product/sdm660_64/system.img ./out
cp -v LINUX/android/out/target/product/sdm660_64/userdata.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/vbmeta.img ./out
#cp -v LINUX/android/out/target/product/sdm660_64/vbmeta_system.img ./out
cp -v LINUX/android/out/target/product/sdm660_64/vendor.img ./out
 
echo "all done,bye"

#echo "copy images to usb for download===================>"
#cp -av ./out  /media/dexun/UDISK/

#echo "finishedd copy images to usb,now sync"
sync

exit
