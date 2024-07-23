#include <print>

class Vector3f {
   public:
    Vector3f()
    {
        m_x = 0.0f;
        m_y = 0.0f;
        m_z = 0.0f;
    }

    Vector3f(float x, float y, float z) : m_x{x}, m_y{y}, m_z{z} {};

    Vector3f operator+(const Vector3f& rhs)
    {
        Vector3f result;
        result.m_x += rhs.m_x;
        result.m_y += rhs.m_y;
        result.m_z += rhs.m_z;

        return result;
    }

    void operator+=(const Vector3f& rhs)
    {
        this->m_x += rhs.m_x;
        this->m_y += rhs.m_y;
        this->m_z += rhs.m_z;
    }

    float getX() { return this->m_x; }

    float getY() { return this->m_y; }

    float getZ() { return this->m_z; }

   private:
    float m_x, m_y, m_z;
};
int main()
{
    Vector3f myVector;

    Vector3f myVector2{1, 2, 3};

    Vector3f myVector3{2.3, 5.4, -4.5};

    Vector3f result = myVector + myVector2;
    result += myVector2;

    result += myVector3;

    std::println("x: {}, y: {}, z: {}", result.getX(), result.getY(), result.getZ());
}
