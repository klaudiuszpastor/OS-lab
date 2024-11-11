#!/bin/bash

echo "Starting the script"

cd ~/EiT/OS_lab/lab2
touch test.txt

battery_level=$(cat "/sys/class/power_supply/BAT1/capacity")
echo "Battery level is $battery_level%"
echo "$battery_level%" >> test.txt  

echo "Ending the script"

