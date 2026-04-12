data = [
    112, 120, 124, 120, 117, 129, 123, 131, 108, 117, 125, 120, 115, 124, 121, 121, 
    124, 122, 125, 129, 124, 110, 110, 117, 130, 142, 146, 131, 123, 109, 101, 96, 
    145, 146, 150, 140, 121, 104, 88, 87, 130, 144, 147, 125, 122, 99, 92, 94, 
    111, 131, 127, 130, 115, 104, 103, 98, 117, 129, 143, 124, 111, 105, 102, 92
]

with open("image_test_bin.pgm", "wb") as f:
    # L'en-tête est toujours en texte (ASCII) même en format binaire
    f.write(b"P5\n8 8\n255\n")
    # Les pixels sont écrits en binaire (octets bruts)
    f.write(bytearray(data))

print("Fichier image_test_bin.pgm généré !")