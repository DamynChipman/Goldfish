#include <FVFluxHeight.h>

registerMooseObject("GoldfishApp", FVFluxHeight);

InputParameters FVFluxHeight::validParams() {
    InputParameters params = FVFluxKernel::validParams();
    params.addClassDescription(
        "Finite volume kernel for shallow water equations. This is the height flux term: `(H + h)(_u_ * _n_)`"
    );
    params.addParam<Real>(
        "mean_height",
        0,
        "Mean height of the horizontal pressure surface."
    );
    params.addRequiredCoupledVar(
        "velocity_u",
        "X-component of velocity (zonal velocity)."
    );
    params.addRequiredCoupledVar(
        "velocity_v",
        "Y-component of velocity (meridional velocity)."
    );

    return params;
}

FVFluxHeight::FVFluxHeight(const InputParameters & parameters) :
    FVFluxKernel(parameters),
    _meanHeight(getParam<Real>("mean_height")),
    _vel_u(adCoupledValue("velocity_u")),
    _vel_v(adCoupledValue("velocity_v"))
        {}

ADReal FVFluxHeight::computeQpResidual() {
    auto _u_dot_n = _vel_u[_qp] * _normal(0) + _vel_v[_qp] * _normal(1);
    return (_meanHeight + _u_elem[_qp]) * _u_dot_n;
}