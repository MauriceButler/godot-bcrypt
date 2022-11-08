# godot-bcrypt

Godot bindings as a wrapper for bcrypt

## Dependencies

1. Fetch sub modules ([godot-cpp](https://github.com/godotengine/godot-cpp) and [libbcrypt](https://github.com/trusch/libbcrypt)) by running

```bash
git submodule update --init --recursive
```

### Compile godot-cpp

To generate and compile the bindings, use this command (replacing <platform> with `linux`, `macos`, `windows`, `android`, `ios` or `javascript` depending on your OS / target).

```bash
cd godot-cpp
scons platform=<platform> generate_bindings=yes
cd ..
```

For more detailed instructions and options checkout the offical [documentation](https://docs.godotengine.org/en/stable/tutorials/scripting/gdnative/gdnative_cpp_example.html#building-the-c-bindings)

### Compile libbcrypt

```bash
cd libbcrypt
mkdir build
cd build
cmake ..
make
cd ..
```

## Compile godot-bcrypt

Once the dependencies have been compiled, to build this library just run

```bash
scons
```

This will compile the library and place it in the `bcryptDemo/bin` directory, along with the `godotBcrypt.gdextension` file

## Using the library

Once thats done, open the `bcryptDemo` application in Godot, and open the `bcryptDemo.gd` file to see the usage.

```python
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
```

Run the application to see the output.
