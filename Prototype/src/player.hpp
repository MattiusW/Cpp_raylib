#pragma once
#include <raylib.h>
#include <chipmunk/chipmunk.h>

class Player
{
public:
    Player(cpSpace *space);
    void UpdatePhysics(float deltaTime);
    void DrawPlayer();
    void HandleInput();
    cpBody *GetBody() const;

private:
    cpBody *body;
    cpShape *shape;
    Vector2 position;
    int width, height;
    float mass;
};