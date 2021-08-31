// Gmsh project created on Tue Aug 31 09:52:04 2021//+
Point(1) = {0, 1, 0, 1.0};
//+
Point(2) = {1.5, 0.75, 0, 1.0};
//+
Point(3) = {2.25, 0, 0, 1.0};
//+
Point(4) = {1.5, -0.75, 0, 1.0};
//+
Point(5) = {0, -1, 0, 1.0};
//+
Point(6) = {0.5, 0, 0, 1.0};
//+
Point(7) = {0.75, 0, 0, 1.0};
//+
BSpline(1) = {1, 6, 5};
//+
Point(8) = {1.5, 0, 0, 1.0};//+
Circle(2) = {4, 8, 2};
//+
Point(9) = {0.75, 0.5, 0, 1.0};
//+
Point(10) = {0.75, -0.5, 0, 1.0};
//+
Line(3) = {1, 9};
//+
Line(4) = {5, 10};
//+
Delete {
  Curve{2}; 
}
//+
Circle(5) = {10, 8, 9};
//+
Delete {
  Curve{5}; 
}
//+
Circle(5) = {9, 8, 10};
//+
Delete {
  Curve{5}; 
}
//+
Circle(5) = {9, 8, 10};
//+
Circle(6) = {10, 8, 9};
//+
Delete {
  Curve{5}; 
}
//+
Delete {
  Curve{6}; 
}
//+
BSpline(5) = {9, 2, 3, 4, 10};
//+
Delete {
  Curve{5}; 
}
//+
Point(11) = {1.5, 1, 0, 1.0};
//+
Point(12) = {1.5, -1, 0, 1.0};
//+
Point(13) = {2.5, 0, 0, 1.0};
//+
BSpline(5) = {9, 11, 13, 12, 10};
//+
Point(14) = {1.5, 1.5, 0, 1.0};
//+
Point(15) = {1.5, -1.5, 0, 1.0};
//+
Point(16) = {3, 0, 0, 1.0};
//+
BSpline(6) = {9, 14, 16, 15, 10};
//+
Point(17) = {4, -0, 0, 1.0};
//+
BSpline(7) = {9, 14, 17, 15, 10};
//+
Delete {
  Curve{5}; 
}
//+
Delete {
  Curve{6}; 
}
//+
Curve Loop(1) = {1, 4, -7, -3};
//+
Plane Surface(1) = {1};
//+
Extrude {0, 0, -0.5} {
  Surface{1}; 
}
//+
Surface Loop(1) = {16, 1, 20, 24, 28, 29};
//+
Volume(2) = {1};
//+
Physical Surface("tail") = {16};
//+
Physical Surface("top_fin") = {28};
//+
Physical Surface("bottom_fin") = {20};
//+
Physical Surface("head") = {24};
//+
Physical Surface("front_face") = {1};
//+
Physical Surface("back_face") = {29};
