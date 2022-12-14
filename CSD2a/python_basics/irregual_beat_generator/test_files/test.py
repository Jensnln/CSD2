# Import modules
import time
from pkg_resources import safe_name
import simpleaudio      as sa
import question_line    as ql
import generator        as gen
import midi_file_generator as mfgen

another = ql.ask('bool', 'Would you like to start generating? [y/n]')

while another:
    # Declare sample file paths
    samples = {
        'kick': sa.WaveObject.from_wave_file("assets/kick.wav"),
        'rim' : sa.WaveObject.from_wave_file("assets/rim.wav"),
        'hat' : sa.WaveObject.from_wave_file('assets/hihat.wav'),
        'ohat' : sa.WaveObject.from_wave_file('assets/ohat.wav'),
    }


    # Declare variables
    bpm = 120
    event_list = []

    bpm_ask = ql.ask('bool', f'The bpm is currently {bpm}, would you like to change that? [y/n]')
    if bpm_ask is True:
        bpm = ql.ask('float', 'Enter new bpm.')
        print(f'The bpm is now {bpm}.')
    else:
        print(f'Ok. The bpm is still {bpm}.')

    # Amount of measurs
    measures = ql.ask('int', 'How many measures would you like to generate?', {'min': 0})

    for key in samples.keys():
        gen.event_maker(key, bpm, measures, event_list)

    # Function to play all the events.
    def player(events):
        # Set start time of the player to current time.
        start_time = time.time()
        # Make a boolean to determine if the player is playing.
        playing : bool = True
        # Counter for all the timestamps.
        i = 0
        while playing:
            # Calculate current time.
            t = time.time() - start_time
            # Check if the time is greater than the current time stamp.
            if t > events[i]["ts"]:
                # If so play the corresponding sample in the sample dict.
                instrument = events[i]['inst']
                samples[instrument].play()
                # Go the the next timestamp.
                i += 1
            # Check if the time stamp counter is equal to the length of the event list (all the timestamps).
            if i == len(event_list):
                # If so break the while loop and reset all the start time and counter.
                playing = False
                i = 0
                start_time = time.time()
                t = time.time() - start_time
            # Wait for the last sample to finnish playing.
            time.sleep(0.001)


    # Sort all events in event list based on time stamps
    event_list = sorted(event_list, key=lambda d: d['ts']) 

    # Print all the events.
    for i in range(len(event_list)):
        print(
        'Event',[i],event_list[i]['inst'], 
        'ts:',event_list[i]['ts'], 
        'dur:',event_list[i]['dur'])

    # Play all the events.
    player(event_list)

    # Ask to export as midifile.
    export = ql.ask('bool', 'Do you want to save the sequence as midifile? [y/n]')
    if export is True:
        mfgen.midimaker(bpm, event_list)

    # Ask to restart the program.
    another = ql.ask('bool', 'Do you want to make anther one? [y/n]')
    


# --- To Do --- 
# Upgrade UI
# Add more option for generation.
