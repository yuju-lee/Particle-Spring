#include "ParticleSpring.h"


ParticleSpring::ParticleSpring()
{
}

ParticleSpring::ParticleSpring(Particle *other, double k, double restLength)
{
	m_Other = other;
	m_SpringConstant = k;
	m_RestLength = restLength;
}

ParticleSpring::~ParticleSpring()
{
}

void ParticleSpring::UpdateForce(Particle *p, double dt)
{
	Vec3<double> force = p->GetPos() - m_Other->GetPos();
	
	double length = force.Length();
	length = length - m_RestLength;
	length *= m_SpringConstant;

	force.Normalize();
	force *= -length;
	p->AddForce(force);
	p->Integrate(dt);
}

ParticleStiffSpring::ParticleStiffSpring()
{
}

ParticleStiffSpring::ParticleStiffSpring(Particle *other, double k, double damping)
{
	m_Other = other;
	m_SpringConstant = k;
	m_Damping = damping;
}

ParticleStiffSpring::~ParticleStiffSpring()
{
}

void ParticleStiffSpring::UpdateForce(Particle *p, double dt)
{
	Vec3<double> relativePos = p->GetPos() - m_Other->GetPos();

	// Calculate gamma
	double gamma = 0.5 * sqrt(4.0 * m_SpringConstant - m_Damping * m_Damping);
	if (gamma == 0.0) {
		return;
	}
	
	// Calculate c
	Vec3<double> c = relativePos * (m_Damping / (2.0 * gamma)) + p->GetVel() * (1.0 / gamma);

	// Calculate target position
	Vec3<double> targetPos = relativePos * cos(gamma * dt) + c * sin(gamma * dt);
	targetPos *= exp(-0.5 * dt * m_Damping);

	// Calculate the resulting acceleration and therefore the force
	Vec3<double> acc = (targetPos - relativePos) * (1.0 / dt * dt) - p->GetVel() * dt;
	p->AddForce(acc * p->GetMass());
	p->Integrate(dt);
}