#include "PID.h"

//using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
	cte = 0.0;
	diff_cte = 0.0;
	total_error = 0.0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

void PID::UpdateError(double cte) {
	this->diff_cte = cte - this->cte;
	this->cte = cte;
	this->total_error += cte;
}

double PID::TotalError() {
	return total_error;
}

double PID::getOutput() {
	double output = -(this->Kp*cte + this->Ki*total_error  + this->Kd*diff_cte);
	if (output < -1.0) output = -1.0;
	if (output > 1.0) output = 1.0;
	return output;
}
