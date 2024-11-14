#!/usr/bin/env python3

import tkinter as tk

# Create the main window
root = tk.Tk()
root.configure(background='black')

# Define monitor position and dimensions for HDMI-2
hdmi2_width = 3840  # Width of the HDMI-2 monitor
hdmi2_height = 2160  # Height of the HDMI-2 monitor
hdmi2_x = 0          # X position for HDMI-2
hdmi2_y = 0          # Y position for HDMI-2

# Set the window to cover the HDMI-2 monitor
root.geometry(f"{hdmi2_width}x{hdmi2_height}+{hdmi2_x}+{hdmi2_y}")

# Remove window decorations and make it topmost
root.overrideredirect(True)
root.attributes('-topmost', True)

# Prevent user interactions
root.bind("<Key>", lambda e: "break")
root.bind("<Button>", lambda e: "break")

# Run the application
root.mainloop()
