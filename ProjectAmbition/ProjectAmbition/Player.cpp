#include "Player.h"
#include <string>
#include "InteractableObject.h"

//Base constrution of the player
Player::Player() :
	Creature("Images/Player.png", sf::Vector2f(0.2f, 0.2f), sf::Vector2f(0, 0), false)
{
	m_CollisionData.Collision = false;
	m_CollisionData.CurCollisionSide = CollisionSide::NONE;
	m_CollisionData.Object = nullptr;
}

Player::~Player() {}

//This function managnes collision for the player, it will recieve the collided object
void Player::Collision(Object* a_CollisionObject)
{

	//Sets the values of the collision data struct
	m_CollisionData.Object = a_CollisionObject;
	m_CollisionData.Collision = true;

	BlockCollision();
}

void Player::Collision(sf::Sprite* m_CollisionObject)
{

}

//This function checks if the collision will block the player
void Player::BlockCollision() {
	//The length between the player and the current collision
	float length = 0;

	//Scale of the current sprite
	float scale = 0.2f;

	//Calculation of player position and collision object position
	sf::Vector2f pos = m_Sprite.getPosition();
	sf::Vector2f cPos = m_CollisionData.Object->GetSprite().getPosition();

	//////Get the direction of the collision object
	if (pos.x < cPos.x) {
		m_CollisionData.CurCollisionSide = CollisionSide::LEFT;
		length = -(pos.x - cPos.x);
	}
	if (pos.x > cPos.x && length < (pos.x - cPos.x)) {
		m_CollisionData.CurCollisionSide = CollisionSide::RIGHT;
		length = pos.x - cPos.x;
	}
	if (pos.y < cPos.y && length < -(pos.y - cPos.y)) {
		m_CollisionData.CurCollisionSide = CollisionSide::TOP;
		length = pos.y - cPos.y;
	}
	if (pos.y > cPos.y && length < (pos.y - cPos.y)) {
		m_CollisionData.CurCollisionSide = CollisionSide::BOTTOM;
		length = pos.y - cPos.y;
	}
}

//This function manages the input of the player, this will recieve the current event
void Player::Input(sf::Event a_Event)
{
	//Debug component
	std::string values[5] = { "TOP","RIGHT","BOTTOM","LEFT", "NONE" };
	std::cout << values[(int)m_CollisionData.CurCollisionSide] << std::endl;

	//Movement input
	if (a_Event.key.code == sf::Keyboard::A && m_CollisionData.CurCollisionSide != CollisionSide::RIGHT) { m_Sprite.move(-10, 0); }
	if (a_Event.key.code == sf::Keyboard::D && m_CollisionData.CurCollisionSide != CollisionSide::LEFT) { m_Sprite.move(10, 0); }
	if (a_Event.key.code == sf::Keyboard::W && m_CollisionData.CurCollisionSide != CollisionSide::BOTTOM) { m_Sprite.move(0, -10); }
	if (a_Event.key.code == sf::Keyboard::S && m_CollisionData.CurCollisionSide != CollisionSide::TOP) { m_Sprite.move(0, 10); }

	//interaction input
	if (a_Event.key.code == sf::Keyboard::E) {
		if (m_CollisionData.Object != nullptr && m_CollisionData.Object->IsInteractable())
			((InteractableObject*)m_CollisionData.Object)->Interact(this);
		else
			std::cout << "No interactable object found" << std::endl;
	}

	ResetCollision();
}

//This fucntion will manage the rotation of the player
void Player::Rotate(sf::RenderWindow* a_RenderWindow)
{
	//Get position of player and of the curser
	sf::Vector2f curPos = m_Sprite.getPosition();
	//Get the curser position in view
	sf::Vector2f worldPos = a_RenderWindow->mapPixelToCoords(sf::Mouse::getPosition(*a_RenderWindow));

	//PI
	const float PI = 3.14159265f;

	//Calculate Rotation direction
	float dx = curPos.x - worldPos.x;
	float dy = curPos.y - worldPos.y;

	float rotation = (atan2(dy, dx)) * 180 / PI;
	rotation += 90;

	//Set rotation of the player
	m_Sprite.setRotation(rotation);
}

void Player::ResetCollision()
{
	//Reset all the collision data
	m_CollisionData.Reset();
}
