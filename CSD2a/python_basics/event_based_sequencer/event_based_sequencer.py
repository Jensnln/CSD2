# Import modules
import time
import simpleaudio as sa

# Declare sample file paths
kick = sa.WaveObject.from_wave_file("assets/kick.wav")
rim = sa.WaveObject.from_wave_file("assets/rim.wav")
hihat = sa.WaveObject.from_wave_file("assets/hihat.wav")

# Declare different variables
bpm = 120


kick_notes = [1, 0.5, 1, 0.5]
rim_notes = [2, 2]
hihat_notes = [0.5, 0.5, 0.5, 0.5]



        

event_list = [
    {"name" : "rim", "instrument" : rim, "ts" : 1500}, 
    {"name" : "rim", "instrument" : rim, "ts" : 1600}, 
    {"name" : "rim", "instrument" : rim, "ts" : 1700}, 
    {"name" : "kick", "instrument" : kick, "ts" : 1700}, 
    {"name" : "rim", "instrument" : rim, "ts" : 2000}, 
    ]

# print(event_list)

def handle_note_event(event):
    event['instrument'].play()

# handle_note_event(kick_event)
# handle_note_event(hihat_event)
for event in event_list:
    print(event['name'], event['ts'])
    handle_note_event(event)



time.sleep(2)

