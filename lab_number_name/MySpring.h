// MySpring.h
#ifndef MYSPRING_H
#define MYSPRING_H

#include "pfgen.h"

namespace cyclone {
    class MySpring : public ParticleForceGenerator {
    public:
        MySpring(Particle *p, double springConstant, double restLength);
        void updateForce(Particle *particle, double duration) override;

    private:
        Particle *other;
        double springConstant;
        double restLength;
    };
} // namespace cyclone

#endif // MYSPRING_H
