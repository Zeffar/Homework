#!/bin/bash
# Run the Python script to blank tv
python3 /home/zeffar/fedora/scripts/screensaver_tv.py &

# Kill the Python process running blank_dp3.py
pkill -f screensaver.py

# Define the sink names for Line-Out (Analog Stereo) and HDMI (TV)
LINE_OUT="alsa_output.pci-0000_0d_00.6.analog-stereo"     # Analog Stereo output
HDMI_OUT="alsa_output.pci-0000_01_00.1.hdmi-stereo"       # HDMI output 

# Get the current default sink
wpctl set-default 53
