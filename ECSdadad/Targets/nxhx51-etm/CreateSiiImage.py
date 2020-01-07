from optparse import OptionParser

'''
This shall create an Sii c-header file from binary TwinCAT EEPROM export or CTT V2 export
'''

def generateCArray(strSourceName, strSourcePath=".", strDestinationName="data_array.c", strDestinationPath=".", strName="abData", maxEntriesPerLine=16, unsigned=False):
    strSource = strSourceName
    if strSourcePath != ".":
        stSource = "%s/%s"%(strSourcePath,strSourceName)
    strDestination = strDestinationName
    if strDestinationPath != ".":
        strDestination = "%s/%s"%(strDestinationPath,strDestinationName)
    ulEntryByLine = 0
    ulLines = 1
    strBegin = "{sign}char {name}[] = ".format(sign=("" if unsigned == False else "unsigned "), name=strName) + "\n{\n"

    fSource = open(strSource,"rb")
    fDest   = open(strDestination,"w")
    fDest.write(strBegin)

    byte = fSource.read(1)
    if len(byte) != 0:
        fDest.write("  %#04x"%ord(byte))
    byte = fSource.read(1)
    while len(byte) != 0:
        ulEntryByLine += 1
        if ulEntryByLine >= maxEntriesPerLine:
            fDest.write(",\n  %#04x"%(ord(byte)))
            ulEntryByLine = 0
            ulLines += 1
        else:
            if ulEntryByLine == int((maxEntriesPerLine+1)/2):
                fDest.write(",  %#04x"%ord(byte))
            else:
                fDest.write(", %#04x"%ord(byte))
        byte = fSource.read(1)
    fDest.write("\n};\n")
    fDest.close()
    fSource.close()

#--------------------------------------------------------------------------------------

Images = ["SiiImage",
          ]

for image in Images:
    generateCArray(strSourceName = "Binaries/" + image + ".bin",
                   strDestinationName = "Includes/" + image + ".h",
                   strName="g_abSiiImage",
                   maxEntriesPerLine=16,
                   unsigned=True)
