#include "player.hpp"

Player::Player(cpSpace *space)
{
    width = 40;
    height = 40;
    mass = 1.0f;
    position.x = 200;
    position.y = 200;
    /*
    Moment bezwładności to wielkość fizyczna, która opisuje, jak trudno jest obrócić obiekt wokół pewnej osi.
    W przypadku gier 2D, takich jak te, które mogą być budowane przy użyciu biblioteki Chipmunk2D,
    moment bezwładności określa, jak obiekt będzie się zachowywał podczas obrotu pod wpływem siły, np. przy kolizjach.
    */
    cpFloat moment = cpMomentForBox(mass, width, height);

    // Tworzenie ciała gracza
    body = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    cpBodySetPosition(body, cpv(position.x, position.y));

    // Tworzenie kształtu gracza i tarcia
    shape = cpSpaceAddShape(space, cpBoxShapeNew(body, width, height, 0));
    cpShapeSetFriction(shape, 0.7f); // tarcie obiektu z podłożem
}

void Player::HandleInput()
{
    cpVect velocity = cpBodyGetVelocity(body);
    float speed = 100.0f;

    if (IsKeyDown(KEY_LEFT))
    {
        cpBodySetVelocity(body, cpv(-speed, velocity.y));
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        cpBodySetVelocity(body, cpv(speed, velocity.y));
    }
}

void Player::UpdatePhysics(float deltaTime)
{
    cpSpaceStep(cpBodyGetSpace(body), deltaTime);
}

void Player::DrawPlayer()
{
    cpVect pos = cpBodyGetPosition(body);
    DrawRectangle(pos.x - width / 2, pos.y - height / 2, width, height, GREEN);
}

cpBody *Player::GetBody() const
{
    return body;
}