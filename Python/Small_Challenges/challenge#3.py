import random

highest = 10000
randAnswer = random.randint(1, highest)
userAnswer = -1

while randAnswer != userAnswer and userAnswer != 0:
	userAnswer = int(input('Adivina el numero entre 1 y {0}: '.format(highest)))
	if userAnswer < randAnswer:
		print('La respuesta es mayor')
	else:
		print('La respuesta es menor')

if userAnswer == 0:
	print ('Lo lamento, has perdido :(')
else:
	print ('Felicidades, has adivinado el numero :)')