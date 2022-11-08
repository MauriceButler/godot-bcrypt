extends Node2D

func _ready():
	var password = "SuperSecretPassword"
	var hash1 = GodotBcrypt.hash(password)
	var hash2 = GodotBcrypt.hash(password, 15)

	print("Password: ", password)
	print("Hash1: ", hash1)
	print("Hash2: ", hash2)
	
	print("Matches hash1: ", GodotBcrypt.compare(password, hash1))
	print("Matches hash2: ", GodotBcrypt.compare(password, hash2))
	
	print("Matches incorrect password: ", GodotBcrypt.compare("IncorrectPassword", hash1))
	print("Matches incorrect hash: ", GodotBcrypt.compare(password, "IncorrectHash"))
	
