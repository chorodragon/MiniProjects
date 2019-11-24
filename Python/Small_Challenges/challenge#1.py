name = input('Please enter your name: ')
age = int(input('{0} please enter your age: '.format(name)))

if 18 < age < 31:
	print('Welcome {0}'.format(name))
else:
	print('Fuck off!')
