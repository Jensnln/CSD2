# Import all modules
import time

# Declare variables


# Open the input.txt file
input_file = open('CSD2a/python_basics/input.txt')

# Lees de waardes uit en stop deze in een variable
numPlaybackTimes = input_file.read()
input_file.close()

# Input vragen hoevaak de sample af te spelen.
times_playing = numPlaybackTimes 
print(times_playing)

# Binnenhalen van de library en sample laden in de variabele "wave_obj".
import simpleaudio as sa
wave_obj = sa.WaveObject.from_wave_file("/home/jensnln/Documents/Sounds/506453__kbeezy88__220a-ch.wav")
# Functie om de sample af te spelen.
def loop_sample():
    play_obj = wave_obj.play()
    play_obj.wait_done()

print(times_playing)

#  For loop om de functie te loopen met als variabele de input die wordt gevraagd.
for x in range(int((times_playing))):
    loop_sample()
    time.sleep(1)