#!/bin/bash

echo "Creating file1.txt with random data...."
dd bs=1 count=10 if=/dev/random of=file1.txt
echo ""

echo "file1.txt status:"
ls -li file1.txt
echo ""

echo "Creating hard link file1.txt <===> file2.txt"
ln file1.txt file2.txt
echo ""

echo "As you can see, there is no diffrence beetween file1.txt file2.txt"
diff -s file1.txt file2.txt
echo ""

echo "Do some change in file2.txt and make diffrence again"
echo "Hello world > file2.txt"
echo "Hello world" > file2.txt
diff -s file1.txt file2.txt
echo ""

echo "Removing file1.txt"
rm file1.txt
echo ""

echo "As you can see file2.txt still exits"
ls -li file2.txt
echo ""

echo "Strance output for [rm file2.txt] is shown in following lines"
strace rm file2.txt
echo ""

echo "Creating file3.txt with random data...."
dd bs=1 count=10 if=/dev/random of=file3.txt
echo ""

echo "Creating soft link file3.txt <----> file4.txt"
ln -s file3.txt file4.txt
echo ""

echo "As you can see inodes is different"
ls -li file*.txt
echo ""

echo "Do some change in file4.txt and make diffrence"
echo "Hello world > file4.txt"
echo "Hello world" > file4.txt
diff -s file3.txt file4.txt
echo ""

echo "Removing file3.txt"
rm file3.txt
echo "As you can see file4.txt become invalid pointer"
cat file4.txt
echo ""

rm file4.txt
