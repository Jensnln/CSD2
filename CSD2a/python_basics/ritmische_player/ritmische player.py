# Import all modules
from sqlite3 import Timestamp
import time

# Declare variables
start_time = time.time()
played_time = 0
prev_noteLength = 0


# Open the input.txt file
input_file = open('CSD2a/python_basics/ritmische_player/input.txt')
input_file_content = input_file.read()

# Put the content in the list.
input_file_list = input_file_content.split()

# Lees de waardes uit en stop deze in een variable.
input_file.close()

# Input vragen hoevaak de sample af te spelen.
numPlaybackTimes = input_file_list[0]



# Binnenhalen van de library en sample laden in de variabele "wave_obj".
import simpleaudio as sa
wave_obj = sa.WaveObject.from_wave_file("CSD2a/python_basics/ritmische_player/HH.wav")
# Functie om de sample af te spelen.
def loop_sample():
    play_obj = wave_obj.play()
    # play_obj.wait_done()

# Calculate how many hits a second.
noteTempo = input_file_list[-1]
print(noteTempo)

# Make a new list you can edit seperately.
list_notes = input_file_list

# Remove first and last index from list.
list_notes.pop()
list_notes.pop(0)


# Bool to check if the loop has ended
has_more_notes : bool = True

# Make a value to check what note you're on
next_note = 0

# Set the next note start time equal to the start time of the program.
next_note_start_time = start_time

# Make a while loop for as long as the boolean is true
while has_more_notes:
    current_time = time.time()

    # If the start time for the next note is equal or smaller then the current time play the note.
    if next_note_start_time  <= current_time:

        # Calculate the length of the note
        next_note_start_time = current_time + ((1/(int(noteTempo)/60))) * float(list_notes[next_note])
        next_note += 1
        loop_sample()

        # If the next note index is higher then te current note turn the boolean false.
        if next_note == len(list_notes):
            has_more_notes = False