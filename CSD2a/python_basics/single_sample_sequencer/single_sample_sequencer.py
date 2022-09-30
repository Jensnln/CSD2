# Import all modules
import time

bpm = 120

# Ask to change bpm
changeDefaultBpm = input("Default bpm = 120. Want to adjust? [y/n]: ", )
if changeDefaultBpm == "y":     # If statement.
    bpm = float(input("Input new bpm: ", ))  # Input new bpm
    print("New bpm is:", bpm)
elif changeDefaultBpm == "n":
    bpm = 120
    print("Bpm is:", bpm)
else:
    print("No valid input. ")