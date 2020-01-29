MAPPER
========

GOAL
------
Store a map containing world data accumulated from sensors.

------------
Map Contents
------------

### Robot Location

- Current `x` position
- Current `y` position
- Current `theta_z` (global) rotation
- ? Current `z` position
- ? Current `theta_(x/y)` (global/local) rotations


### Terrain / Obstacles

Obstacles need to bes stored so the robot knows where it can('t) travel.
This can be implemented in various ways:

#### Binary Format

Obstacles are stored as a binary - at a given location, either there is an obstacle or there isn't.

Pros:
- Simplicity

Cons:
- If the robot's `z` location changes (the robot drives up or down an incline), then the obstacles won't update/change.
- Cannot keep track of directional obstacles (a ramp with a cliff at the end of it).

#### Height / Gradient

Obstacles are not explicitly stored. Rather, calculated `z` or `delta_z` values are stored. 

Pros:
- Reduces number of false positives in obstacles. Allows for actual temporal latency of data. New data does not overwrite existing data; It enhances it.
- Cool Renderings

Cons:
- Makes path planning more complex (3d vs naive 2d)
- Complexity. More memory is needed to store the map.

---
## Functions
- init (params) -> ()
- get entire map () -> (image / array)
- update map (location, terrain) -> ()
- copy () -> (mapper)
- ? reset / destroy
- get robot surroundings () -> (image / array)
- get surroundings (location) -> (image / array)
- get location () -> (location)

---
## Future Optimizations
- Default to a really big array -> Cut down on reallocs
- Use a 2d linked list of tiles to makeup the map -> Do no reallocs
- Use some other weird data structure
- Use some form of caching/batching
5. Do it in C/++

---
## Enhancements
- Store all data -> show robot map over time
