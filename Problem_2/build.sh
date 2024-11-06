#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/5/2024
### Description:
## Configures the necessary pins and builds "myGpioApp.cpp"

echo "Configuring pins..."
config-pin P9.12 gpio
config-pin P8.16 gpio_pu

echo "Building myGpioApp.cpp..."
g++ ./myGpioApp.cpp ./myGpio.cpp -o myGpioApp
echo "Finished Building"
