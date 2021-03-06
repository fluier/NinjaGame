#pragma once

#include "Capsule.h"
#include <Adina/InputManager.h>
#include <Adina/SpriteBatch.h>
#include <Adina/TileSheet.h>

enum class PlayerMoveState { STANDING, RUNNING, PUNCHING, IN_AIR };

class Player {
public:
	void init(b2World* world,
		const glm::vec2& position,
		const glm::vec2& drawDims,
		glm::vec2& collisionDims,
		Adina::ColorRGBA8 color);

	void draw(Adina::SpriteBatch& spriteBatch);
	void drawDebug(Adina::DebugRenderer& debugRenderer);

	void update(Adina::InputManager& inputManager);

	const Capsule& getCapsule() const { return m_capsule; }

	glm::vec2 getPosition() const {
		glm::vec2 rv;
		rv.x = m_capsule.getBody()->GetPosition().x;
		rv.y = m_capsule.getBody()->GetPosition().y;
		return rv;
	}

private:
	glm::vec2 m_drawDims;
	Adina::ColorRGBA8 m_color;
	Adina::TileSheet m_texture;
	Capsule m_capsule;
	PlayerMoveState m_moveState = PlayerMoveState::STANDING;
	float m_animTime = 0.0f;
	int m_direction = 1; // 1 or -1
	bool m_onGround = false;
	bool m_isPunching = false;
};