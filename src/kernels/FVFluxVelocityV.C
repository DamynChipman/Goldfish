#include <FVFluxVelocityV.h>

registerMooseObject("GoldfishApp", FVFluxVelocityV);

InputParameters FVFluxVelocityV::validParams() {
    InputParameters params = FVFluxKernel::validParams();
    params.addClassDescription(
        "Finite volume kernel for shallow water equations. This is the y-component of velocity flux term: `v _u_ * _n_ + g h n_y`"
    );
    params.addParam<Real>(
        "gravity",
        9.81,
        "Gravitational constant [m/s^2]."
    );
    params.addRequiredCoupledVar(
        "height",
        "Height."
    );
    params.addRequiredCoupledVar(
        "velocity_u",
        "X-component of velocity (zonal velocity)."
    );

    return params;
}

FVFluxVelocityV::FVFluxVelocityV(const InputParameters & parameters) :
    FVFluxKernel(parameters),
    _gravity(getParam<Real>("gravity")),
    _vel_u(adCoupledValue("velocity_u")),
    _height(adCoupledValue("height"))
        {}

ADReal FVFluxVelocityV::computeQpResidual() {
    auto _u_dot_n = _vel_u[_qp] * _normal(0) + _u_elem[_qp] * _normal(1);
    auto _nx = _normal(0);
    auto _ny = _normal(1);

    return _u_elem[_qp] * _u_dot_n + _gravity * _height[_qp] * _ny;
}