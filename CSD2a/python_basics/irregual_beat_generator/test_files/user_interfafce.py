import time, sys

#Python Typing Text Effect - www.101computing.net/python-typing-text-effect/
import time,os,sys

def typingPrint(text):
  for character in text:
    sys.stdout.write(character)
    sys.stdout.flush()
    time.sleep(0.03)

def typingPrintfast(text):
  for character in text:
    sys.stdout.write(character)
    sys.stdout.flush()
    time.sleep(0.003)
  
def typingInput(text):
  for character in text:
    sys.stdout.write(character)
    sys.stdout.flush()
    time.sleep(0.03)
  value = input()  
  return value  
  
def clearScreen():
  os.system("clear")

typingPrintfast("""\
  _____                           _              _                _                                     _             
  \_   \_ __ _ __ ___  __ _ _   _| | __ _ _ __  | |__   ___  __ _| |_    __ _  ___ _ __   ___ _ __ __ _| |_ ___  _ __ 
   / /\/ '__| '__/ _ \/ _` | | | | |/ _` | '__| | '_ \ / _ \/ _` | __|  / _` |/ _ \ '_ \ / _ \ '__/ _` | __/ _ \| '__|
/\/ /_ | |  | | |  __/ (_| | |_| | | (_| | |    | |_) |  __/ (_| | |_  | (_| |  __/ | | |  __/ | | (_| | || (_) | |   
\____/ |_|  |_|  \___|\__, |\__,_|_|\__,_|_|    |_.__/ \___|\__,_|\__|  \__, |\___|_| |_|\___|_|  \__,_|\__\___/|_|   
                      |___/                                             |___/                                         
                    """)
    
typingPrint("Hello world...\n")
time.sleep(1)

typingPrint("Welcome to the Irregular beat generator.\n")
time.sleep(0.5)
typingPrint("Right now i will try to base a beat on you personality.\n")
time.sleep(1)
typingPrint("What is your speed on a scale from 20 to 220? (And yes, this will also be your bpm input) \n")
bpm = float(input("Speed: ", ))
typingPrint(f"Your bpm is {bpm}... Thats not really fast want me to crank it up a notch? \n")
crank_it_up = input("[y/n]\n", )
if crank_it_up == "y":
    typingPrint("Ok bpm cranked by 5\n")
    bpm += 5
    typingPrint(f"Bpm is now {bpm}\n")
elif crank_it_up == "n":
    typingPrint("Whatever \n")
else:
    typingPrint("Uhmm yeah sure go u.. \n")

