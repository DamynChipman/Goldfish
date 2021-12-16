#include <FVFluxVelocityU.h>

registerMooseObject("GoldfishApp", FVFluxVelocityU);

InputParameters FVFluxVelocityU::validParams() {
    InputParameters params = FVFluxKernel::validParams();
    params.addClassDescription(
        "Finite volume kernel for shallow water equations. This is the x-component of velocity flux term: `u _u_ * _n_ + g h n_x`"
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
        "velocity_v",
        "Y-component of velocity (meridional velocity)."
    );

    return params;
}

FVFluxVelocityU::FVFluxVelocityU(const InputParameters & parameters) :
    FVFluxKernel(parameters),
    _gravity(getParam<Real>("gravity")),
    _vel_v(adCoupledValue("velocity_v")),
    _height(adCoupledValue("height"))
        {}

ADReal FVFluxVelocityU::computeQpResidual() {
    auto _u_dot_n = _u_elem[_qp] * _normal(0) + _vel_v[_qp] * _normal(1);
    auto _nx = _normal(0);
    auto _ny = _normal(1);

    return _u_elem[_qp] * _u_dot_n + _gravity * _height[_qp] * _nx;
}