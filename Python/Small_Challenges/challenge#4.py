imelda = "More mayhem", "Imelda May", 2011, ((1, "Pulling the ring"), (2, "Psycho"), (3, "Mayhem"), (3, "Kentish"))

album, artist, year, tracks = imelda

print("Album: {0}".format(album))
print("Artis: {0}".format(artist))
print("Year: {0}".format(year))

print("Tracks:")
for track in tracks:
	numberTrack, titleTrack = track
	print("\tTrack number: {0}, title: {1}".format(numberTrack, titleTrack))
