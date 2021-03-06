#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kp = Kp_;
  this->Kd = Kd_;
  this->Ki = Ki_;
  Ep = 0.0;
  Ed = 0.0;
  Ei = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  Ed = cte - Ep;
  Ep = cte;
  Ei += cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double Et = 0.0;
  Et = -Kp*Ep -Kd*Ed -Ki*Ei;
  return Et;  // TODO: Add your total error calc here!
}