# Import modules
import time
import simpleaudio as sa

# Declare variables
bpm = 120

# Make variables a string
kick_ = "kick"
rim_ = "rim"
hat_ = "hat"

# Declare sample file paths
kick = sa.WaveObject.from_wave_file("assets/kick.wav")
rim = sa.WaveObject.from_wave_file("assets/rim.wav")
hihat = sa.WaveObject.from_wave_file("assets/hihat.wav")

# Make the note lists
kick_notes = [1, 2, 1, 2]
rim_notes = [2, 2]
hat_notes = [0.5, 0.5, 0.5, 0.5, 0.5, 0.5]

# Function to calculate durations to 16th stamps
def durationsToTimestamps16th(src):
    dst = list(range(len(src)))
    dst.insert(0,0)
    for i in range(len(src)):
        dur = src[i] * 4
        dst[i + 1] = int(dst[i] + dur)
    # print("dst list: ", dst)
    return dst

kick_notes = durationsToTimestamps16th(kick_notes)
rim_notes = durationsToTimestamps16th(rim_notes)
hat_notes = durationsToTimestamps16th(hat_notes)

# Function to calculate 16th stamps to 16th durations
def timeStamps16thTo16Durations16th(src, bpm):
    dst = list(range(len(src)))
    for i in range(len(src)):
        dur = src[i] * (60 / bpm / 4)
        dst[i] = dur
    # print("16th Durations: ", dst)
    dst.pop()
    return dst

kick_notes = timeStamps16thTo16Durations16th(kick_notes, bpm)
rim_notes = timeStamps16thTo16Durations16th(rim_notes, bpm)
hat_notes = timeStamps16thTo16Durations16th(hat_notes, bpm)

print("kick_notes: ", kick_notes)
print("rim_notes: ", rim_notes)
print("hat_notes: ", hat_notes)


# Make an event list
event_list = []


def add_event(instrument, notes):
    for note in notes:
        tempkey = {}
        tempkey["instrument"] = instrument
        tempkey["note"] = note
        event_list.append(tempkey)

# Add all events to the event_list
add_event(kick_, kick_notes)
add_event(rim_, rim_notes)
add_event(hat_, hat_notes)

# print(event_list)


