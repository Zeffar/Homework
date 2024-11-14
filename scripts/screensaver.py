#!/usr/bin/env python3

import tkinter as tk

# Create the main window
root = tk.Tk()
root.configure(background='black')

# Define monitor positions and dimensions
dp2_width = 2560
dp2_height = 1440
dp2_x = 3840
dp2_y = 238

dp3_width = 2560
dp3_height = 1440
dp3_x = 6400
dp3_y = 238

# Calculate total geometry
total_width = dp2_width + dp3_width  # 5120
total_height = max(dp2_height, dp3_height) + 20  # Adding extra pixels to cover any offsets

# Starting position (leftmost monitor)
start_x = dp2_x
start_y = dp2_y + 150 # Adjusting upwards to cover any top offsets

# Set the window to cover both DP-2 and DP-3 monitors
root.geometry(f"{total_width}x{total_height}+{start_x}+{start_y}")

# Remove window decorations and make it topmost
root.overrideredirect(True)
root.attributes('-topmost', True)

# Prevent user interactions
root.bind("<Key>", lambda e: "break")
root.bind("<Button>", lambda e: "break")

# Run the application
root.mainloop()
