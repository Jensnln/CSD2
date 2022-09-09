import simpleaudio as sa
wave_obj = sa.WaveObject.from_wave_file("/Users/jens/Splice/sounds/packs/LOUD DRUMS - VOL. 1/Origin_Sound_-_LOUD_DRUMS_VOL_1/Drum_Hits/Cymbals/OS_LD1_HiHat_Dribble.wav")
play_obj = wave_obj.play()
play_obj.wait_done()