#ifndef BALL_H

#define BALL_H

#include <SFML/Graphics.hpp>

#include <btBulletDynamicsCommon.h>

class Ball
{
	btCollisionShape* collisionShape;
	
	
public:
	btDefaultMotionState* motionState;

	Ball(double x, double y, double z);
	Ball(sf::Vector3f);
	~Ball();

	btRigidBody* rigidBody;
	void init(double,double,double);
	void deallocate();
	void reset(double,double,double);

	void setPosition3(double x, double y, double z);
	btVector3 getPosition3();
	sf::Vector2f getPosition2();

	sf::Vector3f getLinearVelocity();
	float getMagnitude_2DLinearVelocity();
	void setLinearVelocity(sf::Vector3f);

	sf::Vector3f getAngularVelocity();
	void setAngularVelocity(sf::Vector3f);

	void applyImpulse(sf::Vector3f,sf::Vector3f);
};

#endif