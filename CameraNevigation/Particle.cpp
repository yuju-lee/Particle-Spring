#include "Particle.h"
#include <stdio.h>

Particle::Particle()
{
}


Particle::~Particle()
{
}

void Particle::Integrate(double dt)
{
	if (m_InverseMass <= 0.0f) {
		return;
	}

	Vec3<double> acc = m_Acceleration; 
	acc += m_Force * m_InverseMass;

	m_Velocity += acc * dt;
	m_Velocity *= pow(m_Damping, dt);
	m_Position += m_Velocity * dt;
	
	ClearForce();
}