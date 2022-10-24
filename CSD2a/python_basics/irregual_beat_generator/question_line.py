import time,os,sys

# Funtion to print letter for letter.
def typingPrint(text):
  for character in text:
    sys.stdout.write(character)
    sys.stdout.flush()
    time.sleep(0.03)

def typingPrintfast(text):

  for character in text:
    sys.stdout.write(character)
    sys.stdout.flush()
    time.sleep(0.002)

# Function to ask questions.
def ask(type: str, question_string: str, options: dict = {}):
    """Print a question and return the answer. The type and required options are specified in the parameters. If the answer is invalid, the question will be asked again.

    Args:
        type (str): The type of the answer. Can be 'bool', 'int', or 'string'.
        questionString (str): Question to ask.
        options (dict, optional): Parameters to specify the answer. Defaults to None.

    Returns:
        _type_: str
    """
    # Print the question
    typingPrint(f'\n{question_string}')

    # Ask the question
    result = input('\n> ')

    # Check if the requested type is a string
    if type == 'string':
        isError = False

        # Check if the answer is empty
        if 'allowEmpty' in options and options['allowEmpty'] == False and result == "":
            typingPrint('Value cannot be empty.')
            isError = True
        # Check if the answer is too long
        elif 'max' in options and len(result) > options['max']:
            typingPrint('Value cannot be longer than ' + str(options['max']) + ' characters.')
            isError = True

        # If there is an error, ask the question again
        if isError:
            typingPrint('Please enter a valid option.')
            return ask(type, question_string, options)

    # Check if the requested type is a boolean
    elif type == 'bool':
        isError = False

        # Check if the answer is an allowed value
        if (result not in [
            'y', 'Y', 'yes', 'ja',  'j', 'true','Yes', 'True',  'TRUE',
            'n', 'N', 'no','No',  'nee', 'n', 'false', 'False', 'FALSE'
        ]):
            isError = True

        # If there is an error, ask the question again
        if isError:
            typingPrint('Please enter a valid option.')
            return ask(type, question_string, options)

        # Check if the answer is yes
        result = result in ['y', 'Y', 'yes','Yes', 'ja', 'j', 'true', 'True', 'TRUE']

    # Check if the requested type is an integer
    elif type == 'int':
        # Try to parse the answer to an integer. If it fails, ask the question again
        try:
            result = int(result)
            # Check if the answer is in bounds, throw an error if it is not
            if ('min' in options and result < options['min']):
                typingPrint('Value cannot be smaller than ' +
                      str(options['min']) + '.')
                raise ValueError
            if ('max' in options and result > options['max']):
                typingPrint('Value cannot be larger than ' +
                      str(options['max']) + '.')
                raise ValueError
        except:
            typingPrint('Please enter a valid number.')
            return ask(type, question_string, options)
    elif type == 'float':
        try:
            result = float(result)
            if ('min' in options and result < options['min']):
                typingPrint('Value cannot be smaller than ' +
                        str(options['min']) + '.')
                raise ValueError
            if ('max' in options and result > options['max']):
                typingPrint('Value cannot be larger than ' +
                        str(options['max']) + '.')
                raise ValueError
        except:
            typingPrint('Please enter a valid number')
            return ask(type, question_string, options)
    # Return the result
    # print(f'Result in ask(): {result}')
    return result

typingPrint("Welcome to the: \n")
time.sleep(0.1)

typingPrintfast("""\
  _____                           _              _                _                                     _             
  \_   \_ __ _ __ ___  __ _ _   _| | __ _ _ __  | |__   ___  __ _| |_    __ _  ___ _ __   ___ _ __ __ _| |_ ___  _ __ 
   / /\/ '__| '__/ _ \/ _` | | | | |/ _` | '__| | '_ \ / _ \/ _` | __|  / _` |/ _ \ '_ \ / _ \ '__/ _` | __/ _ \| '__|
/\/ /_ | |  | | |  __/ (_| | |_| | | (_| | |    | |_) |  __/ (_| | |_  | (_| |  __/ | | |  __/ | | (_| | || (_) | |   
\____/ |_|  |_|  \___|\__, |\__,_|_|\__,_|_|    |_.__/ \___|\__,_|\__|  \__, |\___|_| |_|\___|_|  \__,_|\__\___/|_|   
                      |___/                                             |___/                                         
                   \n""")
time.sleep(1)

