#!/bin/bash

### Filename: build.sh
## Author : Sed Centeno
# Date : 11/6/2024
### Description:
## Build file for "myApp.cpp"

echo "Building myApp.cpp..."
g++ ./myApp.cpp ./PhoneBook.cpp ./Record.cpp -o ./myApp
echo "Finished building."
