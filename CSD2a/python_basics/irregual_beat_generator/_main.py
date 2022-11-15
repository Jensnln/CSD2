# Import modules
import time
import simpleaudio      as sa
import question_line    as ql
import generator        as gen
import midi_file_generator as mfgen

# Welcome message.
generating = ql.ask('bool', 'Finally... \nI have been waiting for you. \nShall we start generating a beat? [y/n]')

# Declare sample file paths
samples = {
    'kick': sa.WaveObject.from_wave_file("assets/kick.wav"),
    'rim' : sa.WaveObject.from_wave_file("assets/rim.wav"),
    'hat' : sa.WaveObject.from_wave_file('assets/hihat.wav'),
    'ohat' : sa.WaveObject.from_wave_file('assets/ohat.wav'),
}

while generating:
    # Declare variables
    event_list = []
    bpm = 120
    bpm_ask = ql.ask('bool', f'The bpm is currently {bpm}, is that something you feel comfortable with? [y/n]')
    if bpm_ask is False:
        bpm = ql.ask('float', 'Okay princes, if you want to be in charge. \nHow fast do you wanna go?', {'min' : 20, 'max' : 220})
        # ql.typingPrint(f'Not really my fist choice, but I changed the bpm to {bpm}.')
        if bpm >= 130:
            ql.typingPrint('Uhh okay, I guess its rave time.')
        elif 100 <= bpm < 130:
            ql.typingPrint('I mean, if you think your beat will sound better that way.')
        elif 70 <= bpm < 100:
            ql.typingPrint('Sure.')
        elif bpm < 70:
            ql.typingPrint('Okay granny, I have all day.')
    else:
        ql.typingPrint(f'\nGood choice. The bpm is still {bpm}.')

    # Amount of measurs
    measures = ql.ask('int', '\nNow we have that out of the way, how many measures of pure awesomeness would you like me to generate?', {'min': 0, 'max' : 17})
    if measures > 4:
        ql.typingPrint('Oef.. This is gonna be awkward but you need the full version to generate more than 4 bars..\nEnter you credit card details below.')
        time.sleep(1)
        ql.typingPrint(f'\nJust kidding, {measures} measures it will be.')

    # For each key (sample) in the sample dict, run all the generation algorithm in the generator.py file.
    for key in samples.keys():
        gen.event_maker(key, bpm, measures, event_list)

    # Sort all events in event list based on time stamps.
    event_list = sorted(event_list, key=lambda d: d['ts']) 

    # Print all the events.
    for i in range(len(event_list)):
        print(
        'Event',[i],event_list[i]['inst'], 
        'ts:',event_list[i]['ts'], 
        'dur:',event_list[i]['dur'])

    # Play all the events.
    gen.player(event_list, samples)

    # Ask to export as midifile.
    export = ql.ask('bool', 'Do you want to save the sequence as midifile? [y/n]')
    if export is True:
        mfgen.midimaker(bpm, event_list)

    # Ask to restart the program.
    generating = ql.ask('bool', 'Do you want to make anther one? [y/n]')

# Exit message.
ql.typingPrint('Well... I guess this is goodbye then. \nBy the way, all your midi files are automatically being saved in the /midifiles folder.\nSee you next time.\n')
