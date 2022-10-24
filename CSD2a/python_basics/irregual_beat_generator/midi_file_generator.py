#
#   https://pypi.org/project/MIDIUtil
#

from curses import def_prog_mode
from midiutil import MIDIFile
import question_line as ql



def midimaker(bpm, event_list):
    velocity = 100
    track = 0
    channel = 9
    
    file_name = ql.ask('string', 'Insert file name: ')
    print(f'filename: {file_name}')
    
    mf = MIDIFile(1)
    time_beginning = 0
    mf.addTrackName(track, time_beginning, file_name)
    mf.addTempo(track, time_beginning, bpm)

    qnote_dur = 60 / bpm
    instr_midi_pitch = {
        "kick": 36,
        "snare": 38,
        'rim' : 37,
        'hat' : 42,
        'ohat' : 46
    }

    for event in event_list:
        # transform time (sec) to (qnote)
        qnote_time = event["ts"] / qnote_dur
        instr_name = event["inst"]
        mf.addNote(track, channel, instr_midi_pitch[instr_name], qnote_time,
            event['dur'], velocity)

    with open(f'midifiles/{file_name + str(".mid")}','wb') as outf:
        mf.writeFile(outf)

