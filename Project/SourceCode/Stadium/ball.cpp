#include "ball.h"
#include <iostream>

using namespace std;

Ball::Ball(double x, double y, double z)
{
	init(x,y,z);
}

Ball::Ball(sf::Vector3f pos)
{
	init(pos.x,pos.y,pos.z);
}

Ball::~Ball()
{
	deallocate();
}

void Ball::reset(double x, double y, double z)
{
	deallocate();
	init(x,y,z);
}

void Ball::init(double x, double y, double z)
{
	collisionShape = new btSphereShape(1);

	motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(x, y, z)));
	
	btScalar mass = 0.430f;
    btVector3 fallInertia(0, 0, 0);
    collisionShape->calculateLocalInertia(mass, fallInertia);

	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, motionState, collisionShape, fallInertia);

	rigidBody = new btRigidBody(fallRigidBodyCI); // LOCATED IN CLASS

	rigidBody->setRestitution(0.79); // to bounce
	//rigidBody->setFriction(2.0); // 
	rigidBody->setHitFraction(1.5); // to slow down when it hits
	rigidBody->setRollingFriction(12.0); // to slow down when it is rolling
	//rigidBody->setDamping(0,0); // to slow down in the air
};

void Ball::deallocate()
{
	delete collisionShape;
	delete motionState;
	delete rigidBody;
}

void Ball::setPosition3(double x, double y, double z)
{
	rigidBody->setWorldTransform(btTransform(btQuaternion(0, 0, 0, 1), btVector3(x, y, z)));
}

btVector3 Ball::getPosition3()
{
	btTransform trans;
	trans = rigidBody->getWorldTransform();
	return trans.getOrigin();
}

sf::Vector2f Ball::getPosition2()
{
	btVector3 position = getPosition3();
	return sf::Vector2f(position.getX(),position.getZ());
};

sf::Vector3f Ball::getLinearVelocity()
{
	btVector3 toreturn = rigidBody->getLinearVelocity();
	return sf::Vector3f(toreturn.x(),toreturn.y(),toreturn.z());
};

void Ball::setLinearVelocity(sf::Vector3f newVelocity)
{
	rigidBody->setLinearVelocity(btVector3(newVelocity.x,newVelocity.y,newVelocity.z));
};

sf::Vector3f Ball::getAngularVelocity()
{
	btVector3 toreturn = rigidBody->getAngularVelocity();
	return sf::Vector3f(toreturn.x(),toreturn.y(),toreturn.z());
};

void Ball::setAngularVelocity(sf::Vector3f newVelocity)
{
	rigidBody->setAngularVelocity(btVector3(newVelocity.x,newVelocity.y,newVelocity.z));
};

void Ball::applyImpulse(sf::Vector3f impulse, sf::Vector3f position)
{
	rigidBody->applyImpulse(btVector3(impulse.x,impulse.y,impulse.z),btVector3(position.x,position.y,position.z));
};

float Ball::getMagnitude_2DLinearVelocity()
{
	sf::Vector3f vel = getLinearVelocity();
	return sqrt( pow(vel.x,2)+pow(vel.z,2) );
};