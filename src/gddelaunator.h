#ifndef GDDELAUNATOR_CLASS_H
#define GDDELAUNATOR_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref_counted.hpp>
//#include <godot_cpp/classes/global_constants.hpp>
//#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

namespace delaunator_cpp {
	class Delaunator;
}


class Delaunator : public RefCounted {
	GDCLASS(Delaunator, RefCounted);

protected:
	static void _bind_methods();

private:
	delaunator_cpp::Delaunator *delaunator;

public:

	Delaunator();
	~Delaunator();

	enum {
		INVALID_INDEX = static_cast<int32_t>(std::numeric_limits<std::size_t>::max()) // -1 when exposed to godot as a signed int
	};

	// Functions
	void from(const PackedVector2Array &points);

	// Properties
	PackedInt32Array get_triangles();
	PackedInt32Array get_halfedges();
	PackedInt32Array get_hull();
	float get_hull_area();
};

#endif // ! GDDELAUNATOR_CLASS_H
