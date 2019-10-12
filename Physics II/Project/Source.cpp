#include <Box2D/Box2D.h>

int main()
{
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);

	system("Pause");
	return 0;
}