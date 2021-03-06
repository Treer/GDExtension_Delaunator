

#include "gddelaunator.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "delaunator.hpp"

using namespace godot;

void Delaunator::_bind_methods() {
	
  // Constants
	BIND_CONSTANT(INVALID_INDEX);

  // Functions
	ClassDB::bind_method(D_METHOD("from"), &Delaunator::from);
	
  // Properties
	ClassDB::bind_method(D_METHOD("get_triangles"), &Delaunator::get_triangles);
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "triangles"), NULL, "get_triangles");

	ClassDB::bind_method(D_METHOD("get_halfedges"), &Delaunator::get_halfedges);
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "halfedges"), NULL, "get_halfedges");

	ClassDB::bind_method(D_METHOD("get_hull"), &Delaunator::get_hull);
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "hull"), NULL, "get_hull");

	ClassDB::bind_method(D_METHOD("get_hull_area"), &Delaunator::get_hull_area);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hull_area"), NULL, "get_hull_area");

	ClassDB::bind_method(D_METHOD("get_compile_time"), &Delaunator::get_compile_time);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "compile_time"), NULL, "get_compile_time");
}

Delaunator::Delaunator() {
	//UtilityFunctions::print("Delaunator Constructor.");
  delaunator = NULL;
}

Delaunator::~Delaunator() {
	//UtilityFunctions::print("Delaunator Destructor.");
  if (delaunator) delete(delaunator);
  delaunator = NULL;
}

void Delaunator::from(PackedVector2Array points) {
  
  if (delaunator) delete(delaunator);
  delaunator = new delaunator_cpp::Delaunator(points);
}

PackedInt32Array Delaunator::get_triangles() {

  PackedInt32Array result;

  if(delaunator) {
    std::size_t size = delaunator->triangles.size();
    result.resize(size);

    for(std::size_t i = 0; i < size; i++) {
      result.set(i, delaunator->triangles[i]);
    }
  }
  return result;
}


PackedInt32Array Delaunator::get_halfedges() {

  PackedInt32Array result;

  if(delaunator) {
    std::size_t size = delaunator->halfedges.size();
    result.resize(size);

    for(std::size_t i = 0; i < size; i++) {
      result.set(i, delaunator->halfedges[i]);
    }
  }
  return result;
}

PackedInt32Array Delaunator::get_hull() {

  PackedInt32Array result;

  if(delaunator) {

    size_t e = delaunator->hull_start;
    do {
      result.push_back(static_cast<int32_t>(e));
      e = delaunator->hull_next[e];
    } while (e != delaunator->hull_start);
  }
  return result;
}

float Delaunator::get_hull_area() {

  PackedInt32Array result;

  if(delaunator) {
    //return static_cast<float>(delaunator->get_triangle_area()); // used to check get_hull_area() value
    return static_cast<float>(delaunator->get_hull_area());    
  }
  return std::numeric_limits<float>::quiet_NaN();
}

String Delaunator::get_compile_time() {
  return __TIME__;
}
