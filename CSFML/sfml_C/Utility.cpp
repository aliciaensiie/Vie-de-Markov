#include "../include/Utility.h"

extern "C"
{

FloatRect getFloatRect(float left, float top, float width, float height)
{
    FloatRect r = {left, top, width, height};
    return r;
}

Vector2f getVect2f(float x, float y)
{
    Vector2f v = {x, y};
    return v;
}

float length(Vector2f v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

Vector2f times(float scalar, Vector2f v)
{    
    Vector2f ret_v = {v.x * scalar, v.y * scalar};
    return ret_v;
}

void timesAndModify(float scalar, Vector2f* v)
{
    v->x *= scalar;
    v->y *= scalar;
}

Vector2f add(Vector2f a, Vector2f b)
{
    Vector2f ret_v = {a.x + b.x, a.y + b.y};
    return ret_v;
}

void addAndModify(Vector2f* a, Vector2f b)
{
    a->x += b.x;
    a->y += b.y;
}

Vector2f sub(Vector2f a, Vector2f b)
{
    Vector2f ret_v = {a.x - b.x, a.y - b.y};
    return ret_v;
}

void subAndModify(Vector2f* a, Vector2f b)
{
    a->x -= b.x;
    a->y -= b.y;
}

}