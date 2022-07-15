#!/bin/bash
## Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0

echo -e "Thread Director Status: $(cat /proc/sys/kernel/sched_itmt_enabled)\n"

echo "CPU Core List: "
for cpu in $(ls /sys/devices/system/cpu | grep "cpu" | grep -v freq | grep -v idle); do
	echo "$cpu: $(cat /sys/devices/system/cpu/$cpu/acpi_cppc/highest_perf)"
done

echo -e "Perf values shown should differ: Preferred cores, P/E cores)\n"
