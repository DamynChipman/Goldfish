#ifndef SOIL_SURFACE_FUNCTION_H_
#define SOIL_SURFACE_FUNCTION_H_
#pragma once

#include "Function.h"
#include <math.h>

class SoilSurfaceFunction : public Function {
public:
	static InputParameters validParams();
	SoilSurfaceFunction(const InputParameters & parameters);
	virtual Real value(Real t, const Point & p) const override;

protected:
	const Real & _meanAnnualTemperature;
	const Real & _amplitude;

};

#endif // SOIL_SURFACE_FUNCTION_H_