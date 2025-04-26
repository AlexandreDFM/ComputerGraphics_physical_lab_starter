#include "MySpring.h"

namespace cyclone {
    MySpring::MySpring(cyclone::Particle* p, double springConstant, double restLength)
        : other(p), springConstant(springConstant), restLength(restLength) {}

    void MySpring::updateForce(Particle* particle, double duration) {
        // Calculate the vector of the spring
        Vector3 force = particle->getPosition();
        force -= other->getPosition(); // d = p - other

        // Calculate the magnitude of the force
        const double length = force.magnitude();
        const double deltaLength = length - restLength;

        // Normalize the force and apply Hooke's law
        force.normalise();
        force *= -springConstant * deltaLength; // f = -k * (d - l0) * d̂

        // Apply the force to the particle
        particle->addForce(force);
    }
}