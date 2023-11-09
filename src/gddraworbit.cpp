#include "GDDrawOrbit_H.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


using namespace godot;

void GDDrawOrbit::_bind_methods() {
    // ClassDB::bind_method(D_METHOD("get_curve"), &GDDrawOrbit::get_curve);
    // ClassDB::bind_method(D_METHOD("set_curve","p_curve"), &GDDrawOrbit::set_curve);
    // ClassDB::add_property("GDDrawOrbit", PropertyInfo(Variant::Ref<Curve2D>, "curve"), "set_curve", "get_curve");

    // ClassDB::bind_method(D_METHOD("get_curve"), &GDDrawOrbit::get_curve);
    // ClassDB::bind_method(D_METHOD("set_curve", "newcurve"), &GDDrawOrbit::set_curve);
    // ADD_PROPERTY(PropertyInfo(GetTypeInfo<decltype(GDDrawOrbit::curve)>::VARIANT_TYPE, "curve"), "set_curve", "get_curve");


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
    float a{400};
    float b{350};
    float c{sqrt(pow(a,2)+pow(b,2))};
    float e{c/a};
    float focus{a*e};
    int t = 360*2;

    int x{10};
    int y{10};
    // curve->add_point(Vector2(0,0));
    // curve->add_point(Vector2(10,10));
    // curve->add_point(Vector2(20,20));
    for (int i = 0; i <t ; i++) {
        x = a*cos(i*PI/360);
        y = b*sin(i*PI/360);
        //points.append(Vector2(x,y));
        
        curve->add_point(Vector2(x,y));
    }
    //points.append_array(curve.get_baked_points());
}
 void  GDDrawOrbit::_draw() {  
    double a{2000};
    double focus{a*0.5};

    draw_polyline(curve->get_baked_points(), Color(255, 255, 255, 1));
    draw_circle(Vector2(focus,0),float(10),Color(0,255,0,1));
}

void GDDrawOrbit::_process(double delta) {
}

// void GDDrawOrbit::set_curve(Ref<Curve2D> newcurve) {
// 	curve = newcurve;
// }

// Ref<Curve2D> GDDrawOrbit::get_curve() {
// 	return curve;
// }