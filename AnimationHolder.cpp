#include "AnimationHolder.h"
#include <SFML/Graphics/RenderTarget.hpp>


Animation::Animation(sf::Texture& texture, int x, int y, int width, int height, int count, float speed, int step)
 : speed(speed)
{
	sprite.setTexture(texture);

	for (int i = 0; i < count; ++i)
	{
		frames.push_back(sf::IntRect(x + i*step, y, width, height));
		frames_flip.push_back(sf::IntRect(x + i*step + width, y, -width, height));
	}
}

void Animation::Tick(float time)
{
	if (!bPlaying)
	{
		return;
	}

	currentFrame += speed * time;
	if (currentFrame > frames.size())
	{
		currentFrame -= frames.size();
		if (!bLoop)
		{
			bPlaying = false;
			return;
		}
	}
	
	const int iFrame = static_cast<int>(currentFrame);
	if (bFlip)
	{
		sprite.setTextureRect(frames_flip[iFrame]);
	}
	else
	{
		sprite.setTextureRect(frames[iFrame]);
	}
	
}

////////////////////////////////////////////////////////////////////

void AnimationHolder::Create(const std::string& name, sf::Texture& texture, int x, int y, int width, int height, int count,
                             float speed, int step)
{
	animations.emplace(name, Animation(texture, x, y, width, height, count, speed, step));
	currentAnimationName = name;
}


void AnimationHolder::Draw(sf::RenderTarget& renderTarget, int x, int y)
{
	animations[currentAnimationName].GetSprite().setPosition(x, y);
	renderTarget.draw(animations[currentAnimationName].GetSprite());
}
