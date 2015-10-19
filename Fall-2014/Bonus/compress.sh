#!/bin/bash
HW_NO=Bonus

rm os_assigment$[HW_NO]_9231058.tgz
tar cvfz os_assigment$[HW_NO]_9231058.tgz mount.sh umount.sh make.sh 1.img
