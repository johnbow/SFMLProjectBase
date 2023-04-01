#pragma once

#include "SFML/Graphics.hpp"

#include <memory>

template<class T>
constexpr inline T clamp_value(const T value, const T lower, const T upper)
{
	return std::min(std::max(value, lower), upper);
}

template<class T>
constexpr inline T clamp_value(const T value, const sf::Vector2<T> bounds)
{
	return clamp_value(value, bounds.x, bounds.y);
}

template<class T>
constexpr inline sf::Vector2<T> clamp(const sf::Vector2<T> vec, const sf::Vector2<T> xBounds, const sf::Vector2<T> yBounds)
{
	return {
		clamp_value(vec.x, xBounds),
		clamp_value(vec.y, yBounds)
	};
}

template<class T>
constexpr inline sf::Vector2<T> clamp(const sf::Vector2<T> vec, const sf::Rect<T> bounds)
{
	return {
		clamp_value(vec.x, bounds.left, bounds.left + bounds.width), 
		clamp_value(vec.y, bounds.top, bounds.top + bounds.height)
	};
}

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	Entity();
	Entity(const sf::Vector2f pos);
	virtual ~Entity() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(const sf::Time dt) = 0;

	void load(sf::Texture * const tex);	// call to initialize sprites!

	std::size_t getAnimationFrame() const;
	void setAnimationFrame(std::size_t animationFrame);

	sf::FloatRect getCollisionBox() const;
	void setRelativeCollisionBox(sf::FloatRect rect);
	bool checkCollision(const Entity& other) const;

	void addSprite();
	void addSprite(const sf::IntRect& subRect);

	const sf::Sprite& getSprite(std::size_t animationFrame) const;
	const sf::Sprite& getSprite() const;
	const sf::Texture* getTexture() const;

	sf::FloatRect getBounds() const;
	std::size_t framesCount();

private:
	std::size_t animationFrame;
	std::vector<std::unique_ptr<sf::Sprite>> sprites;
	sf::FloatRect collisionBox;	// relative position of collision box
	sf::Texture* texture = nullptr;

	void applyTransformations(sf::Transformable& toTransform) const;
	void applyTransformations(sf::Transformable& toTransform);
	virtual void loadSprites();		// override to customize sprite loading, called by load()
};
