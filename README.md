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
~/GasStation$ bazel run //Code:main -c opt # Release mode
```
3. And the application output should be visible in the console