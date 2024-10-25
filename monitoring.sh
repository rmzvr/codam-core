#!/usr/bin/bash

ARCHITECTURE=$(uname -a)
CPU_PHYSICAL=$(lscpu | grep -E '^Socket\(s\)' | awk '{print $2}')
V_CPU=$(lscpu | grep -E '^CPU\(s\)' | awk '{print $2}')

MEM_USED_MB=$(free --si -m | grep -E '^Mem' | awk '{print $3}')
MEM_TOTAL_MB=$(free --si -m | grep -E '^Mem' | awk '{print $2}')
MEM_PERCENT=$(echo "scale=2; ($MEM_USED_MB / $MEM_TOTAL_MB) * 100" | bc)
MEM_STAT="$MEM_USED_MB/$MEM_TOTAL_MB"MB

DISK_USED=$(df -BMB --total --output=used | tail -1 | rev | cut -c 3- | rev)
DISK_TOTAL=$(df -BGB --total --output=size | tail -1 | awk '{print $1}' | rev | cut -c 3- | rev)
DISK_PERCENT=$(df -BGB --total --output=pcent | tail -1 | awk '{print $1}')
DISK_STATS="$DISK_USED/$DISK_TOTAL"Gb

CPU_LOAD=$(echo "scale=2; (100 - $(mpstat | tail -1 | awk '{print $13}'))" | bc)
LAST_BOOT=$(who -b | awk '{print $3 " " $4}')
LVM_USE=$( [ $(lsblk | grep -c lvm) -ne 0 ] && echo "yes" || echo "no" )
CONNECTIONS_TCP="$(ss -t | grep -c ESTAB) ESTABLISHED"
USER_LOG="$(who | awk '{print $1}' | sort | uniq | wc -l)"
NETWORK="IP $(hostname -I)($(ip a | grep ether | awk '{print $2}'))"
SUDO="$(ls /var/log/sudo/00/00 | wc -w) cmd"

echo -n "\
#Architecture: $ARCHITECTURE
#CPU physical : $CPU_PHYSICAL
#vCPU : $V_CPU
#Memory Usage: $MEM_STAT ($MEM_PERCENT%)
#Disk Usage: $DISK_STATS ($DISK_PERCENT)
#CPU load: $CPU_LOAD%
#Last boot: $LAST_BOOT
#LVM use: $LVM_USE
#Connections TCP : $CONNECTIONS_TCP
#User log: $USER_LOG
#Network: $NETWORK 
#Sudo : $SUDO" | wall
