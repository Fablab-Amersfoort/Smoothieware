#include "CartesianSolution.h"
#include "ActuatorCoordinates.h"
#include "checksumm.h"
#include "ConfigValue.h"
#include <math.h>

#define cartesian_swap_yz_checksum   CHECKSUM("cartesian_swap_yz")

CartesianSolution::CartesianSolution(Config* config) {
    if (config->value(cartesian_swap_yz_checksum)->by_default(false)->as_bool()) {
        axis_to_actuator[Y_AXIS] = GAMMA_STEPPER;
        axis_to_actuator[Z_AXIS] = BETA_STEPPER;
    }
}

void CartesianSolution::cartesian_to_actuator( const float cartesian_mm[], ActuatorCoordinates &actuator_mm ) const {
    actuator_mm[axis_to_actuator[X_AXIS]] = cartesian_mm[X_AXIS];
    actuator_mm[axis_to_actuator[Y_AXIS] ] = cartesian_mm[Y_AXIS];
    actuator_mm[axis_to_actuator[Z_AXIS]] = cartesian_mm[Z_AXIS];
}

void CartesianSolution::actuator_to_cartesian( const ActuatorCoordinates &actuator_mm, float cartesian_mm[] ) const {
    cartesian_mm[X_AXIS] = actuator_mm[axis_to_actuator[X_AXIS]];
    cartesian_mm[Y_AXIS ] = actuator_mm[axis_to_actuator[Y_AXIS]];
    cartesian_mm[Z_AXIS] = actuator_mm[axis_to_actuator[Z_AXIS]];
}
