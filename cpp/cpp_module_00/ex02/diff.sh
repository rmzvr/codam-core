#!/bin/sh

sed 's/^\[[0-9]\{8\}_[0-9]\{6\}\] //' "$1" > /tmp/file1.txt
sed 's/^\[[0-9]\{8\}_[0-9]\{6\}\] //' "$2" > /tmp/file2.txt

diff /tmp/file1.txt /tmp/file2.txt

rm /tmp/file1.txt /tmp/file2.txt