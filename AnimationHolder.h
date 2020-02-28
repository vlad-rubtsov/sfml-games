#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace sf
{
	class RenderTarget;
}

class Animation
{
public:
	Animation() = default;

	Animation(sf::Texture& texture, int x, int y, int width, int height, int count, float speed, int step);

	sf::Sprite& GetSprite() { return sprite; }

	void Tick(float time);

	void SetFlip(bool flip) { bFlip = flip; }

	void Play() { bPlaying = true; }
	void Pause() { bPlaying = false; }

private:
	std::vector<sf::IntRect> frames;
	std::vector<sf::IntRect> frames_flip;

	sf::Sprite sprite;

	float currentFrame = 0.f;
	float speed = 0.f;

	bool bFlip = false;
	bool bPlaying = true;
	bool bLoop = true;
};


class AnimationHolder
{
public:
	void Create(const std::string& name, sf::Texture& texture, int x, int y, int width, int height, int count,
	            float speed, int step);

	void Draw(sf::RenderTarget& renderTarget, int x, int y);

	void Set(const std::string& name)
	{
		currentAnimationName = name;
	}

	void Flip(bool bFlip = true)
	{
		animations[currentAnimationName].SetFlip(bFlip);
	}

	void Tick(float time)
	{
		animations[currentAnimationName].Tick(time);
	}

	void Play()
	{
		animations[currentAnimationName].Play();
	}

	void Pause()
	{
		animations[currentAnimationName].Pause();
	}

private:
	std::string currentAnimationName;
	std::map<std::string, Animation> animations;
};

#endif