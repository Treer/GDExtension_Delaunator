#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>


#include "gddelaunator.h"

using namespace godot;

void register_delaunator_types() {
	ClassDB::register_class<Delaunator>();
}

void unregister_delaunator_types() {}

extern "C" {

// Initialization.

GDNativeBool GDN_EXPORT gdextension_delaunator_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_scene_initializer(register_delaunator_types);
	init_obj.register_scene_terminator(unregister_delaunator_types);

	return init_obj.init();
}
}
