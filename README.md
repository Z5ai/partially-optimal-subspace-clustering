# Partially Optimal Subspace Clustering
This repository implements different algorithms for partial optimality for the cubic clustering problem. It focuses on the special case of clustering, where the underlying graph is fully connected.
## Cubic Clustering
In cubic partitioning triples of elements are considered when calculating the cost for a partitioning instead of 2 elements. This makes sense for some applications.
For example consider some planes that contain the origin and a set of points in the 3D vector space where each point is sampled from one of the planes. When calculating costs for a triple of points, a plane that best fits the points and contains the origin is generated. Then the maximum distance from one of the 3 points to this plane is used to calculate the cost. Partitioning the points such that all points in one partition are sampled from the same plane only makes sense when considering 3 points at a time (as for 2 points there always exists a plane through the origin that contains both points).
## Partial Optimality
With partial optimality criteria it is possible to predecide for some edges, if they should be cut or not without solving the whole clustering problem. This repository implements partial optimality criteria by improving mappings.
## Usage
### Requirements
This Program is only tested on Linux (Ubuntu 22.04).
### Build Project
```sh
$ mkdir build
```
```sh
$ cd build
```
```sh
$ cmake ..
```
```sh
$ make
```
### Run Program
inside build directory:
```sh
$ ./partially_optimal_subspace_clustering {n_planes} {n_vertices_per_plane} {stddev} {mode} {project_path}
```
The following arguments must be set:
- `n_planes`: Number of planes. Recommended value: **3**
- `n_vertices_per_plane`: Number of vertices of plane. Recommended value: **33**
- `stddev`: Standard deviation (sigma). Outlier can be found for equal or smaller than : **0.001**
- `mode`: EDGE_CUT, TRIANGLE_CUT or TRIANGLE_JOIN. Recommended value: **TRIANGLE_CUT**
- `project_path`: Path to project folder, where also source code and dependencies are located. This is necessary, because this program calls other scripts from the project-folder. Example path: **/home/david/partially-optimal-subspace-clustering**
