#!/bin/bash

# Please run this script with root permission !!! :-) Have fun...

echo "Inserting required modules..."
modprobe cryptoloop
#modprobe aes

echo "Creating file..."
dd if=/dev/urandom of=1.img bs=1M count=50

echo "Inserting file into loopback device /dev/loop1..."
losetup -d /dev/loop1
losetup -e aes /dev/loop1 1.img

echo "Creating ext2 file system on loopback device /dev/loop1..."
mkfs.ext2 -L "PARHAM AES" /dev/loop1

echo "Removing file from loopback device /dev/loop1..."
losetup -d /dev/loop1
