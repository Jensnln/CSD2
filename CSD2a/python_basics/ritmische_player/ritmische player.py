# Import all modules
import time

# Declare variables


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

# Start a for loop as long as the list length.
for notes in range(len(list_notes)):
    # Indexes the list so it cycles through.
    list_note = list_notes[notes]

    # Call the function.
    loop_sample()

    # Calculate the noteLength 1sec / (BPM / 60) = amount of beat per second.
    # BPS * the notelength of the notes.
    noteLength = ((1/(int(noteTempo)/60))) * float(list_notes[notes])
    time.sleep(noteLength)
