#!/bin/bash

cd LINUX/android
#sed -i "85c FILE_NAME_TAG := eng.\$(BUILD_USERNAME)" build/make/core/main.mk
#sed -i '85,85s/^/  /' build/make/core/main.mk
source build/envsetup.sh
lunch 
./clean_edk2_env.sh
cd ../../
./build.sh all
./cpn_all
