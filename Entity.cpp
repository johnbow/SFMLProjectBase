#include "Entity.h"

#include <iostream>

const sf::FloatRect INITIAL_COLLISION_BOX(0.f, 0.f, 0.f, 0.f);

Entity::Entity(const sf::Vector2f pos)
{
	animationFrame = 0;
	setPosition(pos);
	setRelativeCollisionBox(INITIAL_COLLISION_BOX);
}

Entity::Entity() : Entity(sf::Vector2f(0.f, 0.f)) {}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	applyTransformations(*sprites[animationFrame]);
	target.draw(*sprites[animationFrame], states);
}

void Entity::load(sf::Texture * const tex)
{
	texture = tex;
	loadSprites();
	if (collisionBox == INITIAL_COLLISION_BOX && !sprites.empty())
		setRelativeCollisionBox(getBounds());
}

std::size_t Entity::getAnimationFrame() const
{
	return animationFrame;
}

void Entity::setAnimationFrame(std::size_t animationFrame)
{
	this->animationFrame = animationFrame;
}

sf::FloatRect Entity::getCollisionBox() const
{	// returns absolute position of collision box
	return { collisionBox.left + getPosition().x, collisionBox.top + getPosition().y,
		collisionBox.width, collisionBox.height };
}

void Entity::setRelativeCollisionBox(sf::FloatRect box)
{
	this->collisionBox = box;
}

bool Entity::checkCollision(const Entity& other) const
{
	return getCollisionBox().intersects(other.getCollisionBox());
}

const sf::Sprite& Entity::getSprite(std::size_t animationFrame) const
{
	return *sprites[animationFrame];
}

const sf::Sprite& Entity::getSprite() const
{
	return getSprite(animationFrame);
}

const sf::Texture* Entity::getTexture() const
{
	return texture;
}

sf::FloatRect Entity::getBounds() const
{
	return getSprite().getGlobalBounds();
}

std::size_t Entity::framesCount()
{
	return sprites.size();
}

void Entity::addSprite()
{
	sprites.push_back(std::make_unique<sf::Sprite>(*texture));
}

void Entity::addSprite(const sf::IntRect& subRect)
{
	sprites.push_back(std::make_unique<sf::Sprite>(*texture, subRect));
}

void Entity::applyTransformations(sf::Transformable& toTransform) const
{
	toTransform.setPosition(getPosition());
	toTransform.setRotation(getRotation());
	toTransform.setScale(getScale());
	toTransform.setOrigin(getOrigin());
}

void Entity::applyTransformations(sf::Transformable& toTransform)
{
	toTransform.setPosition(getPosition());
	toTransform.setRotation(getRotation());
	toTransform.setScale(getScale());
	toTransform.setOrigin(getOrigin());
}

void Entity::loadSprites() { // default: constructs sprite from texture
	addSprite();
}
