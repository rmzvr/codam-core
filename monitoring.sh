MEM_USED_MB=$(free --si -m | grep -E '^Mem' | awk '{print $3}')
MEM_TOTAL_MB=$(free --si -m | grep -E '^Mem' | awk '{print $2}')
MEM_PERCENT=$(echo "scale=2; ($MEM_USED_MB / $MEM_TOTAL_MB) * 100" | bc)
MEM_STAT="$MEM_USED_MB/$MEM_TOTAL_MB"MB
DISK_USAGE=$(df --si --total --output=used,size,pcent)
DISK_USED=$(df -BMB --total --output=used | tail -1 | rev | cut -c 3- | rev)
DISK_TOTAL=$(df -BGB --total --output=size | tail -1 | awk '{print $1}' | rev | cut -c 3- | rev)
DISK_PERCENT=$(df -BGB --total --output=pcent | tail -1 | awk '{print $1}')
DISK_STATS="$DISK_USED/$DISK_TOTAL"Gb

CPU_PERCENT=$(echo "scale=2; (100 - 97.34)" | bc)

echo -e "\
#Architecture: $(uname -a)\n\
#CPU physical : $(lscpu | grep -E '^Socket\(s\)' | awk '{print $2}')\n\
#vCPU : $(lscpu | grep -E '^CPU\(s\)' | awk '{print $2}')\n\
#Memory Usage: $MEM_STAT ($MEM_PERCENT%)\n\
#Disk Usage: $DISK_STATS ($DISK_PERCENT)\n\
#CPU load: $CPU_PERCENT
" | wall
