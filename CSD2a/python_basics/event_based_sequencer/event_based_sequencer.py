# Import modules
import time
import simpleaudio as sa

# Declare sample file paths
kick = sa.WaveObject.from_wave_file("assets/kick.wav")
rim = sa.WaveObject.from_wave_file("assets/rim.wav")
hihat = sa.WaveObject.from_wave_file("assets/hihat.wav")

kick_notes = []
rim_notes = []
hihat_notes = []

event_list = [
    {"name" : "rim", "instrument" : rim, "ts" : 1500}, 
    {"name" : "rim", "instrument" : rim, "ts" : 1600}, 
    {"name" : "rim", "instrument" : rim, "ts" : 1700}, 
    {"name" : "kick", "instrument" : kick, "ts" : 1700}, 
    {"name" : "rim", "instrument" : rim, "ts" : 2000}, 
    ]

# print(event_list)

def handle_note_event(event):
    print(event['name'], event['ts'])
    event['instrument'].play()

# handle_note_event(kick_event)
# handle_note_event(hihat_event)
for event in event_list:
    handle_note_event(event)



time.sleep(2)

