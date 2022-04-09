[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT) ![example workflow](https://github.com/Treer/GDExtension_Delaunator/actions/workflows/build.yml/badge.svg)
# Delaunator GDExtension for Godot 4

A fast library for Delaunay triangulation.

This GDExtension is still in alpha.

See [Delaunator guide](https://mapbox.github.io/delaunator/) (how to get Voronoi polygons etc.) and [API reference](https://github.com/mapbox/delaunator#api-reference) for interim details, as documentation here is a work in progress

## Installation
Download `delaunator_gdextension.zip` from [the latest Release page](https://github.com/Treer/GDExtension_Delaunator/releases/latest) and copy the `delaunator_gdextension` folder from inside the zip file into your project's `addons` folder.

It supports Windows and Linux.

## Example GDScript
```gdscript
var delaunator = Delaunator.new();

var points = [Vector2(1,1), Vector2(10, 0), Vector2(5, 1), Vector2(1, 5)];
delaunator.from(PackedVector2Array(points));
    
prints("Delaunator triangles:", delaunator.triangles)
prints("           half edges:", delaunator.halfedges)
prints("           hull:", delaunator.hull)
prints("           hull area:", delaunator.hull_area)

points = [Vector2(-1,1), Vector2(1, 1), Vector2(1, -1), Vector2(-1, -1)];
delaunator.from(PackedVector2Array(points));

prints("Delaunator triangles:", delaunator.triangles)
prints("           half edges:", delaunator.halfedges)
prints("           hull:", delaunator.hull)
prints("           hull area:", delaunator.hull_area)
```

Note that currently the array is copied back into Godot every time a property is accessed, so take a GDScript copy of it rather than accessing the property more than once.

## Suggested work remaining
Any help appreciated

* [x] Github actions, so nobody needs to setup a build environment to use this
* [ ] C# bindings
* [ ] Optimization (lots of low-hanging memory gains if delaunator_cpp is switched to operating on Godot types directly)
* [ ] Godot example project & documentation

## Acknowledgements
* Volodymyr Bilonenko, [ported Delaunator to C++](https://github.com/delfrrr/delaunator-cpp) (MIT)
* Andrew Bell, [worked on Delaunator C++](https://github.com/abellgithub/delaunator-cpp)
* Unknown, [GDExtension Project Creator](https://github.com/nonunknown/gdextension-creator) (MIT)
