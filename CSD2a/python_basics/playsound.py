# Input vragen hoevaak de sample af te spelen.
times_playing = input("Hoe vaak moet de sample worden afgespeeld? " )

# Binnenhalen van de library en sample laden in de variabele "wave_obj".
import simpleaudio as sa
wave_obj = sa.WaveObject.from_wave_file("/Users/jens/Splice/sounds/packs/LOUD DRUMS - VOL. 1/Origin_Sound_-_LOUD_DRUMS_VOL_1/Drum_Hits/Cymbals/OS_LD1_HiHat_Dribble.wav")

# Functie om de sample af te spelen.
def loop_sample():
    play_obj = wave_obj.play()
    play_obj.wait_done()

#  For loop om de functie te loopen met als variabele de input die wordt gevraagd.
for x in range(int(times_playing)):
    loop_sample()
    

    aanpassing