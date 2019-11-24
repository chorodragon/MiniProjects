ipAdresses = ["127.0.0.1", ".192.168.1.1", "10.0.12344.255","172.23", "255."]

sections = 0
inside = 0 
sectionLenght = 0

for ipAdress in ipAdresses:
	print('Adress: ' + ipAdress)
	for section in ipAdress:
		if inside == 1:	
			if section not in "1234567890":
				inside = 0
				sections += 1
				print ('Section #{0} Lenght: {1}'.format(sections, sectionLenght))
				sectionLenght = 0
			else:
				sectionLenght += 1 
		else:
		
			if section in "1234567890":
				inside = 1
				sectionLenght += 1
	
	if inside == 1:
		sections += 1
		print ('Section #{0} Lenght: {1}'.format(sections, sectionLenght))
	
	print ('Secciones: ' + str(sections))
	sections = 0
	sectionLenght = 0
	inside = 0