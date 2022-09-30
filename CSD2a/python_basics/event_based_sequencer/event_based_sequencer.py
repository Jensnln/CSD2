# Import modules
import time
import simpleaudio as sa

# Declare sample file paths
kick = sa.WaveObject.from_wave_file("assets/kick.wav")
rim = sa.WaveObject.from_wave_file("assets/rim.wav")
hihat = sa.WaveObject.from_wave_file("assets/hihat.wav")

rim_event = {
'timestamp': 1000, # msec w.r.t start of program
'instrumentname': "rim", # name of instrument in text
'instrument': rim, # reference to sound file
'velocity': 82, # numeric MIDI-based, 0-127
'duration': 500 # msec
}

kick_event = {
'timestamp': 2000, # msec w.r.t start of program
'instrumentname': "kick", # name of instrument in text
'instrument': kick, # reference to sound file
'velocity': 82, # numeric MIDI-based, 0-127
'duration': 500 # msec
}

hihat_event = {
'timestamp': 5000, # msec w.r.t start of program
'instrumentname': "hihat", # name of instrument in text
'instrument': hihat, # reference to sound file
'velocity': 82, # numeric MIDI-based, 0-127
'duration': 500 # msec
}

def handle_note_event(event):
    # print(event['instrumentname'])
    event['instrument'].play()

handle_note_event(kick_event)
handle_note_event(hihat_event)

time.sleep(2)
