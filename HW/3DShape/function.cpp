#include <iostream>
#include <string>
#include "function.h"
using namespace std;

oj::Sphere::Sphere(double r, double pi){
    radius = r;
    pi = pi;
    if(r<0||pi<0){
        Shape3D::setVolume(0);
    }
    else{
        Shape3D::setVolume(4.0/3.0*pi*r*r*r);
    }
}

oj::Cone::Cone(double r, double h, double pi){
    radius = r;
    height = h;
    pi = pi;
    if(r<0||h<0||pi<0){
        Shape3D::setVolume(0);
    }
    else{
        Shape3D::setVolume(1.0/3.0*pi*r*r*h);
    }
}

oj::Cuboid::Cuboid(double l, double w, double h){
    length = l;
    width = w;
    height = h;
    if(l<0||w<0||h<0){
        Shape3D::setVolume(0);
    }
    else{
        Shape3D::setVolume(l*w*h);
    }
}

oj::Cube::Cube(double a):Cuboid(a, a, a){
    if(a<0){
        Shape3D::setVolume(0);
    }
    else{
        Shape3D::setVolume(a*a*a);
    }
}