ARCH=$(uname -a)
#The uname command prints system information. This line returns the architecture of the operating system and its kernel version

CPU=$(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
#CPU is the number of physical processors

VCPU=$(grep processor /proc/cpuinfo | wc -l)
#VCPU is the number of virtual processors

URAM=$(free -m | awk '$1 == "Mem:" {print $3}')
TRAM=$(free -m | awk '$1 == "Mem:" {print $2}')
PRAM=$(free | awk '$1 == "Mem:" {printf("%.f"), $3/$2 * 100}')
#RAM information - the free command displays amount of free and used memory in the system. The -m flag displays the memory in megabytes. 

TDISK=$(df -H --total | grep total | awk '{print $2}')
UDISK=$(df -H --total | grep total | awk '{print $3}')
PDISK=$(df -H --total | grep total | awk '{print $5}')
#Disk information - the df command displays the amount of disk space available

CPUL=$(vmstat 1 2 | awk 'NR==4 {print 100 - $15"%"}')
#The vmstat command provides CPU utilization information. This command line returns the current utilization rate of the processors as a %

BOOT=$(who -b)
#The boot cmmnd show who is logged on and the -b flag show the time of last system boot

LVM=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
#This line looks if i have lvm partitions and prints either yes or no

TCP=$(echo "$(netstat -an | grep ESTABLISHED | wc -l) ESTABLISHED")
#The netstat command displays network connections. The -a flag shows all sockets and -n displays numerical addresses and port numbers. Then we filter by active connections by using grep ESTABLISHED.

USERS=$(who | wc -l)
#This command line shows the number os users using the server. The who command gives this information in more detail, the wc -l counts the lines to provide a number

IPADD=$(hostname -I | awk '{print $1}')

MACADD=$(ip link show | awk '$1 == "link/ether" {print $2}')

SUDO=$(grep COMMAND /var/log/sudo/sudo.log | wc -l)

wall "

	#Architecture: $ARCH
	#CPU physical: $CPU
	#vCPU: $VCPU
	#Memory Usage: $URAM/$TRAM ($PRAM%)
	#Disk Usage: $UDISK/$TDISK ($PDISK)
	#CPU load: $CPUL
	#Last boot: $BOOT
	#LVM use: $LVM
	#Connections TCP: $TCP
	#User log: $USERS
	#Network: IP $IPADD ($MACADD)
	#Sudo: $SUDO cmd"
