#pragma once

class Entity
{
	friend class AbstractBehavior;
public:
	Entity(int n);
	~Entity();
	void Show();
	int GetX() const
	{
		return x;
	}
private:
	int x;
	AbstractBehavior* m_behavior;
};

class AbstractBehavior
{
public:
	virtual void Show(Entity& e) = 0;
	virtual ~AbstractBehavior() = default;
protected:
	void SetBehavior(Entity& e, AbstractBehavior* p_newBehavior);
};

class BehaviorA : public AbstractBehavior
{
public:
	BehaviorA()
	{
		std::cout << "Behavior A activated.\n";
	}
	void Show(Entity& e) override;
	virtual ~BehaviorA()
	{
		std::cout << "Behavior A destructed.\n";
	}
};

class BehaviorB : public AbstractBehavior
{
public:
	BehaviorB()
	{
		std::cout << "Behavior B activated.\n";
	}
	void Show(Entity& e) override;
	virtual ~BehaviorB()
	{
		std::cout << "Behavior B destructed.\n";
	}
};


Entity::Entity(int n)
	:
	x(n)
{
	m_behavior = new BehaviorA;
}
Entity::~Entity()
{
	delete m_behavior;
	m_behavior = nullptr;
}
void Entity::Show()
{
	m_behavior->Show(*this);
}

void AbstractBehavior::SetBehavior(Entity& e, AbstractBehavior* p_newBehavior)
{
	delete e.m_behavior;
	e.m_behavior = p_newBehavior;
}


void BehaviorA::Show(Entity& e)
{
	std::cout << "Behavior A: " << e.GetX() + 10 << std::endl;
	SetBehavior(e, new BehaviorB);
}

void BehaviorB::Show(Entity& e)
{
	std::cout << "Behavior B: " << e.GetX() + 20 << std::endl;
	SetBehavior(e, new BehaviorA);
}



