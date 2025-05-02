#ifndef MOVER_H
#define MOVER_H

#if defined(_WIN32) || defined(_WIN64)
#include "windows.h"
#endif

#include <GL/glut.h>
#include <functional>
#include <map>

#include "MySpring.h"
#include "core.h"
#include "iostream"
#include "particle.h"
#include "pfgen.h"

class Mover {
public:
    enum projectileType { BASE, WIND, LASER, FIREBALL, ARTILLERY, PISTOL };
    Mover();
    Mover(cyclone::Vector3 pos, cyclone::Vector3 vel, cyclone::Vector3 acc, float mass, float damping);
    explicit Mover(const cyclone::Vector3 &initPosition);

    ~Mover();

    void draw(int shadow) const;

    void update(float duration);
    void updateColor(float duration);

    void stop();
    void checkEdges() const;
    void setBase();
    void setWind();
    void setLaser();
    void setFireball();
    void setArtillery();
    void setPistol();
    void setConnection(Mover *other);
    void reset();
    float getSize() const { return size; }
    int getId() const { return _id; }
    void setProjectileType(projectileType type) { projectileType = type; }
    [[nodiscard]] projectileType getProjectileType() const { return projectileType; }
    static std::map<projectileType, const char *> getProjectileModeType() {
        return {{BASE, "BASE"},         {WIND, "WIND"},           {LASER, "LASER"},
                {FIREBALL, "FIREBALL"}, {ARTILLERY, "ARTILLERY"}, {PISTOL, "PISTOL"}};
    }
    std::map<projectileType, void (Mover::*)()> projectileMap = {
            {BASE, &Mover::setBase},         {WIND, &Mover::setWind},           {LASER, &Mover::setLaser},
            {FIREBALL, &Mover::setFireball}, {ARTILLERY, &Mover::setArtillery}, {PISTOL, &Mover::setPistol}};
    cyclone::Particle *m_particle;
    cyclone::MySpring *m_spring;

private:
    int _id;
    static int idProvider;
    float size = 2.0;
    projectileType projectileType = WIND;
    cyclone::Vector3 m_position = cyclone::Vector3(0, 0, 0);
    cyclone::ParticleGravity *m_gravity;
    cyclone::ParticleDrag *m_drag;
    cyclone::ParticleForceRegistry *m_forces;
    cyclone::Vector3 position = cyclone::Vector3(0, 3, 0);
    cyclone::Vector3 basePosition = cyclone::Vector3(0, 3, 0);
    cyclone::Vector3 ballColor = cyclone::Vector3(0.5, 0.5, 0.5);
};

#endif // MOVER_H
