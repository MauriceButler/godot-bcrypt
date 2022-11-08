#ifndef GODOT_BCRYPT_H
#define GODOT_BCRYPT_H

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class GodotBcrypt : public Node
{
	GDCLASS(GodotBcrypt, Node);

protected:
	static void _bind_methods();

private:
public:
	GodotBcrypt();
	~GodotBcrypt();

	static String hash(String password, int rounds = 11);
	static bool compare(String password, String hash);
};

#endif
