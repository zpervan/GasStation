# Gas station simulation #
[![Linux](https://github.com/zpervan/GasStation/actions/workflows/ubuntu_ci.yml/badge.svg?branch=main)](https://github.com/zpervan/GasStation/actions/workflows/ubuntu_ci.yml)

Gas station simulation created with C++ and Bazel in Linux Ubuntu.

## Setup ##

1. Open your terminal and navigate to the root of the project
2. Allow execution permissions to the installation and execute the following:
 ```shell
~/GasStation$ sudo chmod +x Scripts/ubuntu_install.sh
```
3. Now you can execute the installation script and install all needed dependencies. Do this with the following command:
```shell
~/GasStation$ sudo ./Scripts/ubuntu_install.sh
```
4. And you're ready to go

## Run ##

1. Open your terminal and navigate to the root of the project
2. To run the project, execute the following command:
```shell
~/GasStation$ bazel run //Code:main -c dbg # Debug mode OR
~/GasStation$ bazel run //Code:main -c opt # Release mode (preferred)
```
3. And the application output should be visible in the console

## Assignment decomposition ##

We have 2 gas pumps and 10 cars waiting in queue to fill up. 
```
      ___   +-----+         ___    +-----+
     O   O  |  G  |        O   O   |  G  |
     | C |  |  P  |        | C |   |  P  |
     | 0 |  |  0  |        | 1 |   |  1  |
     O___O  +-----+        O___O   +-----+
         
                \               /
                 \             /
                  \    ___    /
                      O   O  
                      | C |  
                      | 3 |  
                      O___O  
                        .
                        .
                        .
                       ___   
                      O   O   
                      | C |  
                      | 9 |  
                      O___O  
```

Each car can fill up once and then goes back to line, which means that it CANNOT fill up again on the other pump in the
same turn. After each fill up is finished, we increase the fill up count for both cars and gas pumps. We do this for 30 
seconds and print out the statistics to the console.
