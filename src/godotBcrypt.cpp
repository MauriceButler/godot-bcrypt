#include "godotBcrypt.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include "bcrypt/BCrypt.hpp"

using namespace godot;

void GodotBcrypt::_bind_methods()
{
	ClassDB::bind_static_method("GodotBcrypt", D_METHOD("hash", "password", "rounds"), &GodotBcrypt::hash, DEFVAL(10));
	ClassDB::bind_static_method("GodotBcrypt", D_METHOD("compare", "password", "hash"), &GodotBcrypt::compare);
}

GodotBcrypt::GodotBcrypt()
{
}

GodotBcrypt::~GodotBcrypt()
{
}

String GodotBcrypt::hash(String password, int rounds)
{
	return BCrypt::generateHash(password.utf8().get_data(), rounds).c_str();
}

bool GodotBcrypt::compare(String password, String hash)
{
	return BCrypt::validatePassword(password.utf8().get_data(), hash.utf8().get_data());
}
