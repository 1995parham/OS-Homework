#!/bin/bash
HW_NO=5

rm os_assigment$[HW_NO]_group20.tgz
tar cvfz os_assigment$[HW_NO]_group20.tgz *.c *.h Makefile memory.sh
