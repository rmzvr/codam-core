#!/usr/bin/bash

MEM_USED_MB=$(free --si -m | grep -E '^Mem' | awk '{print $3}')
MEM_TOTAL_MB=$(free --si -m | grep -E '^Mem' | awk '{print $2}')
MEM_PERCENT=$(echo "scale=2; ($MEM_USED_MB / $MEM_TOTAL_MB) * 100" | bc)
MEM_STAT="$MEM_USED_MB/$MEM_TOTAL_MB"MB
DISK_USAGE=$(df --si --total --output=used,size,pcent)
DISK_USED=$(df -BMB --total --output=used | tail -1 | rev | cut -c 3- | rev)
DISK_TOTAL=$(df -BGB --total --output=size | tail -1 | awk '{print $1}' | rev | cut -c 3- | rev)
DISK_PERCENT=$(df -BGB --total --output=pcent | tail -1 | awk '{print $1}')
DISK_STATS="$DISK_USED/$DISK_TOTAL"Gb

CPU_PERCENT=$(echo "scale=1; (100 - $(mpstat | tail -1 | awk '{print $13}'))" | bc)
LVM_USE=$( [ $(lsblk -f | grep -c lvm) -ne 0 ] && echo "yes" || echo "no" )
echo -e "\
#Architecture: $(uname -a)
#CPU physical : $(lscpu | grep -E '^Socket\(s\)' | awk '{print $2}')
#vCPU : $(lscpu | grep -E '^CPU\(s\)' | awk '{print $2}')
#Memory Usage: $MEM_STAT ($MEM_PERCENT%)
#Disk Usage: $DISK_STATS ($DISK_PERCENT)
#CPU load: $CPU_PERCENT%
#Last boot: $(who -b | awk '{print $3}') $(who -b | awk '{print $4}')
#LVM use: $LVM_USE
#Connections TCP : $(ss -t | grep -c ESTAB) ESTABLISHED
#User log: $(users | wc -w)
#Network: IP $(nmcli | grep inet4 | awk '{print $2}' | rev | cut -c 4- | rev) ($(ifconfig -a | grep -oE '([a-z0-9]{2}:){5}[a-z0-9]{2}')) 
" | wall
