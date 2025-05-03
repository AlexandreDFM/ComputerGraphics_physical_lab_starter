#include "MoverFactory.h"

Mover* MoverFactory::createMover(const cyclone::Vector3& position,
                                 const cyclone::Vector3& velocity,
                                 const cyclone::Vector3& acceleration,
                                 float mass, float damping) {
    Mover* mover = new Mover(position, velocity, acceleration, mass, damping);
    m_movers[mover->getId()] = mover; // Store the mover by its ID
    return mover;
}

MoverConnection* MoverFactory::createMoverConnection() {
    MoverConnection* connection = new MoverConnection();
    m_connections.push_back(connection);

    // Add Movers from the connection to the factory's map
    connection->setInGlWindowMovers(m_movers);
    return connection;
}

void MoverFactory::cleanup() {
    // Delete all Movers
    for (auto& pair : m_movers) {
        delete pair.second;
    }
    m_movers.clear();

    // Delete all MoverConnections
    for (auto connection : m_connections) {
        delete connection;
    }
    m_connections.clear();
}
