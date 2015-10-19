#!/bin/sh

umount /media/secure && rmdir /media/secure

echo "Removing file from loopback device /dev/loop1..."
losetup -d /dev/loop1
