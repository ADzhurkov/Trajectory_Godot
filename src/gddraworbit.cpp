#include "GDDrawOrbit_H.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


using namespace godot;

void GDDrawOrbit::_bind_methods() {
    // ClassDB::bind_method(D_METHOD("get_curve"), &GDDrawOrbit::get_curve);
    // ClassDB::bind_method(D_METHOD("set_curve","p_curve"), &GDDrawOrbit::set_curve);
    // ClassDB::add_property("GDDrawOrbit", PropertyInfo(Variant::Ref<Curve2D>, "curve"), "set_curve", "get_curve");

    ClassDB::bind_method(D_METHOD("get_a"), &GDDrawOrbit::get_a);
    ClassDB::bind_method(D_METHOD("set_a", "p_a"), &GDDrawOrbit::set_a);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,"a"),"set_a","get_a");

    ClassDB::bind_method(D_METHOD("get_e"), &GDDrawOrbit::get_e);
    ClassDB::bind_method(D_METHOD("set_e", "p_e"), &GDDrawOrbit::set_e);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,"e"),"set_e","get_e");


    //ADD_PROPERTY(PropertyInfo(GetTypeInfo<decltype(GDDrawOrbit::curve)>::VARIANT_TYPE, "curve"), "set_curve", "get_curve");


}





GDDrawOrbit::GDDrawOrbit() {
	// Initialize any variables here.
    curve.instantiate();
    //_draw(); 
}

GDDrawOrbit::~GDDrawOrbit() {
	// Add your cleanup here.
}

void GDDrawOrbit::_ready(){
    //Ref<Curve2D> curve = Curve2D::new();
    //curve.instantiate();
    _makecurve(); //calculates and adds points to curve
    _draw();      //draws the path
    set_curve(curve);
    UtilityFunctions::print("This is curve",curve);
    UtilityFunctions::print("Hello World from OrbitDrawer");
}

void GDDrawOrbit::_makecurve(){
    
    //double b{350};
    //float c{e*a};
    float b{a*sqrt(1-pow(e,2))};
    //double c{sqrt(pow(a,2)+pow(b,2))};
    //double e{c/a};
    float focus{a*e};
    int t{360*2};

    int x{10};
    int y{10};
    for (int i = 0; i <t ; i++) {
        x = a*cos(i*PI/360);
        y = b*sin(i*PI/360);
        
        curve->add_point(Vector2(x,y));
    }
 
}
 void  GDDrawOrbit::_draw() {  
    //float a = semi_major;
    float focus{a*e};

    draw_polyline(curve->get_baked_points(), Color(255, 255, 255, 1));
    draw_circle(Vector2(focus,0),float(10),Color(0,255,0,1));
}

void GDDrawOrbit::_process(double delta) {
}

void GDDrawOrbit::set_a(float p_a) {
	a = p_a;
}

float GDDrawOrbit::get_a() {
	return a;
}

void GDDrawOrbit::set_e(float p_e) {
	e = p_e;
}

float GDDrawOrbit::get_e() {
	return e;
}