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
    total_step_amount = step_amount * measures
     
    # How many of those steps played.
    active = int(ql.ask('int', f'How many of the {string} samples do you want played per measure?', {'min': 0, 'max': step_amount}))
    muted = step_amount - active


    # print(f'Amount: {step_amount} | Active: {active} | Muted: {muted}')
    
    # Divide "1" by the amount of steps played to get all equal durations.
    if step_amount > 1:
        dur = 4 / step_amount
    else:
        dur = 0
    # Add all the possible steps with the same duration.
    for i in range(total_step_amount):
        notes.append(round(dur, 4))

    # Double for loop to generate a new sequence for the amount of measures
    for i in range(measures):

        for j in range(muted):

            # p = starting index of each measure (notes[i]). 
            # Min value of the random range. Index of the start of the current measure.
            p = (i * active)

            # Max value of the random range. Amount of notes left in the current measure.
            q = (p + step_amount - j - 2)

            # Generate a random value that corresponds with an index of the current measure.
            r = random.randint(p, q)
            # print(f'min: {p} \nmax:{q}\nq: {r}')

            # If r is smaller then the amount of active notes (notes left in the measure), it will add its duration to the next note and delete itself. 
            # If not it will add tis value to the previous note.

            if r < (p + active):
                notes[r + 1] += notes[r]
                notes.pop(r)
            else:
                # print(f'its happening: | q: {r} | min: {p} | max: {q} | j: {j} | i: {i} | p + active: {p + active}')
                # print(f'notes pre: {notes}')
                notes[r - 1] += notes[r]
                notes.pop(r)
                # print(f'notes post: {notes}')
            
    # Call the next function to calculate the timestamps.
    # print(f'{string} durations: {notes}')
    return notes


# Function to calculate timestamps from durations.
def timestamps(durations, bpm):
    time_stamps = []
    multiplier = 60 / bpm
    sum = 0

    for i in durations:
        time_stamps.append(round(sum, 3))
        sum += i * multiplier

    # print('time_stamps: ', time_stamps)
    return time_stamps


# Function to add the time stamps + instrument as event to the event list.
def event_adder(instrument, dur, ts, event_list_2):
    for i in range(len(dur)):
        # Make a tempory dictionary to add to the event list.
        temp_dict = {}
        temp_dict['inst'] = instrument
        temp_dict['ts'] = round(ts[i], 2)
        temp_dict['dur'] = round(dur[i], 2)
        event_list_2.append(temp_dict)




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

    print(f'{string}notes: ', notes)
