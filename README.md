# Delaunator GDExtension for Godot 4

A fast library for Delaunay triangulation.

This GDExtension is still in alpha.

See [Delaunator guide](https://mapbox.github.io/delaunator/) (how to get Voronoi polygons etc.) and [API reference](https://github.com/mapbox/delaunator#api-reference) for interim details, as documentation here is a work in progress

## Installation
[An initial build is available](https://github.com/Treer/GDExtension_Delaunator/suites/5862211168/artifacts/197641652) from the [Actions](https://github.com/Treer/GDExtension_Delaunator/actions) tab, however you will need to have logged into Github to access it.

Copy the `delaunator_gdextension` folder from the zip file into your project's `addons` folder.

It supports Windows and Linux.

## Example GDScript
```gdscript
var delaunator = Delaunator.new();

var points = [Vector2(1,1), Vector2(10, 0), Vector2(5, 1), Vector2(1, 5)];
delaunator.from(PackedVector2Array(points));
    
prints("Delaunator triangles:", delaunator.triangles)
prints("           half edges:", delaunator.halfedges)
prints("           hull:", delaunator.hull)
#prints("           hull area:", delaunator.hull_area) # commented out due to bug - I'd need to retain the double-precision coords array in memory to make this work, or pre-calculate it inside from(), neither of which are justified

points = [Vector2(-1,1), Vector2(1, 1), Vector2(1, -1), Vector2(-1, -1)];
delaunator.from(PackedVector2Array(points));

prints("Delaunator triangles:", delaunator.triangles)
prints("           half edges:", delaunator.halfedges)
prints("           hull:", delaunator.hull)
#prints("           hull area:", delaunator.hull_area) # commented out due to bug - I'd need to retain the double-precision coords array in memory to make this work, or pre-calculate it inside from(), neither of which are justified
```

Note that currently the array is copied back into Godot every time a property is accessed, so take a GDScript copy of it rather than accessing the property more than once.

## Suggested work remaining
Help appreciated... or a link to an existing GDExtensions Delaunator project!

* [x] Github actions, so nobody needs to setup a build environment to use this
* [ ] C# bindings
* [ ] Optimization (lots of low-hanging memory gains if delaunator_cpp is switched to operating on Godot types directly)
* [ ] Godot example project

## Licence

MIT License

Copyright 2022 Treer  
Copyright 2020 Andrew Bell  
Copyright 2018 Volodymyr Bilonenko  
Copyright 2017 Mapbox

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Acknowledgements
* Volodymyr Bilonenko, [ported Delaunator to C++](https://github.com/delfrrr/delaunator-cpp) (MIT)
* Andrew Bell, [worked on Delaunator C++](https://github.com/abellgithub/delaunator-cpp)
* Unknown, [GDExtension Project Creator](https://github.com/nonunknown/gdextension-creator) (MIT)
