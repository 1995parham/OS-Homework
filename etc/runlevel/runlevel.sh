#!/bin/bash
# In The Name Of God
# ========================================
# [] File Name : runlevel.sh
#
# [] Creation Date : 25-06-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
read input

if [ $input == "L" ]; then
	for service in `ls /etc/init.d`; do
		echo $service
	done
elif [ $input == "on" ]; then
	runlevel=`runlevel | awk '{ print $2 }'`
	echo `ls /etc/rc$runlevel.d`
else
	for i in 0 1 2 3 4 5 6; do
		if `ls /etc/rc$i.d | grep -q [SK][0-9][0-9]$input`; then
			echo -n "$i,"
		fi
	done
fi
