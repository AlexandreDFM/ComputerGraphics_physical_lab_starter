#ifndef MOVERFACTORY_H
#define MOVERFACTORY_H

#include "Mover.h"
#include "MoverConnection.h"
#include <map>
#include <vector>

class MoverFactory {
public:
    // Singleton pattern to ensure a single instance of the factory
    static MoverFactory& getInstance() {
        static MoverFactory instance;
        return instance;
    }

    // Create a single Mover
    Mover* createMover(const cyclone::Vector3& position = cyclone::Vector3(0, 3, 0),
                       const cyclone::Vector3& velocity = cyclone::Vector3(0, 0, 0),
                       const cyclone::Vector3& acceleration = cyclone::Vector3(0, 0, 0),
                       float mass = 1.0f, float damping = 0.99f);

    // Create a MoverConnection
    MoverConnection* createMoverConnection();

    // Get all created Movers
    const std::map<int, Mover*>& getMovers() const { return m_movers; }

    // Clean up all created objects
    void cleanup();

private:
    // Private constructor for Singleton
    MoverFactory() = default;

    // Disable copy constructor and assignment operator
    MoverFactory(const MoverFactory&) = delete;
    MoverFactory& operator=(const MoverFactory&) = delete;

    std::map<int, Mover*> m_movers; // Store all Movers by their ID
    std::vector<MoverConnection*> m_connections; // Store all MoverConnections
};

#endif // MOVERFACTORY_H
