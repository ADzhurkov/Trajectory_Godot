#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/Node3D.hpp>



namespace godot {

class GDExample : public Node3D {
	GDCLASS(GDExample, Node3D)

private:
	double time_passed;

protected:
	static void _bind_methods();

public:
	GDExample();
	~GDExample();

	void _process(double delta);
};

}

#endif