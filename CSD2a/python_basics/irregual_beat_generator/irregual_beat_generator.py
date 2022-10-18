# Import modules
import time
import simpleaudio as sa
import question_line as ql

# Declare sample file paths
kick = sa.WaveObject.from_wave_file("assets/kick.wav")
rim = sa.WaveObject.from_wave_file("assets/rim.wav")
hat = sa.WaveObject.from_wave_file("assets/hihat.wav")

# Declare variables
bpm = 120.0

#Ask bpm
bpm_ask = ql.ask("bool", "\nThe default bpm is 120. \nDo you wish to change it?")
print(f"bpm_ask: {bpm_ask}")
if (bpm_ask == 1):
    bpm = ql.ask("int", "\nWhat would you like the bpm to be?")
    print(f"Bpm is now {bpm}")


# Make the note lists
kick_notes = [1, 1, 1, 1]
rim_notes = [2, 2]
hat_notes = [0.25, 0.5, 0.25, 0.5, 0.25, 0.5, 0.25, 0.5, 0.25, 0.5, 0.25]

# Function to calculate durations to 16th stamps
def note_to_dur(src):
    dst = list(range(len(src)))
    dst.insert(0,0)
    for i in range(len(src)):
        dur = src[i] * 4
        dur = dur * (60 / bpm /4)
        dst[i + 1] = dst[i] + dur
    dst.pop()
    return dst

# Insert the notes to dur function
kick_notes = note_to_dur(kick_notes)
rim_notes = note_to_dur(rim_notes)
hat_notes = note_to_dur(hat_notes)
print(f"kick_notes: {kick_notes}")
print(f"rim_notes: {rim_notes}")
print(f"hat_notes: {hat_notes}")

# Event list
event_list = []

# Function to add the _notes list as dicts to the event_list
def add_event(instrument, ts):
    for i in range(len(ts)):
        temp_key = {}
        temp_key["instrument"] = instrument
        temp_key["ts"] = ts[i]
        event_list.append(temp_key)

# Insert the function
add_event(kick, kick_notes)
add_event(rim, rim_notes)
add_event(hat, hat_notes)

# Function to play all the events
def player(events):
    start_time = time.time()
    playing : bool = True
    i = 0
    while playing:
        t = time.time() - start_time
        if t > events[i]["ts"]:
            events[i]["instrument"].play()
            i += 1
        if i == len(event_list):
            playing = False
            i = 0
            start_time = time.time()
            t = time.time() - start_time

        time.sleep(0.001)

# Sort all dicts in the event list
event_list = sorted(event_list, key=lambda d: d['ts']) 

# Insert the function
# player(event_list)

# Wacht totdat alle samples gespeeld zijn.
time.sleep(1)