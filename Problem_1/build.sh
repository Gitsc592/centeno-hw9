#!/bin/bash

### Filename : build.sh
## Author : Sed Centeno
# Date : 11/5/2024
### Description:
## Configures the necessary pins and builds "PushBtn.cpp"

echo "Configuring pins..."
config-pin P9.12 gpio
config-pin P8.16 gpio_pu

echo "Building PushBtn.cpp..."
g++ ./PushBtn.cpp -o PushBtn
echo "Finished Building"
