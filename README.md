# Spring

- Hook's law gives us the mathematics of springs

- Hook discovered that the force exerted by a spring depends only on the distance the spring is extended or compressed from its rest position

  - The formula is therefore : 𝒇=−𝒌Δ𝒍=−𝒌𝒍−𝒍𝟎

    - Δ𝒍: distance the spring is extended or compressed

    - 𝒌: spring constant (stiffness of the spring)

    - 𝒍𝟎: rest length  no forces acting to extend or compress the spring

- When it comes to 3D, we need to generate a force vector rather than a scalar:
![image](https://user-images.githubusercontent.com/78521423/191071083-a3be639e-269d-4c10-bb84-059d33b98851.png)


  - 𝒅: vector from the end of the spring attached to the object we re generating a
force, to the other end of the spring : 𝒅=𝒙𝑨−𝒙𝑩

## A basic spring generator

The basic spring generator simply calculates the length of the spring using equation, and then uses Hook s law to calculate toe force
