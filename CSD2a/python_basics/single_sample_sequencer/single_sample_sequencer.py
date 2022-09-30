# Import all modules
import time

bpm = 120

# Ask to change bpm
changeDefaultBpm = input("Default bpm = 120. Want to adjust? [y/n]: ", )
if changeDefaultBpm == "y":     # If statement.
    bpm = float(input("Input new bpm: ", ))  # Input new bpm
    print("New bpm is:", bpm)
elif changeDefaultBpm == "n":
    bpm = 120.0
    print("Bpm is:", bpm)
else:
    print("No valid input. ")


# Ask for user input for note durations or default
defaultNoteDurations = input("Want to adjust note durations? [y/n]: ", )
print("Yes or no: ", defaultNoteDurations)
if defaultNoteDurations == "y":
    noteDurations = list(range(int(input("How many notes? ", ))))
    for i in noteDurations:
        noteDurations[i] = float((input("Input duration: ", )))              # Ask all the durations
elif defaultNoteDurations == "n":
    noteDurations = [0.5, 1.0, 0.75, 1.0]
print("Note durations: ", noteDurations)



def durationsToTimestamps16th(src):
    dst = list(range(len(src)))
    dst.insert(0,0)
    for i in range(len(src)):
        dur = src[i] * 4
        dst[i + 1] = int(dst[i] + dur)
    # print("dst list: ", dst)
    return dst

def timeStamps16thTo16Durations16th(src, bpm):
    dst = list(range(len(src)))
    for i in range(len(src)):
        dur = src[i] * (60 / bpm / 4)
        dst[i] = dur
    # print("16th Durations: ", dst)
    return dst


"""
# Make a function to recalculate the note durations to 16th
def durationsToTimestamps16th(src):
  dst = list(range(len(src)))       # Make temp lst.
  for i in range(len(src)):         # Save you calculation in a new variable.
    dur = src[i] * ((60.0 / bpm) / 4)# Do your calculation.
    dst[i] = dur                    # Give your new variable to the current index.
  return dst                        # Return your list.
"""

tempList = durationsToTimestamps16th(noteDurations)
print("tempList: ", tempList)

noteDurations16th = timeStamps16thTo16Durations16th(tempList, bpm)
print("Note durations 16th: ", noteDurations16th)

