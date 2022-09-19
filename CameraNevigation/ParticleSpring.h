#ifndef __PARTICLE_SPRING_H__
#define __PARTICLE_SPRING_H__

#pragma once
#include "ParticleForceGenerator.h"

class ParticleSpring : public ParticleForceGenerator
{
public:
	Particle	*m_Other;
	double		m_SpringConstant;
	double		m_RestLength;
public:
	ParticleSpring();
	ParticleSpring(Particle *other, double k, double restLength);
	~ParticleSpring();
public:
	virtual void UpdateForce(Particle *p, double dt);
};

class ParticleStiffSpring : public ParticleForceGenerator
{
public:
	Particle	*m_Other;
	double		m_SpringConstant;
	double		m_Damping;
public:
	ParticleStiffSpring();
	ParticleStiffSpring(Particle *other, double k, double damping);
	~ParticleStiffSpring();
public:
	virtual void UpdateForce(Particle *p, double dt);
};

#endif