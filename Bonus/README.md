
# Bonus Project - Encrypted Loopback Filesystem
In this assignment you will create an encrypted filesystem on a file. You will
need to (i) create a file with random bytes, (ii) create an encrypted loopback
device (AES encryption), (iii) create a filesystem on the loopback device, created
in the previous step, and finally (iv) unassign the loopback device. After
these steps, you have successfully created an encrypted filesystem. Mount the
filesystem and create some files and directories on the encrypted filesystem, and
test that you can remount it with the correct key. Check what happens with a
wrong key.  

Hint1: to be able to use the AES encryption, you need to insert its module:
`modprobe aes`. You may get an error after this command, try to resolve it.  

Hint2: you need to use the `dd` command to create a file, use the `losetup` to
create and detach a filesystem, and the `mkfs` command to format the filesystem.
You can mount the created filesystem using the `mount` command.
