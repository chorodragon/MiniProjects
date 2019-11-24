import os
import re

def moveFile(fileToMove, destinyDir):
	print('\nMoving {0} to directory: {1}'.format(fileToMove, destinyDir))
	destiny = destinyDir + fileToMove
	try:
		os.rename(fileToMove, destiny)
	except FileExistsError:
		print ('Error when moving file {0} to {1}'.format(fileToMove, os.getcwd()))
		print ('File already exists on destiny directory\n')
	except:
		print ('Error when moving file {0} to {1}\n'.format(fileToMove, os.getcwd()))

def searchAndMoveFiles(destiny, userPattern):
	try:
		pattern = re.compile(userPattern)
	except:
		print('Pattern isn\'t valid')
		print('You must use regular expressions for the pattern')
		quit()
	
	for content in os.listdir():
		if pattern.match(content) and not os.path.isdir(content):
			moveFile(content, destiny)
		elif os.path.isdir(content) and (os.getcwd() + "\\" + content + "\\") != destiny:
			os.chdir(content)
			searchAndMoveFiles(destiny, userPattern)
			os.chdir("../")


def main():
	# Gets the destiny and test if the directory exists
	destinyDirectory = input ('Ingrese el nombre del directorio destino: ')
	destinyDirectory = os.getcwd() + "\\" + destinyDirectory + "\\"
	if not os.path.isdir(destinyDirectory):
		print ('The directory doesn\'t exist')
		print ('Creating directory...')
		os.mkdir (destinyDirectory)
		print ('Done!!!')

	# Name pattern to look for
	# Check this later
	patternToUse = input ('Ingrese el patron a buscar: ')

	searchAndMoveFiles(destinyDirectory, patternToUse)


main()
print ('\n**********************Operation has ended*********************')