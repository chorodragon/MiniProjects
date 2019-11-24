import os
import re

f = open("log.txt", "w+")

def renameFile(oldFileName, newFileName):
	try:
		print('Renaming file "{0}" to "{1}"'.format(oldFileName, newFileName))
		os.rename(oldFileName, newFileName)
		f.write('Renaming file "{0}"" to "{1}\n"'.format(oldFileName, newFileName))
	except:
		f.write('Error. Omitting file: {0}\n'.format(oldFileName))
		print('Error. Omitting file: {0}'.format(oldFileName))

def generateNewNames():
	volumePattern = re.compile("v\d+", re.IGNORECASE)
	uniqueChapterPattern = re.compile("c\d+", re.IGNORECASE)
	multipleChapterPattern = re.compile("c\d+\-\d+", re.IGNORECASE)

	for file in os.listdir():
		volumeFile = volumePattern.search(file)
		uniqueChapterFile = uniqueChapterPattern.search(file)
		multipleChapterFile = multipleChapterPattern.search(file)
		newFileName = ""
		
		if volumeFile != None:
			newFileName += "Vol " + str(volumeFile.group()[1:]).zfill(3) + " "
		if multipleChapterFile != None:
			newFileName += "Ch " + multipleChapterFile.group()[1:]
		elif uniqueChapterFile != None:
			newFileName += "Ch " + str(uniqueChapterFile.group()[1:]).zfill(3)
		
		if newFileName == "":
			continue

		newFileName += file[-4:]
		renameFile(file, newFileName)


def main():
	generateNewNames()
	
main()
f.close()
print ('****************Operation has ended*****************')
print ('For information check the log.txt file')