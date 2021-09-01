#include "SoilSurfaceFunction.h"

registerMooseObject("GoldfishApp", SoilSurfaceFunction);

InputParameters SoilSurfaceFunction::validParams() {
	InputParameters params = Function::validParams();
	params.addClassDescription(
		"Stores the surface temperature function."
	);
	params.addRequiredParam<Real>(
		"meanAnnualTemperature",
		"The mean annual temperature of the surface."
	);
	params.addRequiredParam<Real>(
		"amplitude",
		"Amplitude of oscillation about the mean annual temperature."
	);

	return params;
}

SoilSurfaceFunction::SoilSurfaceFunction(const InputParameters & parameters) :
	Function(parameters),
	_meanAnnualTemperature(getParam<Real>("meanAnnualTemperature")),
	_amplitude(getParam<Real>("amplitude"))
		{}

Real SoilSurfaceFunction::value(Real t, const Point & p) const {
	return _meanAnnualTemperature + _amplitude * std::sin((2.0*M_PI/(365.0 * 24 * 3600)) * t);
}