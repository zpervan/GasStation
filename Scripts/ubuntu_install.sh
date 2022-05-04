#!/usr/bin/env bash

echo "This script installs all needed dependencies."
echo "Run this script with sudo privileges in order to install the libraries"

if [[ `whoami` != root ]]; then
    echo -e " -- \e[31mPlease run this script as root or using sudo\e[0m"
    exit
fi

echo -e " -- \e[33mFetching updates\e[0m"
apt update -qq

echo -e " -- \e[33mInstalling Bazel\e[0m"
apt install apt-transport-https curl gnupg
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg
mv bazel.gpg /etc/apt/trusted.gpg.d/
echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
apt update
apt install bazel

echo -e " -- \e[33mInstalling dependencies\e[0m"
apt install -y build-essential clang