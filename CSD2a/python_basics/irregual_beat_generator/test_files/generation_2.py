import random
import question_line as ql

measures = ql.ask('int', 'How many measures do you want to generate?', {'min':0})

# Function to calculate timestamps from durations.
def timestamps(durations, bpm):
    time_stamps = []
    multiplier = 60 / bpm
    sum = 0

    for i in durations:
        time_stamps.append(round(sum, 4))
        sum += i * multiplier

    return time_stamps

# Eucleadian way of generating durations.
def durations(string, bpm, measures):
    notes = []

    # Steps to divide the measure.
    step_amount = int(ql.ask('int', f'How many {string} notes do you want in a measure?', {'min': 0}))
    total_step_amount = step_amount * measures
     
    # How many of those steps played.
    active = int(ql.ask('int', f'How many of the {string} samples do you want played per measure?', {'min': 1, 'max': step_amount}))
    muted = step_amount - active


        
    # print(f'Amount: {step_amount} | Active: {active} | Muted: {muted}')
    
    # Divide "1" by the amount of steps played to get all equal durations.
    dur = 4 / step_amount


    for i in range(measures):
        temp_list = []

        for j in range(step_amount):
            temp_list.append(round(dur, 3))
        # print(f'temp_list pre pop: {temp_list}')

        for k in range(muted):

            rand_value = random.randint(0, len(temp_list) - 2)
            # print(f'k: {k} | rand_value: {rand_value} | step_amount: {step_amount}')
            if rand_value == len(temp_list):


                temp_list[rand_value - 1] += temp_list[rand_value]
                temp_list.pop(rand_value)
            elif rand_value < len(temp_list):
                
                temp_list[rand_value + 1] += temp_list[rand_value]
                temp_list.pop(rand_value)
        
        print(f'temp_list post pop: {temp_list}\n')
        
        for l in range(len(temp_list)):
            notes.append(temp_list[l])
            
    print(f'notes: {notes}\n length{len(notes)}')

        
    # Call the next function to calculate the timestamps.
    # print(f'{string} durations: {notes}')
    return timestamps(notes, bpm)            


kick_notes = durations('kick', 120, measures)
print(f'kick_notes: {kick_notes}\n length{len(kick_notes)}')