#ifndef GDDrawOrbit_H
#define GDDrawOrbit_H
#define PI           3.14159265358979323846  /* pi */
#include <godot_cpp/classes/Node2D.hpp>
#include <godot_cpp/classes/Curve2D.hpp>
#include <godot_cpp/classes/Path2D.hpp>
#include <godot_cpp/classes/ref.hpp>

namespace godot {

class GDDrawOrbit : public Path2D {
	GDCLASS(GDDrawOrbit, Path2D)
	
private:
	double time_passed;
	


protected:
	static void _bind_methods();

public:
	GDDrawOrbit();
	~GDDrawOrbit();
    void _draw();
	Ref<Curve2D> curve;
	PackedVector2Array points;
	// Ref<Curve2D> get_curve();
	//void set_curve(Ref<Curve2D> curve);
    void _makecurve();
	void _ready();
	void _process(double delta);
};

}

#endif