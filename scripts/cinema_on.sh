#!/bin/bash
pkill -f screensaver_tv.py
# Run the Python script to blank monitors
python3 /home/zeffar/fedora/scripts/screensaver.py &

#!/bin/bash

wpctl set-default 64