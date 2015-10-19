#!/bin/sh

echo "Inserting file into loopback device /dev/loop1..."
losetup -d /dev/loop1
losetup -e aes /dev/loop1 1.img

mkdir -p /media/secure && mount -o loop,encryption=aes 1.img /media/secure
