#pragma once
#ifndef __PARTICLE_FORCE_GENERATOR_H__
#define __PARTICLE_FORCE_GENERATOR_H__

#include "Particle.h"

class ParticleForceGenerator
{
public:

public:
	ParticleForceGenerator();
	~ParticleForceGenerator();
public:
	virtual void UpdateForce(Particle *p, double dt) = 0;
};

#endif