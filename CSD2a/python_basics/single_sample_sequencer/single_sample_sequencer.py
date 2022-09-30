# Import all modules
import time
import simpleaudio as sa

# Declare valueables
hh = sa.WaveObject.from_wave_file("HH.wav")
bpm = 120

# Ask to change bpm
changeDefaultBpm = input("Default bpm = 120. Want to adjust? [y/n]: ", )
if changeDefaultBpm in ("y", "Y"):     # If statement.
    bpm = float(input("Input new bpm: ", ))  # Input new bpm
    print("New bpm is:", bpm)
elif changeDefaultBpm in ("n", "N"):
    bpm = 120.0
    print("Bpm is:", bpm)
else:
    print("No valid input. ")


# Ask for user input for note durations or default
defaultNoteDurations = input("Want to adjust note durations? [y/n]: ", )
print("Yes or no: ", defaultNoteDurations)
if defaultNoteDurations in ("y", "Y"):
    noteDurations = list(range(int(input("How many notes? ", ))))
    for i in noteDurations:
        noteDurations[i] = float((input("Input duration: ", )))              # Ask all the durations
elif defaultNoteDurations in ("n", "N"):
    noteDurations = [1, 2, 0.75, 1.0, 1]
else:
    print("No valid input.")
print("Note durations: ", noteDurations)

# Function to calculate durations to 16th stamps
def durationsToTimestamps16th(src):
    dst = list(range(len(src)))
    dst.insert(0,0)
    for i in range(len(src)):
        dur = src[i] * 4
        dst[i + 1] = int(dst[i] + dur)
    # print("dst list: ", dst)
    return dst

# Function to calculate 16th stamps to 16th durations
def timeStamps16thTo16Durations16th(src, bpm):
    dst = list(range(len(src)))
    for i in range(len(src)):
        dur = src[i] * (60 / bpm / 4)
        dst[i] = dur
    # print("16th Durations: ", dst)
    dst.pop()
    return dst

# Function to play hh

# Feed functions
stamps16th = durationsToTimestamps16th(noteDurations)
print("tempList: ", stamps16th)

noteDurations16th = timeStamps16thTo16Durations16th(stamps16th, bpm)
print("Note durations 16th: ", noteDurations16th)

def hhplay():
    global hhplaying
    hhplaying = hh.play()

# Function to start playing the timestamps
def playFunction(src):
    startTime = time.time()
    playing : bool = True
    counter = 0
    while playing:
        t = time.time() - startTime
        if t > src[counter]:
            print(counter + 1)
            hhplay()
            counter += 1
        if counter > len(src) -1:
            playing = False
    hhplaying.wait_done()
    time.sleep(0.01)


playFunction(noteDurations16th)
