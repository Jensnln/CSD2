import sys
from PIL import Image

# Open the .heic file
try:
    heic_file = Image.open(sys.argv[1])
except IOError:
    print("Error opening file")
    sys.exit()

# Save the file as a .png
png_file = IMG_1827.save(sys.argv[1][:-5] + ".png")