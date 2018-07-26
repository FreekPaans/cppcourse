class Vector
{
public:

	Vector()
	:Vector(0,0)
	{
	}

	Vector(int x, int y)
	:m_x(x),
	 m_y(y)
	{
	}

	bool operator==(const Vector& rhs) const
	{
		return m_x == rhs.m_x &&
			   m_y == rhs.m_y;
	}

	int GetX() const
	{
		return m_x;
	}

	int GetY() const
	{
		return m_y;
	}

	Vector& Add(const Vector& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return *this;
	}


private:
	int m_x;
	int m_y;
};
