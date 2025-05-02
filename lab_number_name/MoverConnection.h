// MoverConnection.h
#ifndef MOVERCONNECTION_H
#define MOVERCONNECTION_H

#include <vector>
#include "Mover.h"

class MoverConnection {
public:
    MoverConnection();
    ~MoverConnection();

    void update(float duration) const;
    void updateColor(float duration) const;

    void draw(int shadow) const;

    void setInGlWindowMovers(std::map<int, Mover *> &winMovers);

private:
    cyclone::ParticleForceRegistry *m_forces;
    cyclone::ParticleGravity *m_gravity;
    cyclone::ParticleDrag *m_drag;
    std::vector<Mover *> m_movers;
};

#endif // MOVERCONNECTION_H
