# Print selected Code Pages named at https://docs.python.org/3.6/library/codecs.html#standard-encodings
# Ian Tresman. 10 November 2018.
import unicodedata as ucd

all_codepages=['cp037', 'cp273', 'cp424', 'cp437', 'cp500', 'cp720', 'cp737', 'cp775', 'cp850', 'cp852', 'cp855', 'cp856',
           'cp857', 'cp858', 'cp860', 'cp861', 'cp862', 'cp863', 'cp864', 'cp865', 'cp866', 'cp869', 'cp874', 'cp875',
           'cp932', 'cp1006', 'cp1026', 'cp1125', 'cp1140', 'cp1250', 'cp1251', 'cp1252', 'cp1253', 'cp1254', 'cp1255',
           'cp1256', 'cp1257', 'cp1258',  'latin_1', 'iso8859_1', 'iso8859_2', 'iso8859_3', 'iso8859_4', 'iso8859_5',
           'iso8859_6', 'iso8859_7', 'iso8859_8', 'iso8859_9', 'iso8859_10', 'iso8859_11', 'iso8859_13', 'iso8859_14',
           'iso8859_15', 'iso8859_16', 'koi8_r', 'koi8_t', 'koi8_u', 'kz1048', 'mac_cyrillic', 'mac_greek', 'mac_iceland',
           'mac_latin2', 'mac_roman', 'mac_turkish', 'ptcp154']

codepages=['cp437', 'cp850', 'cp1252']

c0 = '⌂☺☻♥♦♣♠•◘○◙♂♀♪♫☼►◄↕‼¶§▬↨↑↓→←∟↔▲▼'

cp850 = ('░▒▓│┤╣║╗╝┐└┴┬├─'
         '┼╚╔╩╦╠═╬ı┘┌█▄▀‗■ƒ')

cp1252 = '€‚ƒ„…†‡ˆ‰Š‹ŒŽ‘’“”•–—˜™š›œžŸ'
# only ƒ is in cp850 (9f)
#for c in c0:
#  print(f"u'{c} {ucd.name(c).lower()}")
#exit()

for c in cp1252:
  ac = c.encode('cp1252')
#  print(f"    {{0x{ac.hex()}, u'{c}'} }, // {ucd.name(c).lower()}")
  print(f"{ord(c):04x}", ac.hex(), c, ucd.category(c), ucd.name(c))
exit()

for i in range(0xA0, 0xFF):
  c = chr(i)
  c850 = c.encode('cp850')
  print(f"{ord(c):04x}", c850.hex(), c, ucd.category(c), ucd.name(c))
exit()

for codepage in codepages:                             #Select each code page in turn
    print(" "*12 + "Codepage: ", codepage)             #Indented code page name
    print("   | 0 1 2 3 4 5 6 7 8 9 A B C D E F")      #Code page columns, A=10, B=11 etc
    print("   " + "-"*33)                              #Horizontal rule
    for row in range(0,255,16):                        #For each row (ignore control characters < 32)
        print(f"{row:3}:",end= ' ')                    #Print row code
        for col in range(0,16):                        #For each column
            char=row+col                               #Calculate character number (similar to ascii code)
            try:                                       #Try to get a unicode equivalent of a specific byte value:
                unichar=bytes([char]).decode(codepage) #Fails with non-mappable characters, and some control characters
            except:                                    
                unichar=" "                             #If there was no unicode, use a space

            if not (unichar.isprintable()): unichar=" " #If the unicode is not printable, use a space
            print(unichar, end=' ')
        print()                       #End of row break
    print()                           #End of code page spacing
    # input("")                         #Pause after each code page, press Enter to continue
