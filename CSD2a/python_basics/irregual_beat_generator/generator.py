 import random
import time
import question_line as ql
import simpleaudio as sa


# Function to calculate the note durations. 
# Once calculated, save all the durations in a temporary list within the function.
# Then take that list and calculate al the time stamps with them.
# Then add all the durations and time stamps into a new list.



# Eucleadian way of generating durations.
def durations(string, measures):
    notes = []

    # Steps to divide the measure.
    step_amount = int(ql.ask('int', f'How many {string} notes do you want in a measure?', {'min': 0}))
    # total_step_amount = step_amount * measures
     
    # How many of those steps played.
    active = int(ql.ask('int', f'How many of the {string} samples do you want played per measure?', {'min': 0, 'max': step_amount}))
    muted = step_amount - active


        
    # print(f'Amount: {step_amount} | Active: {active} | Muted: {muted}')
    
    # Divide "1" by the amount of steps played to get all equal durations.
    if step_amount > 1:
        dur = 4 / step_amount
    else:
        dur = 0

    # Generate for each measure.
    for i in range(measures):
        # Generate an empty list for each measure.
        temp_list = []

        # Generate for each step in eacht measure.
        for j in range(step_amount):
            temp_list.append(round(dur, 3))

        # Generate for each muted note a random index within the range of the measure.
        for k in range(muted):

            rand_value = random.randint(0, len(temp_list) - 2)

            # If its the last index in the measure, add its duration to the previous note and remove itself.
            if rand_value == len(temp_list):
                temp_list[rand_value - 1] += temp_list[rand_value]
                temp_list.pop(rand_value)
            elif rand_value < len(temp_list): # If its not the last note, add its duration to the next note.
                
                temp_list[rand_value + 1] += temp_list[rand_value]
                temp_list.pop(rand_value)        
        # Add all the remaining notes in the notes list.
        for l in range(len(temp_list)):
            notes.append(temp_list[l])

    # Return the note list.
    return notes  


# Function to calculate timestamps from durations.
def timestamps(durations, bpm):
    time_stamps = []
    multiplier = 60 / bpm
    sum = 0
    for i in durations:
        time_stamps.append(round(sum, 3))
        sum += i * multiplier
    return time_stamps


# Function to add the time stamps + instrument as event to the event list.
def event_adder(instrument, dur, ts, event_list):
    for i in range(len(dur)):
        # Make a tempory dictionary to add to the event list.
        temp_dict = {}
        temp_dict['inst'] = instrument
        temp_dict['ts'] = round(ts[i], 2)
        temp_dict['dur'] = round(dur[i], 2)
        event_list.append(temp_dict)




def event_maker(string, bpm, measures, event_list):
    _durations = durations(string, measures)
    # print(_durations)
    _timestamps = timestamps(_durations, bpm)
    # print(_timestamps)
    event_adder(string, _durations, _timestamps, event_list)

# Function to play all the events.
def player(events, samples):
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
        if i == len(events):
            # If so break the while loop and reset all the start time and counter.
            playing = False
            i = 0
            start_time = time.time()
            t = time.time() - start_time
        # Wait for the last sample to finnish playing.
        time.sleep(0.001)